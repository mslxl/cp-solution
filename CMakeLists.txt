cmake_minimum_required(VERSION 3.8)
project(oi)

set(CMAKE_CXX_STANDARD 98)

file(GLOB_RECURSE SRC_LIST "*.cpp")

foreach (SRC ${SRC_LIST})
    # How to write the numerical operation in CMake...
    # CMake 中数值运算怎么写...
    if (${SRC} MATCHES ".*CMake.*")
        continue()
    endif ()

    string(FIND ${SRC} "/" POS REVERSE)
    string(SUBSTRING ${SRC} ${POS}+1 -1 NAME_WITH)
    string(SUBSTRING ${NAME_WITH} 1 -1 NAME_WITH)
    string(FIND ${NAME_WITH} "." POS REVERSE)
    string(SUBSTRING ${NAME_WITH} 0 ${POS} NAME)

    add_executable(${NAME} ${SRC})
    message(${NAME} \t\t ${SRC})
endforeach ()