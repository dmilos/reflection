@rem !/bin/msdos
@
@rem  Make all examples.
@rem  No Scons, no CMake, no Make or any other make tool
@rem  One line one example
@rem  Designed for easy copy/paste
@
@rem  TODO REFLECTION_USE_PP2FILE
@
@
@cls
@rem pushd .
@call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"
@rem popd
@
@echo %cd%
@
@cl /EHsc /I../src  readme.cpp
@
@cd ./check
@call ./make.bat
@cd ..
@

pause