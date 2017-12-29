cmake_minimum_required(VERSION 3.1)

project(fun1)

set(CMAKE_CXX_STANDARD 14)

#file(COPY ../pics/info.xpm DESTINATION .)
file(COPY ../pics/elves.jpg DESTINATION .)

add_executable(${PROJECT_NAME}
   main.cpp
   Hello.h Hello.cpp
)

target_link_libraries(${PROJECT_NAME}
   ${GTKMM_LIBRARIES}  )
