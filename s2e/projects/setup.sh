#!/bin/bash

ENV_DIR=$(dirname $(dirname $(dirname $(realpath $0))))
PROJ_DIR=$ENV_DIR/s2e/projects

if [ -d $PROJ_DIR/a ]; then
    echo "Base project a exists, removing..."
    rm -rf $PROJ_DIR/a
fi

cp -r $PROJ_DIR/template $PROJ_DIR/a

# echo $ENV_DIR
# echo $PROJ_DIR

# setup symbolic link
ln -sf $ENV_DIR/s2e/install/bin/guest-tools32 $PROJ_DIR/a/guest-tools32  
ln -sf $ENV_DIR/s2e/install/bin/guest-tools64 $PROJ_DIR/a/guest-tools64
ln -sf $ENV_DIR/s2e/images/debian-11.0.0-x86_64/guestfs $PROJ_DIR/a/guestfs

# set ENV_DIR 
sed -i "s\<ENV_DIR>\\${ENV_DIR}\g" $PROJ_DIR/a/*.lua
sed -i "s\<ENV_DIR>\\${ENV_DIR}\g" $PROJ_DIR/a/*.sh
sed -i "s\<ENV_DIR>\\${ENV_DIR}\g" $PROJ_DIR/a/*.json