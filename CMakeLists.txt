cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(potts CXX)

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(ALPSCore 2.0 REQUIRED)

add_library(POTTSLIB STATIC potts.cpp graph.cpp)
target_link_libraries(POTTSLIB ${ALPSCore_LIBRARIES})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${ALPSCore_LIBRARIES} POTTSLIB)
