#!/bin/bash
name=$(echo $1 | cut -f 1 -d '.')
g++ -std=c++17 $name.cpp -o build/$name
./build/$name