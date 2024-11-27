cmake_minimum_required(VERSION 2.8.3)
project(meojson)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(src SRC)
set(SAMPLE sample/sample.cpp)
include_directories(./include)

find_package(Threads)
set(CMAKE_BUILD_TYPE Release)

add_library(meojson STATIC ${SRC})
add_executable(sample.out ${SAMPLE})
target_link_libraries(sample.out meojson ${CMAKE_THREAD_LIBS_INIT})