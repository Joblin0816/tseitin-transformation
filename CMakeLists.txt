cmake_minimum_required(VERSION 3.10)

project(tseitin-transformation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Source files
# -----------------------------
file(GLOB SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/generated/*.cpp
)

# -----------------------------
# Executable
# -----------------------------
add_executable(crow-server ${SRC_FILES})

# -----------------------------
# Include directories (IMPORTANT FIX)
# -----------------------------
target_include_directories(crow-server PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/generated
    ${CMAKE_SOURCE_DIR}
    /usr/local/include/antlr4-runtime
)

# -----------------------------
# Link libraries
# -----------------------------
target_link_libraries(crow-server
    antlr4-runtime
    pthread
)
