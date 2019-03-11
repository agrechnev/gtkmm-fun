cmake_minimum_required(VERSION 3.1)
project(fun2)
set(CMAKE_CXX_STANDARD 14)

file(COPY fun2.glade DESTINATION .)

add_executable(${PROJECT_NAME}
        main.cpp
        MainWindow.cpp MainWindow.h
        )

target_link_libraries(${PROJECT_NAME} ${GTKMM_LIBRARIES})
