#!/bin/bash

mkdir -p build && cd build && rm -r *
cmake ..
cmake --build .
./test_algebraic
./test_structural
./test_combinatorial 2>&1 | grep -i "error" | sort | uniq
./test_monkey 2>&1 | egrep -i "error*|*seed: [0-9]*" | sort | uniq