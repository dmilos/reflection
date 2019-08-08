#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../src member.cpp               -o  member
g++ -fexceptions -std=c++11 -g -I../../../src simple.cpp               -o  simple
g++ -fexceptions -std=c++11 -g -I../../../src field.cpp                -o  field
g++ -fexceptions -std=c++11 -g -I../../../src common.cpp               -o  common
g++ -fexceptions -std=c++11 -g -I../../../src pointer.cpp              -o  pointer 
