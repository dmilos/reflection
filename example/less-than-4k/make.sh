#!/bin/bash

pwd

cd ./base
./make.sh
cd ..

cd ./friend
./make.sh
cd ..

cd ./exposed
./make.sh
cd ..

cd ./function
./make.sh
cd ..

cd ./idspec
./make.sh
cd ..

cd ./operation
./make.sh
cd ..

cd ./store
./make.sh
cd ..


cd ./trinity
./make.sh
cd ..

cd ./typedef
./make.sh
cd ..