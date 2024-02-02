#!/bin/bash

ROOT=$(dirname $(dirname $(realpath $(dirname $0))))
DIR=$ROOT/s2e/projects
echo $DIR
pushd $DIR
./prepare.sh $1 $2 $3 $4 $5 $6
popd