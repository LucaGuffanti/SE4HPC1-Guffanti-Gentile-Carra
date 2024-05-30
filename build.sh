#!/bin/bash

mkdir -p build && cd build
cmake ..
cmake --build .
./test_algebraic
./test_structural
./test_iterated 2>out && sort out | uniq