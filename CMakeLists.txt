MESSAGE("> Building main module")

cmake_minimum_required(VERSION 3.10)
project(MyMainProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

# pull from git
OPTION(LINK_SUBMODULE_A "Submodule A" ON)

find_package(Git QUIET)
IF(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    MESSAGE("Can download from Git")
    IF(LINK_SUBMODULE_A)
        if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/modules/Demo-Submodules-Mod/src")
            MESSAGE("UPDATING submodules")
            EXECUTE_PROCESS(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                            RESULT_VARIABLE result)
        ENDIF()

        if(result)
            message("Failed to get submodule: ${result}. Will continue without submodules")
            SET(LINK_SUBMODULE_A OFF)
        endif()
    ENDIF()
endif()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/modules/Demo-Submodules-ModA/src")
    MESSAGE("Did not find Submodule A. Turning off")
    SET(LINK_SUBMODULE_A OFF)
endif()

# building
IF(LINK_SUBMODULE_A)
    #add_subdirectory(modules/Demo-Submodules-ModA)  # Adding submodule
    MESSAGE("INCLUDE DIRS: ${CMAKE_CURRENT_SOURCE_DIR}/modules/Demo-Submodules-ModA/src")
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/modules/Demo-Submodules-ModA/src")
ELSE()
    MESSAGE("SKIPPING")
ENDIF()

add_executable(MyMainProject src/core/main.cpp modules/Demo-Submodules-ModA/src/Demo-Submodules-ModA/function.cpp src/core/corefunction/corefunction.cpp)
#target_link_libraries(MyMainProject MySubmoduleProject)