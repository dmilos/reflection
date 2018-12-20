#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g         -I../../../../src print.cpp               -o  print
#g++ -I/usr/include/python2.7  -lpython2.7 -ldl -I/usr/include/python2.7 -fno-strict-aliasing -ggdb -O2 -pipe -fdebug-prefix-map=/usr/src/ports/python2/python2-2.7.14-1.i686/build=/usr/src/debug/python2-2.7.14-1 -fdebug-prefix-map=/usr/src/ports/python2/python2-2.7.14-1.i686/src/Python-2.7.14=/usr/src/debug/python2-2.7.14-1 -DNDEBUG -g -fwrapv -O3 -Wall -std=c++11 -Wmisleading-indentation -shared -DPy_TRACE_DEFS -g -I../../../../src bind.cpp               -o  bind27
#g++ -fexceptions -std=c++11 -L/python3.5/libs -lpython2.7   -g -I../../../../src bind.cpp               -o  bind35


