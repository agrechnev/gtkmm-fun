cmake_minimum_required(VERSION 3.1)

project(hello)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}
   HelloWorld.h
   main.cpp
   )

target_link_libraries(${PROJECT_NAME}
   ${GTKMM_LIBRARIES}  )