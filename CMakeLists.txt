cmake_minimum_required(VERSION 3.10)
project(MyMainProject)

#add_subdirectory(external/logging_library)  # Adding submodule

#include_directories(${LOGGING_LIBRARY_INCLUDE_DIRS})

add_executable(MyMainProject src/main.cpp)
#target_link_libraries(MyMainProject logging_library)