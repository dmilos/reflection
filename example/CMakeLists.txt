cmake_minimum_required(VERSION 3.0)

project( ReflectionPrj )

include_directories( "../src" )

add_subdirectory( less-than-1k )
add_subdirectory( less-than-2k )
add_subdirectory( less-than-3k )
add_subdirectory( less-than-4k )
add_subdirectory( less-than-Nk )

add_executable(  Reflection__WbSmall wb-small.cpp )
add_executable(  Reflection__Workbench workbench.cpp )
add_executable(  Reflection__WbBig wb-big.cpp )
add_executable(  Reflection__Readme readme.cpp )