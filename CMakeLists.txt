cmake_minimum_required(VERSION 3.27)
project(Raytracing)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Source files for application
file(GLOB SOURCES
        ${CMAKE_SOURCE_DIR}/src/*.cpp
)

add_executable(Raycast ${SOURCES})

target_include_directories(Raycast PUBLIC
	include
)

target_include_directories(Raycast PUBLIC
	lib
)