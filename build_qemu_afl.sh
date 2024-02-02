#!/bin/bash
#build qemu into single bc file
ROOT=$(dirname $(realpath $0))
mkdir -p build-qemu-exp
pushd build-qemu-exp
\
  CFLAGS="-I$ROOT/afl-proxy/aplib/ -I$ROOT/afl-proxy/" \
  QEMU_LDFLAGS="$ROOT/afl-proxy/aplib/aplib.so" \
  ../qemu/configure --prefix=/opt/qemu --target-list=x86_64-softmmu --enable-virtfs
\
	CFLAGS="-I$ROOT/afl-proxy/aplib/ -I$ROOT/afl-proxy/" \
	QEMU_LDFLAGS="$ROOT/afl-proxy/aplib/aplib.so" \

make -j32
popd
