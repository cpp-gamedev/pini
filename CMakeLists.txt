cmake_minimum_required(VERSION 3.19)

project(pini)
add_executable(${PROJECT_NAME}  src/main.cpp
                                src/util.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror=return-type)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

set(CCJSON "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
if(EXISTS "${CCJSON}")
    message(STATUS "Copying ${CCJSON} to project root")
    file(COPY "${CCJSON}" DESTINATION "${PROJECT_SOURCE_DIR}")
endif()