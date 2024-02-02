#!/bin/bash

KMOD="KONAME"

function preparefw {
  FW=${1}
  FWDIR=${2}
  ./s2eget ${FW}
  sudo mkdir -p /lib/firmware/${FWDIR}
  sudo mv ${FW} /lib/firmware/${FWDIR}
}

function probe {
  echo -n 'file dd.c +p' | sudo tee /sys/kernel/debug/dynamic_debug/control
  echo 1 | sudo tee /sys/bus/pci/rescan
}

function collect_info {
  #sudo /home/s2e/s2eput /proc/iomem
  #sudo /home/s2e/s2eput /proc/ioports
  #cat /proc/interrupts > interrupts
  #sudo /home/s2e/s2eput interrupts
  #ls -l /proc/ > proc
  #sudo /home/s2e/s2eput proc
  sudo dmesg > /tmp/dmesg.init
  sudo /home/s2e/s2eput /tmp/dmesg.init
  #/home/s2e/s2eput lspci
  #find /dev > devs
  #/home/s2e/s2eput devs
}

function check_ko_match {
  lspci -vvv > lspci
  r=`grep "Kernel modules" lspci | grep ${KMOD}`
  if [ "$r" == "" ];then
      sudo /home/s2e/s2eput lspci
      /home/s2e/tellpex fail
      /home/s2e/s2ecmd kill 0 "configuration error, no device available"
  fi
}

function test_file {
  while true; do
    sudo dmesg > /tmp/dmesg
    sudo /home/s2e/s2eput /tmp/dmesg
    f=`sudo grep -i "$KMOD" /tmp/dmesg|grep "fail\|rejects"`
    if [ "$f" != "" ]; then
      echo "$f" > failed 
      sudo dmesg > /tmp/dmesg.e
      sudo /home/s2e/s2eput /tmp/dmesg.e
      /home/s2e/s2eput failed
      /home/s2e/tellpex fail
      /home/s2e/s2ecmd kill 0 "done"
      exit
    fi
    f=`sudo grep "bound device" /tmp/dmesg | grep bus`
    if [ "$f" != "" ]; then
      echo "$f" > ok
      sudo dmesg > /tmp/dmesg.e
      sudo /home/s2e/s2eput /tmp/dmesg.e
      /home/s2e/s2eput ok
      /home/s2e/tellpex ok
      return
    fi
    sleep 1
  done
}

function access_dev {
#  for (( c=0; c<10; c++ ))
#  do  
#    echo $c | sudo tee /dev/hpilo/d0ccb0
#  done
  for (( c=0; c<2; c++ ))
  do  
    cat /proc/interrupts > interrupts.${c}
    /home/s2e/s2eput interrupts.${c}
    sleep 1
  done
# write
    echo 1 | sudo tee /dev/hpilo/d0ccb0
# read
    cat /dev/hpilo/d0ccb0
}

function collect_info_after {
  sudo dmesg > /tmp/dmesg2
  sudo /home/s2e/s2eput /tmp/dmesg2
}

#preparefw
# trigger probe
probe
# collect information
collect_info
# is the device available?
test_file
# run fuzzing by reading/writing/ioctl the device
#access_dev
#collect_info_after

/home/s2e/s2ecmd kill 0 "gee.. the script is finished"

