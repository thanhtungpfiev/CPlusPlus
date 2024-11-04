import argparse
import os
import subprocess
from file_util import remove_file, remove_directory, make_directory

current_file_path = os.path.abspath(__file__)
current_directory_path = os.path.dirname(current_file_path)
root_directory_path = os.path.abspath(os.path.join(current_directory_path, ".."))

def run_command(command):
    try:
        result = subprocess.run(command, check=True, capture_output=False, text=True)
        print(f"{' '.join(command)} ran successfully.")
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(f"{' '.join(command)} ran failed.")
        print(e.stderr)

def clean_out_build_directory():
    remove_directory(g_out_build_directory_path)
    remove_file("CMakeUserPresets.json")

def make_report_directory():
    make_directory(g_report_directory_path)
    if g_coverage:
        make_directory(g_html_directory_path)

def configure():
    conan_command = [
        "conan",
        "profile",
        "detect",
        "--force"
    ]
    run_command(conan_command)
    
    if g_run_environment == "windows_msvs_2022":
        conan_command = [
            "conan",
            "install",
            ".",
            f"--output-folder={g_out_build_directory_path}",
            "--build=missing",
            "--settings=build_type=Debug"
        ]
        run_command(conan_command)
    
        cmake_command = [
            "cmake",
            "--preset",
            "conan-default"
        ]
    elif g_run_environment == "windows_gcc":
        conan_command = [
            "conan",
            "install",
            ".",
            f"--output-folder={g_out_build_directory_path}",
            "--build=missing",
            "--settings=build_type=Debug",
            "--settings=compiler=gcc",
            "--settings=compiler.version=13",
            "--settings=compiler.libcxx=libstdc++11"
        ]
        run_command(conan_command)
        
        cmake_command = [
            "cmake",
            "--preset",
            "conan-debug"
        ]
    elif g_run_environment == "linux_gcc":
        conan_command = [
            "conan",
            "install",
            ".",
            f"--output-folder={g_out_build_directory_path}",
            "--build=missing",
            "--settings=build_type=Debug"
        ]
        run_command(conan_command)
    
        cmake_command = [
            "cmake",
            "--preset",
            "conan-debug"
        ]
    
    if g_coverage:
        cmake_command.extend([
            "-DCOVERAGE=1"
        ])

    run_command(cmake_command)

def build():
    cmake_command = [
        "cmake",
        "--build",
        g_out_build_directory_path
    ]

    run_command(cmake_command)

def run():
    if g_run_environment == "windows_msvs_2022":
        executable_file_path = os.path.join(g_out_build_directory_path, "tests", "Debug", "multiply_test.exe")
    elif g_run_environment == "windows_gcc":
        executable_file_path = os.path.join(g_out_build_directory_path, "tests", "multiply_test.exe")
    elif g_run_environment == "linux_gcc":
        executable_file_path = os.path.join(g_out_build_directory_path, "tests", "multiply_test")

    with open(g_test_report_file_path, "w") as log_file:
        try:
            subprocess.run([executable_file_path], check=True, stdout=log_file, stderr=log_file)
            print(f"Output has been written to {g_test_report_file_path}")
        except subprocess.CalledProcessError as e:
            print(f"An error occurred while running the executable. Check {g_test_report_file_path} for details.")
    
    if g_coverage:
        gcovr_comamand = [
            "gcovr",
            "-r",
            root_directory_path,
            "--filter",
            os.path.join(root_directory_path, 'src', 'multiply').replace('\\', '/'),
            "--html-details",
            os.path.join(g_html_directory_path, 'coverage_report.html').replace('\\', '/')
        ]
        
        run_command(gcovr_comamand)


def gen_ut_report():
    # Set up argument parser
    parser = argparse.ArgumentParser(description="Process some arguments.")

    # Add arguments
    parser.add_argument("--run_environment", required=True, help="Environment to make test.")
    parser.add_argument("--coverage", required=False, action="store_true", help="Need coverage.")

    # Parse arguments
    args = parser.parse_args()

    # Use arguments
    global g_run_environment, g_coverage, g_out_directory_path, g_out_build_directory_path, g_report_directory_path, g_test_report_file_path
    g_run_environment = args.run_environment
    g_coverage = args.coverage
    g_out_directory_path = os.path.join(root_directory_path, "out")
    g_out_build_directory_path = os.path.join(g_out_directory_path, "build", g_run_environment)
    g_report_directory_path = os.path.join(g_out_build_directory_path, "report")
    g_test_report_file_path = os.path.join(g_report_directory_path, "test_report.txt")
    
    if g_coverage:
        global g_html_directory_path
        g_html_directory_path = os.path.join(g_report_directory_path, "coverage_report") 

    print(f"run_environment: {g_run_environment}")
    print(f"g_coverage: {g_coverage}")
    
    os.chdir(root_directory_path)

    clean_out_build_directory()

    make_report_directory()

    configure()

    build()

    run()


if __name__ == "__main__":
    gen_ut_report()