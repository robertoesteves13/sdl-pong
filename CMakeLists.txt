cmake_minimum_required(VERSION 3.21)
project(pong)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES include/*.hpp include/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
