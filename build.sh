#!/bin/bash

if [ -d "./build" ]
then
    echo "Directoriy build exists. Clean it..."
    rm -r build
    mkdir build
    cd build
else
    echo "Does not exist"
    mkdir build
fi

cmake -G "NMake Makefiles" ..
nmake

./result