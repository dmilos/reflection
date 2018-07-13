# Make all examples.
# No Scons, no CMake, no Make or any other make tool
# One line one example
# Designed for easy copy/paste

# TODO REFLECTION_USE_PP2FILE

g++ -fexceptions -std=c++11 -g -I../src readme.cpp               -o  readme

cd ./less-than-1k
./make.sh
cd ..

cd ./less-than-2k
./make.sh
cd ..

cd ./less-than-3k
./make.sh
cd ..

cd ./less-than-4k
./make.sh
cd .. 

cd ./less-than-Nk
./make.sh
cd .. 