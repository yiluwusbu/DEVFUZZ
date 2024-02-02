all: qemu afl afl-proxy s2e

qemu:
	echo "Building QEMU..." && ./build_qemu_afl.sh

afl:
	make -C ./AFL

afl-proxy:
	make -C afl-proxy

s2e:
	cd s2e && ./build.sh && cd ..

.PHONY: qemu afl afl-proxy s2e

# /usr/bin/make --file=/home/yiluwu/firecracker/s2e/source/guest-images/Makefile --directory=/home/yiluwu/firecracker/s2e/images -j 2 -r --warn-undefined-variables debian-11.3-x86_64