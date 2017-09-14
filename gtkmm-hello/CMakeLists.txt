cmake_minimum_required(VERSION 3.1)

project(gtkmm-hello)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)
                                  
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES 
# contain what you expect 

message("GTKMM_INCLUDE_DIRS = ${GTKMM_INCLUDE_DIRS}")
message("GTKMM_LIBRARY_DIRS = ${GTKMM_LIBRARY_DIRS}")
message("GTKMM_LIBRARIES = ${GTKMM_LIBRARIES}")

link_directories(
   ${GTKMM_LIBRARY_DIRS}  )

include_directories(
   ${GTKMM_INCLUDE_DIRS}  )

add_executable(${PROJECT_NAME}
   HelloWorld.h
   main.cpp
   )

target_link_libraries(${PROJECT_NAME}
   ${GTKMM_LIBRARIES}  )