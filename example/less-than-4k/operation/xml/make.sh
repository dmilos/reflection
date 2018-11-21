#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../../src print.cpp               -o  print
g++ -fexceptions -std=c++11 -g -I../../../../src serialize.cpp               -o  serialize
