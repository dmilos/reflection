@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc /I../../../src  cpp.cpp
@cl /EHsc /I../../../src  json.cpp
@cl /EHsc /I../../../src  protobuf.cpp
@cl /EHsc /I../../../src  xml.cpp
@cl /EHsc /I../../../src  yaml.cpp