#!/bin/bash

pushd $1
export LLVM_COMPILER=clang
export LLVM_CC_NAME=clang-13
export LLVM_COMPILER_PATH=/usr/bin
make CC=wllvm -j`nproc`  
popd