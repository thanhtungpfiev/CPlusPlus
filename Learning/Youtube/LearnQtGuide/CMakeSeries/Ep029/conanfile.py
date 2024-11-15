from conan import ConanFile
from conan.tools.cmake import CMakeToolchain
from conan.tools.microsoft import VCVars


class RoosterRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("catch2/3.4.0")
        self.requires("fmt/10.1.1")
        self.requires("sfml/2.6.1")

    def generate(self):
        ms = VCVars(self)
        ms.generate()
