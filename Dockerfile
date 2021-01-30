FROM ubuntu:bionic

ARG GITHUB_TOKEN

RUN apt-get update
RUN apt-get -y install git
RUN apt-get -y install build-essential
RUN apt-get -y install cmake
RUN apt-get -y install gcc

RUN git clone https://github.com/nasa/cFS.git && \
    cd cFS && \
    git submodule init && \
    git submodule update

COPY . cFS/apps/sample_app/

RUN cd cFS && \
    cp cfe/cmake/Makefile.sample Makefile && \
    cp -r cfe/cmake/sample_defs sample_defs && \
    make SIMULATION=native prep && \
    make && \
    make install

CMD /bin/bash
