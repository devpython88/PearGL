cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(PearGL VERSION 1.0.0 LANGUAGES CXX)

# Link libraries (Fixes raylib not being found)
link_directories(${CMAKE_SOURCE_DIR}/lib)

set(RAYLIB_HEADERS src/raylib.h src/raymath.h)
set(HEADERS src/peargl.hpp src/peargl_input.hpp src/peargl_audio.hpp)
set(IMPLEMENTATIONS src/peargl.cpp src/peargl_shapes.cpp src/peargl_textures.cpp src/peargl_input.cpp src/peargl_text.cpp)
set(AUDIO_IMPLEMENTATIONS src/peargl_audio.cpp)

add_executable(peargl src/main.cpp ${HEADERS} ${IMPLEMENTATIONS} ${RAYLIB_HEADERS} ${AUDIO_IMPLEMENTATIONS})
add_library(PearGL STATIC ${IMPLEMENTATIONS})
add_library(PearGL_Audio STATIC ${AUDIO_IMPLEMENTATIONS})
target_link_libraries(peargl raylib stdc++)
