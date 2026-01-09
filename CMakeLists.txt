cmake_minimum_required(VERSION 3.20)
project(visual-engine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(HL_ROOT "${CMAKE_SOURCE_DIR}/ThirdParty/hashlink")
find_path(HL_INCLUDE_DIR NAMES hl.h PATHS "${HL_ROOT}/include" NO_DEFAULT_PATH)
find_library(HL_LIBRARY NAMES libhl PATHS "${HL_ROOT}/lib" NO_DEFAULT_PATH)
set(HL_DLL "${HL_ROOT}/bin/libhl.dll")

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/thirdparty/installed/x64-windows" ${CMAKE_PREFIX_PATH})

find_package(SDL3     CONFIG REQUIRED)
find_package(glad     CONFIG REQUIRED)
find_package(glm      CONFIG REQUIRED)
find_package(assimp   CONFIG REQUIRED)
find_package(imgui    CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED) 

file(GLOB_RECURSE SOURCES 
    "source/*.cxx" 
    "source/*.hxx"
    "source/*/.hxx"
    "source/*/.cxx" 
    "source/*/*.c"
    "source/*/*.h"
)

add_executable(${PROJECT_NAME} ${SOURCES} "thirdparty/hashlink/include/hl.h" "thirdparty/hashlink/include/hlc.h" "thirdparty/hashlink/include/hlc_main.c" "source/core/cvar.c" "source/core/cvar.h")

target_link_libraries(${PROJECT_NAME} 
    PRIVATE
        SDL3::SDL3
        glad::glad
        glm::glm
        assimp::assimp
        imgui::imgui
        imguizmo::imguizmo
        ${HL_LIBRARY}
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    source
    ${HL_INCLUDE_DIR}
    "${CMAKE_SOURCE_DIR}/ThirdParty/installed/x64-windows/include"
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${HL_DLL}"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
)