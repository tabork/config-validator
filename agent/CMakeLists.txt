cmake_minimum_required(VERSION 3.14)
project(config_compare)

set(CMAKE_CXX_STANDARD 17)

find_package(Doxygen)

if (DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with DOXYGEN"
            VERBATIM)
endif(DOXYGEN_FOUND)

add_executable(config_compare src/main.cpp src/jarvis_the_bee.cpp src/jarvis_the_bee.h src/unordered_set_algorithms.h)