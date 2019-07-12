cmake_minimum_required(VERSION 3.14)
project(config_compare)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CPP_COMPILER "g++")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(restinio CONFIG REQUIRED)

find_package(Doxygen)

if (DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ALL ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with DOXYGEN"
            VERBATIM)
endif(DOXYGEN_FOUND)

include_directories(include/)
include_directories(${OPENSSL_INCLUDE_DIR})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(config_compare ${SRC_FILES})

target_link_libraries(config_compare crypto)
target_link_libraries(config_compare restinio::restinio)
target_link_libraries(config_compare ${CONAN_LIBS})