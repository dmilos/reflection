#!/bin/bash

pwd

./assign.exe
./factory.exe

cd ./cpp
./run.sh
cd ..

cd ./ini
./run.sh
cd ..

cd ./json
./run.sh
cd ..

cd ./lua
./run.sh
cd ..

cd ./python
./run.sh
cd ..

cd ./xml
./run.sh
cd ..

cd ./yaml
./run.sh
cd ..