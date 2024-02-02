#!/bin/bash

while [ true ]; do
  taskset -c 0 ./build/send
  #sleep 1
done

