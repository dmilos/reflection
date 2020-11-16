@rem !/bin/msdos
@
@rem  Make all examples.
@rem  No Scons, no CMake, no Make or any other make tool
@rem  One line one example
@rem  Designed for easy copy/paste
@
@rem  TODO MATH_USE_PP2FILE
@
@
@cls
@rem pushd .
@call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat"
@rem popd
@
@echo %cd%
@
@cl /EHsc /I../src  readme.cpp
@cl /EHsc /I../src  workbench.cpp
@
@cd ./less-than-1k
@call ./make.bat
@cd ..
@
@cd ./less-than-2k
@call ./make.bat
@cd ..
@
@cd ./less-than-3k
@call ./make.bat
@cd ..
@
@cd ./less-than-4k
@call ./make.bat
@cd ..
@
@cd ./less-than-Nk
@call ./make.bat
@cd ..
@

pause