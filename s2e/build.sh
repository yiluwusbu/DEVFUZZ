#!/bin/bash

S2E_DIR=$(dirname $(realpath $0))
SOURCE_DIR=$S2E_DIR/source
S2E_PREFIX=$S2E_DIR/install

mkdir -p $S2E_PREFIX
mkdir -p $S2E_DIR/build

S2E_PREFIX=$S2E_PREFIX make -C $S2E_DIR/build -f $SOURCE_DIR/scripts/Makefile install
