cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(potts CXX)

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(ALPSCore 2.0 REQUIRED)

add_library(POTTSLIB STATIC potts.cpp graph.cpp)
target_link_libraries(POTTSLIB ${ALPSCore_LIBRARIES})

set(MAIN_PROJECT main)
set(TEST_PROJECT graph_test)
add_executable(${MAIN_PROJECT} main.cpp)
add_executable(${TEST_PROJECT} graph_test.cpp)

target_link_libraries(${MAIN_PROJECT} ${ALPSCore_LIBRARIES} POTTSLIB)
target_link_libraries(${TEST_PROJECT} ${ALPSCore_LIBRARIES} POTTSLIB)
