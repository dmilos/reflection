#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../src assign.cpp               -o  assign

cd ./cpp
./make.sh
cd .. 

cd ./ini
./make.sh
cd .. 

cd ./json
./make.sh
cd .. 

cd ./lua
./make.sh
cd .. 

cd ./python
./make.sh
cd .. 

cd ./xml
./make.sh
cd .. 