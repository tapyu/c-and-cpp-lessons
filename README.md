**What is a build automation tool?**

A [build automation tool][2] is a software tool or system designed to automate the process of converting a software code into executable programs or libraries. The primary purpose of a build automation tool is to streamline and simplify the often complex and error-prone process of building software, especially in larger projects with multiple source files and dependencies.

**What are the main taks done by an automation tool?**

- *Compilation*: Build automation tools manage the compilation of source code files into object code or executable files. They ensure that all necessary files are compiled in the correct order and with the appropriate compiler options.
- *Dependency Management*: These tools track dependencies between source code files and libraries. When a file changes, the tool can automatically rebuild only the affected components and their dependencies, reducing build times.
- *Configuration Management*: Build automation tools allow developers to specify build configurations and options in a consistent and maintainable manner. This includes setting compiler flags, linking libraries, and defining environment variables.
- *Testing*: Some build automation tools integrate with testing frameworks, making it easier to run unit tests, integration tests, and other forms of automated testing as part of the build process.
- *Packaging and Distribution*: These tools can package the compiled software into distributable formats, such as executable binaries, installer packages, or container images, making it easier to distribute the software to end-users.
- *Version Control Integration*: Build automation tools often integrate with version control systems (e.g., Git, SVN) to trigger builds automatically when code changes are committed, ensuring that the latest code is always in a build-ready state.
- *Reproducibility*: They promote reproducibility by capturing the exact build process and dependencies, reducing the "it works on my machine" problem.

**What are the most common `C`/`C++` build automation tools**?

- `Makefile`: `Makefile` is one of the oldest and most widely used build automation tools in the `C`/`C++` community. It uses makefiles to define how to build a project, specifying dependencies between files and build rules. While it's powerful, makefiles can become complex and hard to maintain for larger projects.
- `CMake`: `CMake` is a popular cross-platform build system generator. `CMake` is one of the most commonly used build automation tools for `C`/`C++` development. It has gained significant popularity in the `C`/`C++` community due to its versatility and cross-platform support. It generates build files (e.g., Makefiles, Visual Studio project files) based on a high-level `CMakeLists.txt` configuration. `CMake` is known for its flexibility and is commonly used for large, multi-platform projects. `CMake` has a large and active user community, which means there are extensive resources, documentation, and third-party modules available to streamline the build process and manage dependencies.
- `Autotools` (`Autoconf`, `Automake`, `Libtool`): `Autotools` is a suite of tools often used in Unix-based systems for configuring, building, and packaging software. `Autoconf` is used to generate configure scripts, `Automake` is used to create `Makefiles`, and `Libtool` is used to handle shared libraries on various platforms. This toolchain is particularly prevalent in open-source projects. However, `Autotools` has [several drawbacks][1] and is considered a [very archaic][4] tool.
- `Ninja`: While not a standalone build tool, `Ninja` is frequently used in conjunction with other build systems like `CMake` to improve build performance. [`Ninja` is meant to replace `Make`][5], which is slow when performing incremental (or no-op) builds. `Ninja` build files are not meant to be written by hand. Instead, a "build generator" should be used to generate `Ninja` build files. `Gyp`, `CMake`, `Meson`, and gn are popular build management software tools which support creating build files for `Ninja`.
- `Meson`: `Meson` is a modern build system that aims to be simple to use while being highly efficient. It uses a domain-specific language (DSL) for configuration and is known for its speed and ease of use.
- `Bazel`: `Bazel` is a powerful build system developed by Google. It is designed for large, complex projects and supports multiple programming languages, including `C`/`C++`. `Bazel` focuses on reproducibility and performance, making it suitable for large-scale development efforts.

---

# `Autotools`

[Autotools][2] is part of the GNU toolchain and is widely used in many free software and open source packages. Its component tools are free software, licensed under the GNU General Public License with special license exceptions permitting its use with proprietary software.

Autotools consists of the GNU utility programs `autoconf`, `automake`, and `libtool`. Other related tools frequently used alongside it include GNU's make program, GNU `gettext`, `pkg-config`, and `gcc`, the GNU Compiler Collection, also called GCC.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/84/Autoconf-automake-process.svg/1024px-Autoconf-automake-process.svg.png" alt="GNU autotools">
</p>

Legend:
- Dotted arrows: Influences;
- Bold arrows: Generates;
- Ellipses: CLI tools;
- Rectangles: files;

1. The `configure.ac` (or its older counterpart, `configure.in`) file and `Makefile.am` typically come along with the source code of software projects that use the Autotools for building and configuring the software.
1. Run `aclocal` to generate `aclocal.m4`.
1. Run `autoconf` to generate the `configure` executable file.
1. Run `./configure`. If it fails, you can run `autoreconf --install`.
1. Run `autoheader` to generate `config.h.in`.
1. Run `automake` to generate `Makefile.in`.
1. Run `./config.status`.
1. Run `make` or `make install`.



---

# `CMake`

TODO:

https://www.youtube.com/watch?v=kekw7eGb8Mw&t=75s&ab_channel=sudocpp
https://softwareengineering.stackexchange.com/a/278792/435466

[1]: https://stackoverflow.com/a/18291580/13998346
[2]: https://en.wikipedia.org/wiki/GNU_Autotools
[3]: https://en.wikipedia.org/wiki/Build_automation
[4]: https://gitlab.com/pdfgrep/pdfgrep/-/merge_requests/16#note_1542676068
[5]: https://en.wikipedia.org/wiki/Ninja_(build_system)
