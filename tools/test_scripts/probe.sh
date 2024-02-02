#!/bin/bash

name=$(lspci -vvv | grep "Kernel modules" | tail -1 | awk '{ print $NF }')
echo "It is $name!"
# case $name in
#   sky2) file="drivers/net/ethernet/marvell/sky2"
#   ;;
#   skge) file="drivers/net/ethernet/marvell/skge"
#   ;;
#   3c59x) file="drivers/net/ethernet/3com/3c59x"
#   ;;
#   sis190) file="drivers/net/ethernet/sis/sis190"
#   ;;
#   de2104x) file="drivers/net/ethernet/dec/tulip/de2104x"
#   ;;
#   epic100) file="drivers/net/ethernet/smsc/epic100"
#   ;;
#   kvaser_pci) file="drivers/net/can/sja1000/kvaser_pci drivers/net/can/sja1000/sja1000"
#   ;;
#   r8169) file="drivers/net/ethernet/realtek/r8169_main"
#   ;;
#   fealnx) file="drivers/net/ethernet/fealnx"
#   ;;
#   sundance) file="drivers/net/ethernet/dlink/sundance"
#   ;;
#   pcnet32) file="drivers/net/ethernet/amd/pcnet32"
#   ;;
#   ksz884x) file="drivers/net/ethernet/micrel/ksz884x"
#   ;;
#   *) echo "Unsupported!";
#   exit
#   ;;
# esac

# ./rec_cov.sh $file &


while [ true ];
do
  rmmod $name
  sleep 2
  modprobe $name
  lspci -vvv | grep $name
done

