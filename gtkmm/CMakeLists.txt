cmake_minimum_required(VERSION 3.1)

project(gtkmm-examples)

set(CMAKE_CXX_STANDARD 14)
file(COPY pics DESTINATION .)
find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0)
                                  
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES 
# contain what you expect 

#message("GTKMM_INCLUDE_DIRS = ${GTKMM_INCLUDE_DIRS}")
#message("GTKMM_LIBRARY_DIRS = ${GTKMM_LIBRARY_DIRS}")
#message("GTKMM_LIBRARIES = ${GTKMM_LIBRARIES}")

link_directories(
   ${GTKMM_LIBRARY_DIRS}  )

include_directories(
   ${GTKMM_INCLUDE_DIRS}  )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )   

#add_subdirectory(hello)
#add_subdirectory(fun1)
#add_subdirectory(fun2)
add_subdirectory(cursor)
#add_subdirectory(funmat)
#add_subdirectory(zoommat)
#add_subdirectory(funvideo)
#add_subdirectory(rubber)
