cmake_minimum_required(VERSION 3.16)
project(TP_EK_CPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the list of subdirectories
set(SUBDIRS exercise1)

# Add each subdirectory
foreach(subdir IN LISTS SUBDIRS)
    add_subdirectory(${subdir})
endforeach()

# Help and clean_all targets (if needed)
add_custom_target(show_help
        COMMAND ${CMAKE_COMMAND} -E echo "Usage: cmake --build . --target [target]"
        COMMAND ${CMAKE_COMMAND} -E echo "Targets:"
        COMMAND ${CMAKE_COMMAND} -E echo "  exercise1     Build and output to exercise1/"
        COMMAND ${CMAKE_COMMAND} -E echo "  exercise2     Build and output to exercise2/"
        COMMAND ${CMAKE_COMMAND} -E echo "  exercise3     Build and output to exercise3/"
)

add_custom_target(clean_all
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
        COMMAND ${CMAKE_COMMAND} -E echo "Removed build directory: ${CMAKE_BINARY_DIR}"
        COMMAND ${CMAKE_COMMAND} -E remove -f
        ${CMAKE_SOURCE_DIR}/exercise1/exercise1.exe
        ${CMAKE_SOURCE_DIR}/exercise2/exercise2.exe
        ${CMAKE_SOURCE_DIR}/exercise3/exercise3.exe
        COMMENT "Removing all build files and executables..."
)
