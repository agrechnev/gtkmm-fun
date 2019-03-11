cmake_minimum_required(VERSION 3.1)
project(fun1)
set(CMAKE_CXX_STANDARD 14)

file(COPY fun1.glade DESTINATION .)

add_executable(${PROJECT_NAME}
   main.cpp
)

target_link_libraries(${PROJECT_NAME}  ${GTKMM_LIBRARIES}  )
