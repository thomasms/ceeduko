# Set the project name
set (PY_API_NAME pyduko)

# Find default python libraries and interpreter
set(Python_ADDITIONAL_VERSIONS 3.6)

# set this to your python 3 lib absolute path, if cmake cannot find it
#set(PYTHON_LIBRARY "/usr/local/Cellar/python3/3.6.4_2/Frameworks/Python.framework/Versions/3.6/lib/libpython3.6.dylib")

find_package(PythonInterp 3 REQUIRED)
find_package(PythonLibs 3 REQUIRED)

message(STATUS "Using PyBind")

# Include directories
include_directories (${ALL_INCLUDES}
                     ${PYBIND_INCLUDES}
                     ${PYTHON_INCLUDE_DIRS})

# Library directories for linking
link_directories (${CEEDUKO_BUILD_DIR}/lib)

# Copy python scripts to output
file( GLOB scripts "*.py" )
foreach( scripts ${scripts})
    file( COPY "${scripts}" DESTINATION "${CEEDUKO_BUILD_DIR}/bin/py" )
endforeach()

set(PY_API_SOURCES
    api.cpp)

# Build and link the pylib module
add_library(${PY_API_NAME} SHARED ${PY_API_SOURCES})

target_link_libraries(${PY_API_NAME}
                      ${PYTHON_LIBRARIES}
                      ${FACTORY_LIB_NAME})

# Tweaks the name of the library to match what Python expects
set_target_properties(${PY_API_NAME} PROPERTIES SUFFIX .so)
set_target_properties(${PY_API_NAME} PROPERTIES PREFIX "")

# Set the exe properties
set_target_properties(${PY_API_NAME}
                      PROPERTIES OUTPUT_NAME ${PY_API_NAME}
                      VERSION ${CEEDUKO_PROJECT_VERSION}
                      LIBRARY_OUTPUT_DIRECTORY ${CEEDUKO_BUILD_DIR}/lib
                      ARCHIVE_OUTPUT_DIRECTORY ${CEEDUKO_BUILD_DIR}/lib
                      RUNTIME_OUTPUT_DIRECTORY ${CEEDUKO_BUILD_DIR}/bin)
