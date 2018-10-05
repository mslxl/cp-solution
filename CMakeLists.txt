cmake_minimum_required(VERSION 3.8)
project(oi)

set(CMAKE_CXX_STANDARD 98)

file(GLOB_RECURSE SRC_LIST "*.cpp")

foreach (Src ${SRC_LIST})
    if ((${Src} MATCHES "CMakeFiles/") OR (${Src} MATCHES ".idea/"))
        continue()
    endif ()

    string(FIND ${Src} "/" SlashPos REVERSE)
    math(EXPR NamePos ${SlashPos}+1)
    string(SUBSTRING ${Src} ${NamePos} -1 SrcName)

    string(SUBSTRING ${Src} 0 ${SlashPos} Path)
    string(FIND ${Path} "/" PathSlashPos REVERSE)
    math(EXPR LastPathPos ${PathSlashPos}+1)
    string(SUBSTRING ${Path} ${LastPathPos} -1 Folder)

    string(FIND ${SrcName} "." DotPos REVERSE)
    string(SUBSTRING ${SrcName} 0 ${DotPos} Name)

    set(Executable_Name "${Folder}-${Name}")
    add_executable(${Executable_Name} ${Src})
    message(${Executable_Name} \t\t ${Src})
endforeach ()