FROM quay.io/jlospinoso/cppbuild

RUN mkdir /ccc
COPY / /ccc/
RUN mkdir /ccc/build
WORKDIR /ccc/build
RUN CXX=g++-8 cmake ..
RUN make
