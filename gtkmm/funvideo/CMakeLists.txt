cmake_minimum_required(VERSION 3.1)

project(funvideo)

set(CMAKE_CXX_STANDARD 14)

# Threads
find_package(Threads)

add_executable(${PROJECT_NAME}
   #HelloWorld.h
   main.cpp
        Hello.h)

target_link_libraries(${PROJECT_NAME}
   ${GTKMM_LIBRARIES}  ${OpenCV_LIBS}  ${CMAKE_THREAD_LIBS_INIT})
