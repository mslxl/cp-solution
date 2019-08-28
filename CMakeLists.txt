cmake_minimum_required(VERSION 3.8)

project(oi)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRC_LIST "*")

option(COMPILE_CXX "compile cpp and c file" ON)
option(COMPILE_HS "compile haskell code with ghc" ON)
option(COMPILE_TS "compile typescript code with tsc" ON)
option(COMPILE_JAVA "compile java code with javac" ON)

set(Folder_Black_List CMakeFiles/
    .idea/
    .git/
    .vs/
    .vscode/
    build/
    cmake-build-debug/
    out/)

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

    
    if(COMPILE_CXX AND (("${Extension}" STREQUAL "cpp") OR ("${Extension}" STREQUAL "c")))
        # CXX
        message(CXX: \t ${Executable_Name} \t\t ${Src})
        add_executable(${Executable_Name} ${Src})
        target_link_libraries(${Executable_Name}) 
    elseif(COMPILE_HS AND ("${Extension}" STREQUAL "hs"))
        # HASKELL
		set(Target_Name ${Executable_Name}-hs)
        message(HASKELL: \t ${Target_Name} \t\t ${Src})
        add_custom_target(
            ${Target_Name}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${Src} ${PROJECT_BINARY_DIR}/${Executable_Name}.hs
            COMMAND ghc ${PROJECT_BINARY_DIR}/${Executable_Name}.hs
            COMMENT "Building ${Src}")
    elseif(COMPILE_TS AND ("${Extension}" STREQUAL "ts"))
        set(Target_Name ${Executable_Name}-ts)
        message(TYPESCRIPT: \t ${Target_Name} \t\t ${Src})
        add_custom_target(
            ${Target_Name}
            COMMAND tsc ${Src} -out ${PROJECT_BINARY_DIR}/${Executable_Name}.js
        )
    elseif(COMPILE_JAVA AND ("${Extension}" STREQUAL "java"))
        set(Target_Name ${Executable_Name}-ts)
        message(JAVA: \t ${Target_Name} \t\t ${Src})
        add_custom_target(
            ${Target_Name}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${Src} ${PROJECT_BINARY_DIR}/${Executable_Name}.java
            COMMAND javac ${PROJECT_BINARY_DIR}/${Executable_Name}.java
            COMMENT "Building ${Src}")
    endif()
endforeach ()