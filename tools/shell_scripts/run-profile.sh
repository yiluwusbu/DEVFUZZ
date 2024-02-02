#!/bin/bash

ROOT=$(dirname $(dirname $(realpath $(dirname $0))))
SHMID=${1}
CONSOLE=${2}
DEV_NAME=${3}
TEST="profile"
export SFP_SHMID=${SHMID}
export TEST_PROBE=0

#0-disable, 1-r, 2-w, 3-rw
export AP_DUMP_RW=2
export AP_DISABLED=1
# export AP_DUMP_FILE="qemu-w.log"
export USE_DMA=0
export USE_IRQ=1000
export USE_STAGE2=0


export AFL_EPOCH=3
export WAITGDB=0
export EXPORT_DEVMEM=0
# sudo rm -f $AP_DUMP_FILE
#echo press ctrl-a x to quit
DIR=$ROOT/build-qemu-exp/x86_64-softmmu/
KERNEL="-kernel $ROOT/images/bzImage-master"

INITRD=""
#KERNEL="-kernel /boot/vmlinuz-5.11.0-34-generic"
#INITRD="-initrd /boot/initrd.img-5.11.0-34-generic"

ROFS="-snapshot"

ROOTFS="$ROOT/images/stretch.img,format=raw ${ROFS}"

#dd if=/dev/urandom of=./sfp-rom.rom bs=1M count=1

# KVM=-no-kvm
# KVM=-enable-kvm
ACCEL=kvm
# ACCEL=kvm
# LOG_LEVEL="-d exec -D /dev/null"

SFP=""
SFP="-device sfp,bus=pcie.1 "
#SFP="-usb -device usb-sfp"

NIC="-net none"

APPEND="nokaslr console=ttyS0 root=/dev/sda earlyprintk=serial biosdevname=0 net.ifnames=0 loglevel=8 security=none ro rootfstype=ext4 mitigations=off cryptomgr.notests clocksource=tsc audit=0 parport=0 kmemleak=on nosmp intel_iommu=on iommu=pt"

GDB=""
#GDB="-s"
GDBSTOP=""
#GDBSTOP="-S"

unset PCI_CLASS
unset SFP_USB_VID
unset SFP_USB_PID
export SFP_DEV_MODEL="$DEV_NAME"


function launch_console() {
#NIC="-net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10061-:22 -net nic,model=e1000"
SHARE_DIR=share-${DEV_NAME}-${TEST}
mkdir $SHARE_DIR
touch $SHARE_DIR/${DEV_NAME}.name
${DIR}qemu-system-x86_64 \
  -machine q35,accel=${ACCEL},kernel-irqchip=split \
  -device intel-iommu,intremap=on,caching-mode=on,device-iotlb=on \
  -fsdev local,id=test_dev,path=${SHARE_DIR},security_model=none \
  -device virtio-9p-pci,fsdev=test_dev,mount_tag=test_mount \
  -m 2G  -smp 1 \
  ${KVM} ${GDB} ${GDBSTOP} ${LOG_LEVEL} \
  -device ioh3420,id=pcie.1,chassis=1 \
  ${KERNEL} ${INITRD} -append "${APPEND}"\
  -drive file=${ROOTFS} \
  $NIC $SFP \
  -nographic \
  -pidfile vm-testing-${SHMID}.pid \
  2>&1 | tee vm-testing-${SHMID}.log
}

function no_console() {
    
SHARE_DIR=share-${DEV_NAME}-${TEST}
mkdir $SHARE_DIR
touch $SHARE_DIR/${DEV_NAME}.name
${DIR}qemu-system-x86_64 \
  -machine q35,accel=${ACCEL},kernel-irqchip=split \
  -device intel-iommu,intremap=on,caching-mode=on,device-iotlb=on \
  -fsdev local,id=test_dev,path=${SHARE_DIR},security_model=none \
  -device virtio-9p-pci,fsdev=test_dev,mount_tag=test_mount \
  -m 2G  -smp 1 \
  ${KVM} ${GDB} ${GDBSTOP} \
  -device ioh3420,id=pcie.1,chassis=1 \
  ${KERNEL} ${INITRD} -append "${APPEND}"\
  -drive file=${ROOTFS} \
  $NIC $SFP \
  -nographic \
  -pidfile vm-testing-${SHMID}.pid \
  -serial file:vm-testing-${SHMID}.log \
  2>&1 > /dev/null
}

if [ "${CONSOLE}" == "no_console" ]; then
  no_console
else
  launch_console
fi




