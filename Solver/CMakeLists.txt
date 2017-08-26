cmake_minimum_required(VERSION 3.1.0)
project (Solver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")

include_directories("${PROJECT_SOURCE_DIR}/utils"
                    "${PROJECT_SOURCE_DIR}/api"
                    "${PROJECT_SOURCE_DIR}/factory"
                    "${PROJECT_SOURCE_DIR}/implementation"
                    "${PROJECT_SOURCE_DIR}/io")

file(GLOB HEADERS ${PROJECT_SOURCE_DIR}/utils/*.h
                  ${PROJECT_SOURCE_DIR}/api/*.h
                  ${PROJECT_SOURCE_DIR}/factory/*.h
                  ${PROJECT_SOURCE_DIR}/implementation/*.h
                  ${PROJECT_SOURCE_DIR}/io/*.h)

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/factory/*.cpp
                  ${PROJECT_SOURCE_DIR}/implementation/*.cpp
                  ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(main ${HEADERS} ${SOURCES})
