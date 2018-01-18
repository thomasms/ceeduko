cmake_minimum_required(VERSION 3.1.0)
project (Solver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")

set(SOLVER_SOURCE_DIR ${PROJECT_SOURCE_DIR}/source)

include_directories("${SOLVER_SOURCE_DIR}/utils"
                    "${SOLVER_SOURCE_DIR}/api"
                    "${SOLVER_SOURCE_DIR}/factory"
                    "${SOLVER_SOURCE_DIR}/implementation"
                    "${SOLVER_SOURCE_DIR}/io")

file(GLOB HEADERS ${SOLVER_SOURCE_DIR}/utils/*.h
                  ${SOLVER_SOURCE_DIR}/api/*.h
                  ${SOLVER_SOURCE_DIR}/factory/*.h
                  ${SOLVER_SOURCE_DIR}/implementation/*.h
                  ${SOLVER_SOURCE_DIR}/io/*.h)

file(GLOB SOURCES ${SOLVER_SOURCE_DIR}/factory/*.cpp
                  ${SOLVER_SOURCE_DIR}/implementation/*.cpp
                  ${SOLVER_SOURCE_DIR}/main.cpp)

add_executable(main ${HEADERS} ${SOURCES})
