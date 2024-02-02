#!/bin/bash
ROOT=$(dirname $(dirname $(realpath $(dirname $0))))
pushd $ROOT/linux
make -j`nproc`
make -j`nproc` modules
make -j`nproc` INSTALL_MOD_PATH=output modules_install

sudo mkdir -p /mnt/chroot
sudo mount $ROOT/images/stretch.img /mnt/chroot
#sudo mount /home/tong/qemu-afl-image/stretch.img /mnt/chroot

pushd output/lib/modules/

for dirs in `ls`;do
	echo ${dirs}
	depmod -b ../../ ${dirs}
	mkdir -p /mnt/chroot/lib/modules/${dirs}
	sudo rsync -rvp ./${dirs}/ \
	/mnt/chroot/lib/modules/${dirs}/
done
popd

sudo umount /mnt/chroot

cp arch/x86_64/boot/bzImage $ROOT/images/bzImage-master

popd