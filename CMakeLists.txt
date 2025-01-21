cmake_minimum_required(VERSION 3.16)
project(TP_EK_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the list of subdirectories for exercises
set(SUBDIRS exercise1)

# Add each exercise subdirectory
foreach(subdir IN LISTS SUBDIRS)
    add_subdirectory(${subdir})
endforeach()

# Google Test configuration
add_subdirectory(external/googletest) # Include Google Test
enable_testing()                      # Enable testing

# Add the 'test' directory for unit tests
add_subdirectory(test)

# Help and clean_all targets
add_custom_target(show_help
        COMMAND ${CMAKE_COMMAND} -E echo "Usage: cmake --build . --target [target]"
        COMMAND ${CMAKE_COMMAND} -E echo "Targets:"
        COMMAND ${CMAKE_COMMAND} -E echo "  exercise1     Build and output to exercise1/"
        COMMAND ${CMAKE_COMMAND} -E echo "  tests         Build and run unit tests in 'test/'"
)

add_custom_target(tests
        COMMAND ${CMAKE_COMMAND} -E echo "Running tests..."
        COMMAND ctest --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running all tests"
)

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E echo "Removed build directory: ${CMAKE_BINARY_DIR}"
        COMMAND ${CMAKE_COMMAND} -E remove -f
        ${CMAKE_SOURCE_DIR}/exercise1/exercise1.exe
        COMMENT "Removing all build files and executables..."
)
