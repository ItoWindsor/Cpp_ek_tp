# exercise1/CMakeLists.txt

# Specify the source and include directories
set(SRC_DIR src)
set(INC_DIR include)  # Include directory specific to exercise1

# Collect the source files
file(GLOB SRC_FILES ${SRC_DIR}/*.cpp)

# Define the executable
add_executable(exercise1 ${SRC_FILES} main_exercise1.cpp)

# Include the exercise1/include directory for header files
target_include_directories(exercise1 PRIVATE ${CMAKE_SOURCE_DIR}/exercise1/${INC_DIR})

# Set the output directory for the executable
set_target_properties(exercise1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/exercise1
)
