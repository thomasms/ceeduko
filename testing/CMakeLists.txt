
set (UNITTEST_EXE_NAME ceedukotests)
set (UNITTEST_EXE_SOURCE ${TEST_DIR_BASE}/main.cpp)

set (UNITTEST_DIR ${TEST_DIR_BASE}/unittests)

set (UNITTEST_SOURCE
    ${UNITTEST_DIR}/BasicAccessorUnitTests.cpp
    ${UNITTEST_DIR}/CellCheckerUnitTests.cpp
    ${UNITTEST_DIR}/CellUnitTest.cpp
    ${UNITTEST_DIR}/GridUnitTests.cpp
    ${UNITTEST_DIR}/UnitTestUtils.cpp
    ${IMPLEMENTATION_DIR}/BacktrackingSolver.cpp
    ${IMPLEMENTATION_DIR}/Cell.cpp
    ${IMPLEMENTATION_DIR}/CellChecker.cpp
    ${IMPLEMENTATION_DIR}/Grid.cpp
    ${FACTORY_DIR}/CellFactory.cpp
    ${FACTORY_DIR}/GridFactory.cpp
    ${FACTORY_DIR}/SolverFactory.cpp)


include_directories(${ALL_INCLUDES} ${UNITTEST_DIR})

add_executable(${UNITTEST_EXE_NAME}
               ${UNITTEST_EXE_SOURCE}
               ${UNITTEST_SOURCE})

set_target_properties(${UNITTEST_EXE_NAME}
                      PROPERTIES OUTPUT_NAME ${UNITTEST_EXE_NAME}
                      VERSION ${CEEDUKO_PROJECT_VERSION}
                      RUNTIME_OUTPUT_DIRECTORY ${CEEDUKO_BUILD_DIR}/bin)
