cmake_minimum_required(VERSION 3.19)

project(pini-test)
add_executable(${PROJECT_NAME}  pini_test.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE pini::pini)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror=return-type)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_test(pini-test pini-test)
