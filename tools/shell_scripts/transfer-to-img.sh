#!/bin/bash

ROOT=$(dirname $(dirname $(realpath $(dirname $0))))
sudo mkdir -p /mnt/chroot
sudo mount $ROOT/images/stretch.img /mnt/chroot

for arg; do
    sudo cp -r $arg /mnt/chroot/root
done

sudo umount /mnt/chroot