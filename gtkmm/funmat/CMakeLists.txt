cmake_minimum_required(VERSION 3.1)

project(funmat)

set(CMAKE_CXX_STANDARD 14)

file(COPY ../pics/elves.jpg DESTINATION .)


add_executable(${PROJECT_NAME}
   #HelloWorld.h
   main.cpp
        Hello.h)

target_link_libraries(${PROJECT_NAME}
   ${GTKMM_LIBRARIES}  ${OpenCV_LIBS} )
