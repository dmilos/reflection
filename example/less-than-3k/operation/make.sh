#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../src cpp.cpp           -o  cpp     
g++ -fexceptions -std=c++11 -g -I../../../src json.cpp          -o  json    
g++ -fexceptions -std=c++11 -g -I../../../src protobuf.cpp      -o  protobuf
g++ -fexceptions -std=c++11 -g -I../../../src xml.cpp           -o  xml    
g++ -fexceptions -std=c++11 -g -I../../../src yaml.cpp          -o  yaml  