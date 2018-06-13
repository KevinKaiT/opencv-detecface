cmake_minimum_required(VERSION 2.8)
project( DetecFace )
find_package( OpenCV REQUIRED )

add_executable( detecface ./src/detecface.cpp )
target_link_libraries( detecface ${OpenCV_LIBS} )
