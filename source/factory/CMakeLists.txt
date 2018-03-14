set (FACTORY_LIB_NAME ceedukolib)

set (FACTORY_SOURCE
    ${FACTORY_DIR}/CellFactory.cpp
    ${FACTORY_DIR}/GridFactory.cpp
    ${FACTORY_DIR}/SolverFactory.cpp)

set (FACTORY_SOURCE ${FACTORY_SOURCE} PARENT_SCOPE)

add_library(${FACTORY_LIB_NAME} ${FACTORY_SOURCE}
                                ${IMPLEMENTATION_SOURCE})

set_target_properties(${FACTORY_LIB_NAME}
                      PROPERTIES OUTPUT_NAME ${FACTORY_LIB_NAME} LINKER_LANGUAGE CXX
                      VERSION ${CEEDUKO_PROJECT_VERSION}
                      LIBRARY_OUTPUT_DIRECTORY ${CEEDUKO_BUILD_DIR}/lib
                      ARCHIVE_OUTPUT_DIRECTORY ${CEEDUKO_BUILD_DIR}/lib)
