@rem !/bin/msdos
@
@echo %cd%
@

@cd ./base
@call ./make.bat
@cd ..
@
@cd ./exposed
@call ./make.bat
@cd ..
@
@cd ./friend
@call ./make.bat
@cd ..
@
@cd ./function
@call ./make.bat
@cd ..
@
@cd ./idspec
@call ./make.bat
@cd ..
@
@cd ./operation
@call ./make.bat
@cd ..
@
@cd ./store
@call ./make.bat
@cd ..
@
@cd ./trinity
@call ./make.bat
@cd ..
@
@cd ./typedef
@call ./make.bat
@cd ..
@