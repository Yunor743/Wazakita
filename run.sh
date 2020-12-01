#!/bin/bash

mkdir -p cmake-build-debug &&
cd cmake-build-debug &&
cmake .. -G "Unix Makefiles" &&
cmake --build . -- -j$(nproc);

