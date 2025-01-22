# test/CMakeLists.txt

# Collect test source files
set(TEST_SRC_DIR src)
file(GLOB TEST_SRC_FILES ${TEST_SRC_DIR}/*.cpp)

# Common source files for both tests
set(COMMON_SRC_FILES
        ${CMAKE_SOURCE_DIR}/exercise1/src/monome.cpp
        ${CMAKE_SOURCE_DIR}/exercise1/src/polynome.cpp
)

# Define test executables
add_executable(test_monome ${COMMON_SRC_FILES} test_monome.cpp)
add_executable(test_polynome ${COMMON_SRC_FILES} test_polynome.cpp)

# Include directories for the test targets
target_include_directories(test_monome PRIVATE ${CMAKE_SOURCE_DIR}/exercise1/include)
target_include_directories(test_polynome PRIVATE ${CMAKE_SOURCE_DIR}/exercise1/include)

# Link Google Test and pthread to the test executables using the 'PRIVATE' keyword
target_link_libraries(test_monome PRIVATE gtest gtest_main pthread)
target_link_libraries(test_polynome PRIVATE gtest gtest_main pthread)

# Set output directory for the test executables
set_target_properties(test_monome test_polynome PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
        FOLDER "test"
)

# Register tests with CTest
add_test(NAME TestMonome COMMAND test_monome)
add_test(NAME TestPolynome COMMAND test_polynome)
