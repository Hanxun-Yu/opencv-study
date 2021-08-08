cmake_minimum_required(VERSION 3.0)
project(opencv_study)

set(CMAKE_CXX_STANDARD 11)


#根据opencv实际位置指定
#set(OpenCV_DIR "E://source//open//opencv//build_mingw//install//x64//mingw//lib")
find_package(OpenCV REQUIRED)

# set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-msse4")
# set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-msse4")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -qopenmp")

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

include_directories(./cv_api)
include_directories(./common_api)

AUX_SOURCE_DIRECTORY(./common_api SRC_COMMON_API)
AUX_SOURCE_DIRECTORY(./cv_api SRC_CV_API)
add_executable(opencv_study ${SRC_CV_API}
        ${SRC_COMMON_API}
        main.cpp)

#add_definitions("-Wall -g")



target_link_libraries( opencv_study ${OpenCV_LIBS} )

