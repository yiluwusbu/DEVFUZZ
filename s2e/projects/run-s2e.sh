#!/bin/bash

PROJ_DIR=$(dirname $(realpath $0))/$1

pushd $PROJ_DIR
sudo ./check_ok.sh &
sudo ./launch-s2e.sh
sudo kill -9 $(ps aux | grep check_ok.sh | awk '{print $2}')
sudo ./get_result.sh
popd
