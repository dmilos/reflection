@rem !/bin/msdos
@
@echo %cd%
@

@cd ./big
@call ./make.bat
@cd ..
@
@cd ./direct
@call ./make.bat
@cd ..
@
@cd ./enum
@call ./make.bat
@cd ..
@
@cd ./exposed
@call ./make.bat
@cd ..
@
@cd ./function
@call ./make.bat
@cd ..
@
@cd ./guarded
@call ./make.bat
@cd ..
@
@cd ./inspect
@call ./make.bat
@cd ..
@
@cd ./mutate
@call ./make.bat
@cd ..
@
@cd ./reset
@call ./make.bat
@cd ..
@
@cd ./trinity
@call ./make.bat
@cd ..
@
@cd ./variable
@call ./make.bat
@cd ..
@
