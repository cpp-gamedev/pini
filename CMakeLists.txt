cmake_minimum_required(VERSION 3.15)
project(pini)
add_executable(${PROJECT_NAME}  src/main.cpp
                                src/util.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror=return-type)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)