#!/bin/bash

# wait 10s before we collect coverage info
sleep 10

HOME="/home/yiluwu/firecracker"

SYSFS_DIR="/sys/kernel/debug/gcov/"

# modify here to collect coverage info for other drivers
FILE="${HOME}/linux/drivers/net/ethernet/dlink/sundance"

pushd ${HOME}/linux
cat  $SYSFS_DIR/${FILE}.gcda > ${FILE}.gcda
llvm-cov-11 gcov ${FILE}.c  | tee  /mnt/report.txt
cp *.gcov /mnt/
sync
touch /mnt/done
sync
popd
