#!/bin/sh

cd ${TRAVIS_BUILD_DIR}/build
cmake -DCMAKE_PREFIX_PATH=/usr/local/opt/qt/lib/cmake ..
make -j4
