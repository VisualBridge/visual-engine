cmake_minimum_required(VERSION 3.20)
project(visual-engine CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HL_ROOT "${CMAKE_SOURCE_DIR}/thirdparty/hashlink")
find_path(HL_INCLUDE_DIR NAMES hl.h PATHS "${HL_ROOT}/include" NO_DEFAULT_PATH)
find_library(HL_LIBRARY NAMES libhl PATHS "${HL_ROOT}/lib" NO_DEFAULT_PATH)
set(HL_DLL "${HL_ROOT}/bin/libhl.dll")

set(SDL_ROOT "${CMAKE_SOURCE_DIR}/thirdparty/SDL3")
find_path(SDL_INCLUDE_DIR NAMES SDL3/SDL.h PATHS "${SDL_ROOT}/include" NO_DEFAULT_PATH)
find_library(SDL_LIBRARY NAMES SDL3 PATHS "${SDL_ROOT}/lib/x64" NO_DEFAULT_PATH)
set(SDL_DLL "${SDL_ROOT}/lib/x64/SDL3.dll")

set(SDL_IMAGE_ROOT "${CMAKE_SOURCE_DIR}/thirdparty/SDL3_image")
find_path(SDL_IMAGE_INCLUDE_DIR NAMES SDL3_image/SDL_image.h PATHS "${SDL_IMAGE_ROOT}/include" NO_DEFAULT_PATH)
find_library(SDL_IMAGE_LIBRARY NAMES SDL3_image PATHS "${SDL_IMAGE_ROOT}/lib/x64" NO_DEFAULT_PATH)
set(SDL_IMAGE_DLL "${SDL_IMAGE_ROOT}/lib/x64/SDL3_image.dll")

set(SDL_TTF_ROOT "${CMAKE_SOURCE_DIR}/thirdparty/SDL3_ttf")
find_path(SDL_TTF_INCLUDE_DIR NAMES SDL3_ttf/SDL_ttf.h PATHS "${SDL_TTF_ROOT}/include" NO_DEFAULT_PATH)
find_library(SDL_TTF_LIBRARY NAMES SDL3_ttf PATHS "${SDL_TTF_ROOT}/lib/x64" NO_DEFAULT_PATH)
set(SDL_TTF_DLL "${SDL_TTF_ROOT}/lib/x64/SDL3_ttf.dll")

set(IMGUI_ROOT "${CMAKE_SOURCE_DIR}/thirdparty/imgui")

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/thirdparty/installed/x64-windows" ${CMAKE_PREFIX_PATH})

find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED) 

file(GLOB_RECURSE SOURCES 
    "source/*.cxx" 
    "source/*.hxx"
    "source/*/*.hxx"
    "source/*/*.cxx" 
    "source/*/*.c"
    "source/*/*.h"
    "${IMGUI_ROOT}/*.cpp"
    "${IMGUI_ROOT}/backends/imgui_impl_sdl3.cpp"
    "${IMGUI_ROOT}/backends/imgui_impl_opengl3.cpp"
)

add_executable(${PROJECT_NAME} 
    ${SOURCES} 
    "thirdparty/hashlink/include/hl.h" 
    "thirdparty/hashlink/include/hlc.h" 
    "thirdparty/hashlink/include/hlc_main.c" 
    "source/core/cvar.cxx"
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE
        glad::glad
        glm::glm
        assimp::assimp
        imguizmo::imguizmo
        ${HL_LIBRARY}
        ${SDL_LIBRARY}
        ${SDL_IMAGE_LIBRARY}
        ${SDL_TTF_LIBRARY}
)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE 
    source
    ${IMGUI_ROOT}
    "${IMGUI_ROOT}/backends"
    ${HL_INCLUDE_DIR}
    ${SDL_INCLUDE_DIR}
    ${SDL_IMAGE_INCLUDE_DIR}
    ${SDL_TTF_INCLUDE_DIR}
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${HL_DLL}" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL_DLL}" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL_IMAGE_DLL}" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL_TTF_DLL}" "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
)