#!/bin/bash

pwd


g++ -fexceptions -std=c++11 -g -I../../src parser.cpp             -o  parser
g++ -fexceptions -std=c++11 -g -I../../src misc.cpp               -o  misc
g++ -fexceptions -std=c++11 -g -I../../src observe.cpp            -o  observe
