cmake_minimum_required(VERSION 3.22)

project(cpp_test)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 17)

add_compile_options(-g -Wall)
aux_source_directory(. alls)
add_executable(myexe ${alls})

