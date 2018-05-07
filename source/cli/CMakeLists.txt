set (CEEDUKO_EXE_NAME ceeduko)
set (CEEDUKO_EXE_SOURCE main.cpp)

add_executable(${CEEDUKO_EXE_NAME}
               ${CEEDUKO_EXE_SOURCE}
               ${FACTORY_SOURCE}
               ${IMPLEMENTATION_SOURCE})

set_target_properties(${CEEDUKO_EXE_NAME}
                      PROPERTIES OUTPUT_NAME ${CEEDUKO_EXE_NAME}
                      VERSION ${CEEDUKO_PROJECT_VERSION}
                      RUNTIME_OUTPUT_DIRECTORY ${CEEDUKO_BUILD_DIR}/bin)
