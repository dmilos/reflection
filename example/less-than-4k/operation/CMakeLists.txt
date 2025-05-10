#cmake_minimum_required(VERSION 2.8)

add_subdirectory( cpp   )
add_subdirectory( ini   )
add_subdirectory( java   )
add_subdirectory( json   )
add_subdirectory( lua   )
add_subdirectory( protobuf   )
#add_subdirectory( python   )
add_subdirectory( xml   )
add_subdirectory( yaml   )

add_executable(   Reflection__LessT4K__operation__factory              factory.cpp )
add_executable(   Reflection__LessT4K__operation__assign              assign.cpp )
