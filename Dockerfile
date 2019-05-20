FROM quay.io/jlospinoso/cppbuild:v1.8.0

RUN mkdir /ccc
COPY / /ccc/
RUN mkdir /ccc/build
WORKDIR /ccc/build
RUN CXX=g++-8 CC=gcc-8 cmake ..
RUN make -j4
