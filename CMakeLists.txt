cmake_minimum_required(VERSION 3.16)
project(TP_EK_CPP LANGUAGES CXX)

# Configuration de la version de C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Définir les répertoires des sources, des headers et des tests
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

# Inclure les headers
include_directories(${INCLUDE_DIR})

# Ajouter les fichiers sources et headers
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${INCLUDE_DIR}/*.hpp")

# Créer la bibliothèque principale
add_library(tp_ek_cpp_lib ${SOURCES} ${HEADERS})

# Configuration de Google Test
add_subdirectory(external/googletest) # Inclure Google Test
enable_testing()                      # Activer les tests unitaires

# Ajouter les fichiers de test
file(GLOB_RECURSE TEST_SOURCES "${TEST_DIR}/*.cpp")
add_executable(tp_ek_cpp_tests ${TEST_SOURCES})

# Lier les bibliothèques nécessaires
target_link_libraries(tp_ek_cpp_tests gtest gtest_main tp_ek_cpp_lib)

# Activer les tests
add_test(NAME all_tests COMMAND tp_ek_cpp_tests)
