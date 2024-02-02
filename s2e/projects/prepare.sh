#!/bin/bash

name=$1
VID=$2
PID=$3
SUBVID=$4
SUBPID=$5
# 0x12341234
CLASS=${6}

if [ "$name" == "" ]; then
  echo "need a name"
  exit
fi

if [ -f "$name" ]; then
  echo "$name already exists!"
  exit
fi

cp -rv a $name

pushd $name
sed -i s/KONAME/$name/g a.sh
sed -i s/KONAME/$name/g s2e-config.lua
sed -i s/SFPVID/${VID}/g s2e-config.lua
sed -i s/SFPPID/${PID}/g s2e-config.lua
sed -i s/SFPSUBVID/${SUBVID}/g s2e-config.lua
sed -i s/SFPSUBPID/${SUBPID}/g s2e-config.lua
sed -i s/SFPCLASS/${CLASS}/g s2e-config.lua
popd
echo "Remember to edit s2e-config.lua and update VID,PID"



