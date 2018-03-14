cmake_minimum_required (VERSION 2.8)

# project name and details
project (Ceeduko)
set(PROJECT_DESCRIPTION "Ceeduko")
set(PROJECT_URL "https://github.com/thomasms/ceeduko")

# Get the version, set in .VERSION file
file ( STRINGS "${CMAKE_SOURCE_DIR}/.VERSION" VERSION )
string( REPLACE "." ";" VERSION_LIST ${VERSION} )
list(GET VERSION_LIST 0 VERSION_MAJOR)
list(GET VERSION_LIST 1 VERSION_MINOR)
list(GET VERSION_LIST 2 VERSION_PATCH)
set(CEEDUKO_PROJECT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
message ( STATUS "CMake build configuration for Ceeduko ${CEEDUKO_PROJECT_VERSION}" )

# options
option(BUILD_TESTS "Build the tests" ON)
option(BUILD_PY_API "Build the python API" OFF)

# main directories
set (SOURCE_DIR_BASE ${CMAKE_CURRENT_LIST_DIR}/source)
set (TEST_DIR_BASE ${CMAKE_CURRENT_LIST_DIR}/testing)
set (EXTERNAL_DIR_BASE ${CMAKE_CURRENT_LIST_DIR}/external)

# C++ flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif (CMAKE_BUILD_TYPE EQUAL "DEBUG")

# set the output directories
set(CEEDUKO_BUILD_DIR ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

# set the source directories
set (API_DIR ${SOURCE_DIR_BASE}/api)
set (FACTORY_DIR ${SOURCE_DIR_BASE}/factory)
set (IMPLEMENTATION_DIR ${SOURCE_DIR_BASE}/implementation)
set (IO_DIR ${SOURCE_DIR_BASE}/io)
set (PY_DIR ${SOURCE_DIR_BASE}/py)
set (UTILS_DIR ${SOURCE_DIR_BASE}/utils)

set (PROGRAM_DIR ${SOURCE_DIR_BASE}/programs)

set (CEEDUKO_INCLUDES
    ${API_DIR}
    ${FACTORY_DIR}
    ${IMPLEMENTATION_DIR}
    ${IO_DIR}
    ${UTILS_DIR})

set (CATCH_INCLUDES ${EXTERNAL_DIR_BASE}/Catch2/single_include)
set (PYBIND_INCLUDES ${EXTERNAL_DIR_BASE}/pybind11/include)

set (ALL_INCLUDES ${CEEDUKO_INCLUDES} ${CATCH_INCLUDES})
include_directories(${ALL_INCLUDES})

# Add sources
add_subdirectory(${SOURCE_DIR_BASE})
if(BUILD_PY_API)
    add_subdirectory(${PY_DIR})
endif()
if(BUILD_TESTS)
    add_subdirectory(${TEST_DIR_BASE})
endif()
