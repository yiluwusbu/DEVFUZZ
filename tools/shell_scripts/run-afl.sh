#!/bin/bash
ROOT=$(dirname $(dirname $(realpath $(dirname $0))))
IN_DIR=$1
QEMU_CORE_ID=$2
SHM_ID=$3
AFL_BIND_ID=$4
echo core | sudo tee /proc/sys/kernel/core_pattern
pushd /sys/devices/system/cpu
echo performance | sudo tee cpu*/cpufreq/scaling_governor
popd

export AFL_SKIP_CPUFREQ=1
# ignore timeout and dryrun perform_dry_run

DIR=run-$SHM_ID
mkdir $DIR
cd $DIR
rm dry_run_stamp*
echo > afl.log
AFL_CORE_ID=$((AFL_BIND_ID+1))

#taskset -c $AFL_CORE_ID 
sudo $ROOT/AFL/afl-fuzz \
  -b $AFL_BIND_ID \
  -t 500000000+ -m 256 \
  -i $IN_DIR -o out \
  -d \
  -f seed \
  $ROOT/afl-proxy/proxy/build/ap @@ $QEMU_CORE_ID $SHM_ID

