@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc /I../../../src  common.cpp
@cl /EHsc /I../../../src  field.cpp
@cl /EHsc /I../../../src  member.cpp
@cl /EHsc /I../../../src  pointer.cpp
@cl /EHsc /I../../../src  simple.cpp