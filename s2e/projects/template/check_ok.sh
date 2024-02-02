#!/bin/bash
DIR=$1
if [ -z $DIR ]
then
    DIR="."
fi
while [ $(find $DIR  -name "ok" | wc -l) -eq 0 ]
do
    sleep 3
done
echo "solved"
sleep 5
sudo kill -9 $(ps aux | grep qemu | awk '{print $2}')


