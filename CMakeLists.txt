cmake_minimum_required(VERSION 3.8)
project(oi)

set(CMAKE_CXX_STANDARD 98)

file(GLOB_RECURSE SRC_LIST "*.cpp")

foreach (Src ${SRC_LIST})

    if ((${Src} MATCHES "CMakeFiles/") OR (${Src} MATCHES ".idea/"))
        continue()
    endif ()

	STRING(REGEX REPLACE ".+/(.+)/.+\\..*" "\\1" Folder ${Src})
    STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" Name ${Src})

    set(Executable_Name "${Folder}-${Name}")
    add_executable(${Executable_Name} ${Src})
	target_link_libraries(${Executable_Name})
    message(${Executable_Name} \t\t ${Src})
endforeach ()