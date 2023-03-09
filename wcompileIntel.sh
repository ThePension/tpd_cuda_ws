#!/bin/bash
#
# Mandatory : use this script from the root of your workspace
#

set -u

# clean
cd ./BUILDER
cbicc intel cleanAll
cd -

# compile all
readonly WORKSPACE_PATH=$(pwd)
readonly PATH_SCRIPT=./BUILDER/makefile/private/script/workspace_auto

pushd . >/dev/null
cd $PATH_SCRIPT
./workspace_compile.sh $WORKSPACE_PATH intellinux
popd >/dev/null

# check
ls ./RELEASE/bin
sleep 9999999s

