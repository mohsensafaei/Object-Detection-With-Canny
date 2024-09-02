cmake_minimum_required(VERSION 3.10)
project( PREDICT )

########## opencv section
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

########## Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


INCLUDE_DIRECTORIES(./inc)

add_executable( PREDICT ./src/main.cpp
                      ./src/Prediction.cpp
                      ./src/ClogiPy.cpp )
target_link_libraries( PREDICT ${OpenCV_LIBS} m)