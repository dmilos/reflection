#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../src member.cpp               -o  member
g++ -fexceptions -std=c++11 -g -I../../../src free.cpp               -o  free 