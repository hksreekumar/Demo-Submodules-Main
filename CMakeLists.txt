MESSAGE("> Building main module")

cmake_minimum_required(VERSION 3.10)
project(MyMainProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(modules/Demo-Submodules-ModA)  # Adding submodule

MESSAGE("INCLUDE DIRS: ${CMAKE_CURRENT_SOURCE_DIR}/modules/Demo-Submodules-ModA/src")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/modules/Demo-Submodules-ModA/src")

add_executable(MyMainProject src/main.cpp)
target_link_libraries(MyMainProject MySubmoduleProject)