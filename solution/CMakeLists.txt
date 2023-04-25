cmake_minimum_required(VERSION 3.8)

project(oi)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRC_LIST "*")

set(Folder_Black_List CMakeFiles/
    .idea/
    .git/
    .vs/
    .vscode/
    build/
    cmake-build-debug/
    out/)

add_definitions(-DLOCAL_TEST)
add_definitions(-DLOCAL)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

foreach (Src ${SRC_LIST})
    set(Skip FALSE)

    foreach(Item ${Folder_Black_List})
        if (${Src} MATCHES ${Item})
            set(Skip True)
            break()
        endif ()
    endforeach()

    if(Skip)
        continue()
    endif()
    
	string(REGEX REPLACE ".+/(.+)/.+\\..*" "\\1" Folder ${Src})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" Name ${Src})

    
    string(REGEX REPLACE ".+\\.(.+)" "\\1" Extension ${Src})    

	set(Executable_Name "${Folder}-${Name}")

    if((("${Extension}" STREQUAL "cpp") OR ("${Extension}" STREQUAL "c")))
        # CXX
        message(${Executable_Name} \t\t ${Src})
        add_executable(${Executable_Name} ${Src})
        target_link_libraries(${Executable_Name}) 
    endif()
endforeach ()