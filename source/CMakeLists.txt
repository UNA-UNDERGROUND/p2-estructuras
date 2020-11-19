cmake_minimum_required(VERSION 3.10)
project(foro VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

set(src_include
    include/lexer.hpp
    include/parser.hpp
    include/arbol.hpp
)

set(src
    src/source.cpp
    src/lexer.cpp
    src/parser.cpp
    ${src_include}
)


add_executable(source ${src} src/source.cpp)
target_include_directories(source PRIVATE include)
