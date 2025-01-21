# test/CMakeLists.txt

# Collect test source files (e.g., test_exercise1.cpp)
set(TEST_SRC_DIR src)
set(TEST_INC_DIR include)

# Collect source files for the tests
file(GLOB TEST_SRC_FILES ${TEST_SRC_DIR}/*.cpp)

# Specify Monome.cpp as a source file to be included in the test build
list(APPEND TEST_SRC_FILES ${CMAKE_SOURCE_DIR}/exercise1/src/Monome.cpp)

# Define the test executable
add_executable(test_exercise1 ${TEST_SRC_FILES} test_exercise1.cpp)

# Include necessary directories (e.g., Monome.hpp)
target_include_directories(test_exercise1 PRIVATE
        ${CMAKE_SOURCE_DIR}/exercise1/include
)

# Link Google Test and pthread (for Unix-based systems)
target_link_libraries(test_exercise1 gtest gtest_main pthread)

# Specify the output directory for the test executable (in the 'test' folder inside the build-debug directory)
set_target_properties(test_exercise1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
)

# Register the test with CTest
add_test(NAME TestExercise1 COMMAND test_exercise1)
