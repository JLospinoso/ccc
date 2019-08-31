[![C++ Crash Course](http://ccc.codes/cppcc.png "C++ Crash Course")](http://ccc.codes/)

# Get the Book

[C++ Crash Course is currently in Early Access.](https://nostarch.com/cppcrashcourse)

# Install Software

1. [Download, install, and configure Conan](https://conan.io)
2. [Download and install CMake](https://cmake.org/download/)
4. [Download and install Git](https://git-scm.com/downloads)

For example, on a fresh Ubuntu 19.10 installation, you can do the following:

```
sudo apt update && sudo apt upgrade -y
sudo apt install python3 python3-pip build-essential cmake git -y
sudo python3 -m pip install --upgrade conan conan-package-tools
conan profile new default --detect
conan profile update settings.compiler.libcxx=libstdc++11 default
```


# Build the Examples

[![Docker Repository on Quay](https://quay.io/repository/jlospinoso/ccc/status "Docker Repository on Quay")](https://quay.io/repository/jlospinoso/ccc)

First, clone this repository. Next, use Conan to install dependencies and perform an [out-of-source CMake build](https://gitlab.kitware.com/cmake/community/wikis/home).

```
git clone git@github.com:JLospinoso/ccc
mkdir ccc/build && cd ccc/build
conan install .. --build gtest --build bzip2 --build zlib --build boost
CXX=g++-9 CC=gcc-9 cmake .. && make
```

If all goes well, you should be able to run all the test-based listings as follows:
```
ctest --verbose
```

Refer to the [Conan IDE Integrations](https://docs.conan.io/en/latest/integrations/ides.html) for more information on using an IDE to follow along with these examples.
