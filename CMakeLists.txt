cmake_minimum_required(VERSION 3.10)
project(tseitin-transformation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Include directories (antlr4 installed into /usr/local)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}
    /usr/local/include/antlr4-runtime
)

# Source files
file(GLOB SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/generated/*.cpp
)

# Create the executable
add_executable(crow-server ${SRC_FILES})

# Link ANTLR4 runtime (from /usr/local/lib)
target_link_libraries(crow-server
    /usr/local/lib/libantlr4-runtime.so
    pthread
)
