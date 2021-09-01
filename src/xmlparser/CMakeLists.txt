cmake_minimum_required(VERSION 3.5)

#添加C++11支持及其他选项
#SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs -Wno-deprecated")
#set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS -g -ftest-coverage -fprofile-arcs"})

include_directories(
${PROJECT_SOURCE_DIR}/src/xmlparser/inc/
)

AUX_SOURCE_DIRECTORY(./src DIR_SRCS) 

add_executable(XMLparser ${DIR_SRCS})
target_link_libraries(XMLparser tinyxml)