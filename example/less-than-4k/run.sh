#!/bin/bash

pwd

cd ./base
./run.sh
cd ..

cd ./exposed
./run.sh
cd ..

cd ./friend
./run.sh
cd ..

cd ./function
./run.sh
cd ..

cd ./idspec
./run.sh
cd ..

cd ./operation
./run.sh
cd ..

cd ./store
./run.sh
cd ..


cd ./trinity
./run.sh
cd ..

cd ./typedef
./run.sh
cd ..