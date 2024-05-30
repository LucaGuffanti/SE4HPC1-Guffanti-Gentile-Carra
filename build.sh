#!/bin/bash

mkdir -p build && cd build
cmake ..
cmake --build .
./test_algebraic
./test_structural
./test_combinatorial 2>&1 | grep -i "error" | sort | uniq -d