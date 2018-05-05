#!/bin/bash
name=$(echo $1 | cut -f 1 -d '.')
g++ -std=c++17 -O0 -g $name.cpp -o build/$name &&
./build/$name