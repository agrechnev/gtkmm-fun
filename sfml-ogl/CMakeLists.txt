cmake_minimum_required(VERSION 3.1)

project(sfml-ogl)

set(CMAKE_CXX_STANDARD 14)


find_package(OpenGL REQUIRED)
message("OPENGL_gl_LIBRARY = ${OPENGL_gl_LIBRARY}")
message("OPENGLu_gl_LIBRARY = ${OPENGL_glu_LIBRARY}")

set(SRCS
    main.cpp
)

set(SFML_LIBS
    sfml-graphics
    sfml-window 
    sfml-system
    ${OPENGL_gl_LIBRARY}
)

message("SFML_LIBS = ${SFML_LIBS}")

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})