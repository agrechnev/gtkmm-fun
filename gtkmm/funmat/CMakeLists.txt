cmake_minimum_required(VERSION 3.1)

project(funmat)

set(CMAKE_CXX_STANDARD 14)

file(COPY elves.jpg DESTINATION .)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME}
   #HelloWorld.h
   main.cpp
        Hello.h)

target_link_libraries(${PROJECT_NAME}
   ${GTKMM_LIBRARIES}  ${OpenCV_LIBS} )
