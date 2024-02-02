#!/bin/bash

P=$(realpath $(dirname $0))
echo $P
R=$(dirname $P)
echo $R
ls $(dirname $R)

for arg; do
    echo $arg
done