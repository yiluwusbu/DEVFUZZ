#!/bin/bash

ip link set can0 type can bitrate 125000
sleep 1
ifconfig can0 up
sleep 1
candump can0 &
sleep 1
while [ true ]; do 
sleep 1
cansend can0 123#1122334455667788
done

