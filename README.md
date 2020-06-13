[![C++ Crash Course](http://ccc.codes/cppcc.png "C++ Crash Course")](http://ccc.codes/)

# Get the Book

[C++ Crash Course is currently available at No Starch Press.](https://nostarch.com/cppcrashcourse)

# Install Software

1. Follow the instructions in Chapter 1 for setting up a development environment.
2. [Download and install CMake](https://cmake.org/download/)
3. [Download and install Boost](https://www.boost.org/doc/libs/1_68_0/more/getting_started/index.html)
4. [Download and install Git](https://git-scm.com/downloads)

# Build the Examples

[![Docker Repository on Quay](https://quay.io/repository/jlospinoso/ccc/status "Docker Repository on Quay")](https://quay.io/repository/jlospinoso/ccc)

First, clone this repository:

```
git clone git@github.com:JLospinoso/ccc
```

Next, perform an [out-of-source CMake build](https://gitlab.kitware.com/cmake/community/wikis/home). For example:

```
cd ccc
git submodule init
git submodule update
mkdir build
cd build
cmake ..
cmake --build .
```

Your build directory should now contain requisite files for building on your current platform. On Windows, for example, you should find a `.sln` Visual Studio Solution file. On macOS/Linux, you should find a `make` file.
