@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc /I../../../src  assign.cpp
@cl /EHsc /I../../../src  factory.cpp
@cd ./cpp
@call ./make.bat
@cd ..
@
@cd ./ini
@call ./make.bat
@cd ..
@
@cd ./java
@call ./make.bat
@cd ..
@
@cd ./json
@call ./make.bat
@cd ..
@
@cd ./lua
@call ./make.bat
@cd ..
@
@cd ./protobuf
@call ./make.bat
@cd ..
@
@cd ./python
@call ./make.bat
@cd ..
@
@cd ./xml
@call ./make.bat
@cd ..
@
@cd ./yaml
@call ./make.bat
@cd ..
@

