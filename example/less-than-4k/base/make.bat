@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc /I../../../src  direct.cpp
@cl /EHsc /I../../../src  exposed.cpp
@cl /EHsc /I../../../src  guarded.cpp
@cl /EHsc /I../../../src  inspect.cpp
@cl /EHsc /I../../../src  mutate.cpp
@cl /EHsc /I../../../src  trinity.cpp
@cl /EHsc /I../../../src  variable.cpp