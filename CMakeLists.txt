cmake_minimum_required(VERSION 3.26)
project(ObjectGL)

set(CMAKE_CXX_STANDARD 23)

add_compile_definitions(OBJECTGL_ON_OPENGL=460)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_library(ObjectGL
        src/window/window.cpp
        src/window/window.cpp
        src/buffer/frame_buffer.cpp
        src/texture/texture.cpp
        src/texture/image_texture.cpp
        src/device/monitor.cpp
        src/test.cpp)

include(FindPkgConfig)

find_package(GLFW REQUIRED)
include_directories(${GLFW_INCLUDE})
target_link_libraries(${PROJECT_NAME} ${GLFW_LIB})

find_package(glad REQUIRED)
include_directories(${GLAD_INCLUDE})
