cmake_minimum_required(VERSION 3.27)
project(CPP)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(CPP
        Homework/08/08_04.cpp)

target_link_libraries(CPP ${OpenCV_LIBS})
