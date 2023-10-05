# `C`/`C++` test frameworks

There isn't a single "most used" testing framework for C/C++, as the choice of a testing framework often depends on various factors such as project requirements, team preferences, and specific needs. However, several testing frameworks are widely used and have gained popularity in the C/C++ community. Here are a few of them:

- `Google Test (gtest)`:
  - Developed by Google.
  - Provides a comprehensive set of features for writing unit tests.
  - Supports fixtures, test suites, parameterized tests, and more.
  - Integrates with Google Mock for creating mock objects.
- `Catch2`:
  - Header-only testing framework for C++.
  - Easy to use and configure.
  - Supports BDD-style testing and expressive syntax.
  - Doesn't require separate compilation of test cases.
- `Boost.Test`:
  - Part of the Boost C++ Libraries.
  - Provides a rich set of tools for writing test cases.
  - Supports test fixtures, logging, and reporting.
  - Integrates with the Boost build system.
- `doctest`:
  - Lightweight, single-header testing framework.
  - Easy to integrate into projects.
  - Supports assertions, fixtures, and subcases.
  - Designed to be fast and efficient.

TODO:

https://yurigeronimus.medium.com/guide-for-choosing-a-test-framework-for-your-c-project-2a7741b53317

https://www.reddit.com/r/cpp/comments/4e9afx/most_popular_c_unit_testing_frameworks/

## DejaGNU

DejaGnu is a framework for testing other programs. It provides a standardized interface for testing command-line programs, libraries, and other software components. DejaGnu is often associated with the GNU Project and is used extensively in the testing of GNU software. DejaGnu is primarily used for testing programs and software components written in the C and C++ programming languages. It was developed by the Free Software Foundation (FSF) and is closely associated with the GNU Project. As a result, many GNU software packages, which are often written in C and C++, use DejaGnu for their testing needs.

It's worth noting that it's not specifically designed for C/C++ applications. DejaGnu is a framework for testing other programs, specifically for testing the GNU toolchain (GCC, GDB, binutils, etc.) and other software that interacts closely with these tools. While DejaGnu itself is not a unit testing framework for C/C++ code, it plays a crucial role in the testing of toolchain components and ensuring their correctness across different platforms. If your primary goal is to test the functionality of your C/C++ code, you may want to consider one of the previously mentioned testing frameworks that are more tailored for unit testing in the C/C++ context.

However, if you're working on the development or maintenance of a compiler, debugger, or other GNU toolchain components, DejaGnu could be a valuable tool for writing tests to ensure the correct behavior of these tools.

Key features of DejaGnu include:

- `Scripting Language`: DejaGnu uses the Expect scripting language to automate the testing process. Expect is a scripting language designed for automating interactions with interactive command-line programs.
- `Standardized Interface`: DejaGnu provides a standardized interface for creating and running tests. It allows developers to write test scripts that check the behavior of their software in a systematic way.
- `Reusability`: Test scripts written with DejaGnu can be reused across different platforms and architectures. This makes it easier to maintain a consistent testing process across various environments.
- `Test Results Reporting`: DejaGnu can generate detailed reports of test results, making it easier for developers to identify issues and track the progress of testing efforts.
- `Test Suites`: DejaGnu supports the creation of test suites, which are collections of related tests. This is useful for organizing tests based on different aspects of the software's functionality.


### Expect programming language

Expect is not a general-purpose programming language; instead, it is a scripting language specifically designed for automating interactions with other programs. Expect is often used for automating tasks that involve command-line interfaces, text-based interactions, and scenarios where scripted input and responses are required.

As for complexity, the difficulty of learning Expect depends on your familiarity with TCL and your understanding of the specific interactions you want to automate. If you're comfortable with TCL and have a good understanding of how to interact with command-line programs, Expect can be relatively straightforward. However, like any tool, it may take some time to become proficient, especially if you're new to scripting or automation.

TCL, or Tool Command Language, is a scripting language that was designed with a focus on simplicity and ease of use. It is commonly used for various purposes, including scripting, embedded applications, and as a command language for applications. TCL is often pronounced as "tickle."

TCL is commonly used in applications that require scripting capabilities, such as graphical user interface (GUI) development, testing frameworks, and automation tools. One of its notable uses is as the scripting language for the Expect tool, which is used for automating interactions with other programs.
