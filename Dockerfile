FROM ubuntu:19.10
RUN apt update && apt upgrade -y
RUN apt install python3 python3-pip build-essential cmake -y
RUN python3 -m pip install --upgrade conan conan-package-tools

RUN mkdir /ccc
COPY / /ccc/
RUN mkdir /ccc/build
WORKDIR /ccc/build
RUN conan profile new default --detect
RUN conan profile update settings.compiler.libcxx=libstdc++11 default
RUN conan install .. --build gtest --build bzip2 --build zlib --build boost
RUN CXX=g++-9 CC=gcc-9 cmake ..
RUN make
RUN ctest
