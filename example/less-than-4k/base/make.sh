pwd

g++ -fexceptions -std=c++11 -g -I../../../src  direct.cpp       -o direct
g++ -fexceptions -std=c++11 -g -I../../../src  exposed.cpp      -o exposed
g++ -fexceptions -std=c++11 -g -I../../../src  guarded.cpp      -o guarded
g++ -fexceptions -std=c++11 -g -I../../../src  inspect.cpp      -o inspect
g++ -fexceptions -std=c++11 -g -I../../../src  mutate.cpp       -o mutate
g++ -fexceptions -std=c++11 -g -I../../../src  trinity.cpp      -o trinity
g++ -fexceptions -std=c++11 -g -I../../../src  variable.cpp     -o variable