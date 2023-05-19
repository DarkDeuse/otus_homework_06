cmake_minimum_required(VERSION 3.25)

project(containers)

add_executable(containers main.cpp
                          )

set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_include_directories(containers PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(containers, PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(containers PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()
add_executable(list list.cpp)
target_compile_features(list PUBLIC cxx_std_17)

target_include_directories(list PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(list PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(list PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(list PUBLIC cxx_std_17)
