@rem !/bin/msdos
@
@echo %cd%
@

@cl /EHsc /I../../src  parser.cpp
@cl /EHsc /I../../src  misc.cpp
@cl /EHsc /I../../src  observe.cpp
