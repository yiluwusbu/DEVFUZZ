FROM ubuntu:focal
ENV DEBIAN_FRONTEND noninteractive
# Install build dependencies
RUN dpkg --add-architecture i386 && apt-get update &&                       \
    apt-get -y install build-essential pip git cmake wget texinfo flex bison        \
    python-dev python3-dev python3-venv python3-distro mingw-w64 lsb-release \
    clang lsb-release wget software-properties-common gnupg ninja-build libcap-ng-dev \
    libattr1-dev libncurses5 libssl-dev bc tmux vim sudo debootstrap kmod rsync

# Install S2E dependencies
RUN apt-get update && apt-get -y install libdwarf-dev libelf-dev libelf-dev:i386 \
    libboost-dev zlib1g-dev libjemalloc-dev nasm pkg-config                 \
    libmemcached-dev libpq-dev libc6-dev-i386 binutils-dev                  \
    libboost-system-dev libboost-serialization-dev libboost-regex-dev       \
    libbsd-dev libpixman-1-dev                                              \
    libglib2.0-dev libglib2.0-dev:i386 python3-docutils libpng-dev gcc-multilib g++-multilib


RUN pip install wllvm && wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh && ./llvm.sh 13 all

COPY . DevFuzz/

