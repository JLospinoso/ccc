FROM quay.io/jlospinoso/cppbuild

RUN mkdir build
WORKDIR build
RUN cmake ..
RUN make
