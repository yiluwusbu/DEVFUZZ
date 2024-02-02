#!/bin/bash

set -eux

# Create a minimal Debian distribution in a directory.
DIR=chroot
RELEASE=stretch
SEEK=2047

sudo rm -rf $DIR
sudo mkdir -p $DIR
sudo chmod 0755 $DIR

# 1. debootstrap stage
sudo debootstrap --include=vim,net-tools,iproute2,wireless-tools,wget,curl,openssh-server,pciutils $RELEASE $DIR https://archive.debian.org/debian-archive/debian/

# Set some defaults and enable promtless ssh to the machine for root.
sudo sed -i '/^root/ { s/:x:/::/ }' $DIR/etc/passwd
echo '# T0:23:respawn:/sbin/getty -L ttyS0 115200 vt100' | sudo tee -a $DIR/etc/inittab
# Skip login phase
sudo sed -i "s/#NAutoVTs=6/NAutoVTs=1/g" $DIR/etc/systemd/logind.conf
sudo mkdir -p $DIR/etc/systemd/system/serial-getty@ttyS0.service.d
echo "[Service]" | sudo tee  $DIR/etc/systemd/system/serial-getty@ttyS0.service.d/override.conf
echo "ExecStart=" | sudo tee -a $DIR/etc/systemd/system/serial-getty@ttyS0.service.d/override.conf
echo "ExecStart=-/sbin/agetty --autologin root --noclear %I 38400 linux" | sudo tee -a $DIR/etc/systemd/system/serial-getty@ttyS0.service.d/override.conf

printf '\nauto eth0\niface eth0 inet dhcp\n' | sudo tee -a $DIR/etc/network/interfaces
echo '/dev/root / ext4 defaults 0 0' | sudo tee -a $DIR/etc/fstab
echo 'debugfs /sys/kernel/debug debugfs defaults 0 0' | sudo tee -a $DIR/etc/fstab
echo 'securityfs /sys/kernel/security securityfs defaults 0 0' | sudo tee -a $DIR/etc/fstab
echo 'configfs /sys/kernel/config/ configfs defaults 0 0' | sudo tee -a $DIR/etc/fstab
echo 'binfmt_misc /proc/sys/fs/binfmt_misc binfmt_misc defaults 0 0' | sudo tee -a $DIR/etc/fstab
echo -en "127.0.0.1\tlocalhost\n" | sudo tee $DIR/etc/hosts
echo "nameserver 8.8.8.8" | sudo tee -a $DIR/etc/resolve.conf
echo "devfuzz" | sudo tee $DIR/etc/hostname


# Build a disk image
dd if=/dev/zero of=$RELEASE.img bs=1M seek=$SEEK count=1
sudo mkfs.ext4 -F $RELEASE.img
sudo mkdir -p /mnt/$DIR
sudo mount -o loop $RELEASE.img /mnt/$DIR
sudo cp -a $DIR/. /mnt/$DIR/.
sudo cp ../tools/test_scripts/*.sh /mnt/$DIR/root/
sudo cp ../tools/test_scripts/bashrc /mnt/$DIR/root/.bashrc
sudo umount /mnt/$DIR
