cmake_minimum_required(VERSION 3.1)

project(sfml-hello)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
    main.cpp
)

set(SFML_LIBS
    sfml-graphics
    sfml-window 
    sfml-system
)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})