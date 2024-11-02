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

def make_report_directory():
    make_directory(g_report_directory_path)

def configure():
    if g_run_environment == "windows_msvs_2022":
        cmake_command = [
            "cmake",
            "-DCMAKE_C_COMPILER=cl.exe",
            "-DCMAKE_CXX_COMPILER=cl.exe",
            f"-S{root_directory_path}",
            f"-B{g_out_build_directory_path}",
            "-G",
            "Visual Studio 17 2022",
            "-T",
            "host=x64",
            "-A",
            "x64"
        ]
    elif g_run_environment == "windows_gcc":
        cmake_command = [
            "cmake",
            "-DCMAKE_C_COMPILER=gccc.exe",
            "-DCMAKE_CXX_COMPILER=g++.exe",
            "-DCMAKE_BUILD_TYPE=Debug",
            f"-S{root_directory_path}",
            f"-B{g_out_build_directory_path}"
        ]
    elif g_run_environment == "linux_gcc":
        cmake_command = [
            "cmake",
            "-DCMAKE_C_COMPILER=/usr/bin/gcc",
            "-DCMAKE_CXX_COMPILER=/usr/bin/g++",
            "-DCMAKE_BUILD_TYPE=Debug",
            f"-S{root_directory_path}",
            f"-B{g_out_build_directory_path}"

        ]

    run_command(cmake_command)

def build():
    cmake_command = [
        "cmake",
        "--build",
        f"{g_out_build_directory_path}"
    ]

    run_command(cmake_command)

def run():
    if g_run_environment == "windows_msvs_2022":
        executable_file_path = os.path.join(g_out_build_directory_path, "Debug", "test_defaults.exe")
    elif g_run_environment == "windows_gcc":
        executable_file_path = os.path.join(g_out_build_directory_path, "Debug", "test_defaults.exe")
    elif g_run_environment == "linux_gcc":
        executable_file_path = os.path.join(g_out_build_directory_path, "test_defaults")

    with open(g_test_report_file_path, "w") as log_file:
        try:
            subprocess.run([executable_file_path], check=True, stdout=log_file, stderr=log_file)
            print(f"Output has been written to {g_test_report_file_path}")
        except subprocess.CalledProcessError as e:
            print(f"An error occurred while running the executable. Check {g_test_report_file_path} for details.")


def gen_ut_report():
    # Set up argument parser
    parser = argparse.ArgumentParser(description="Process some arguments.")

    # Add arguments
    parser.add_argument("--run_environment", required=True, help="Environment to make test.")

    # Parse arguments
    args = parser.parse_args()

    # Use arguments
    global g_run_environment, g_out_directory_path, g_out_build_directory_path, g_report_directory_path, g_test_report_file_path
    g_run_environment = args.run_environment
    g_out_directory_path = os.path.join(root_directory_path, "out")
    g_out_build_directory_path = os.path.join(g_out_directory_path, "build", g_run_environment)
    g_report_directory_path = os.path.join(g_out_build_directory_path, "report")
    g_test_report_file_path = os.path.join(g_report_directory_path, "test_report.txt")

    print(f"run_environment: {g_run_environment}")

    clean_out_build_directory()

    make_report_directory()

    configure()

    build()

    run()


if __name__ == "__main__":
    gen_ut_report()