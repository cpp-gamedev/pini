cmake_minimum_required(VERSION 3.19)

project(pini)
add_library(${PROJECT_NAME}     src/util.cpp
                                src/util.hpp
                                src/pini.cpp
                                include/pini/pini.hpp)
add_library(pini::pini ALIAS pini)
target_include_directories(${PROJECT_NAME} PRIVATE src PUBLIC include)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror=return-type)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

option(PINI_BUILD_TESTS "Build tests" ON)

if(PINI_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

set(CCJSON "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
if(EXISTS "${CCJSON}")
    message(STATUS "Copying ${CCJSON} to project root")
    file(COPY "${CCJSON}" DESTINATION "${PROJECT_SOURCE_DIR}")
endif()
