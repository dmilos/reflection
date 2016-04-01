# Make all examples.
# No Scons, no CMake, no Make or any other make tool
# One line one example
# Designed for easy copy/paste

# TODO REFLECTION_USE_PP2FILE

g++ -fexceptions -std=c++11 -g -I../src hello.cpp               -o  hello

