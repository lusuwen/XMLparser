cmake_minimum_required(VERSION 3.5)

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")
project(xmlparser VERSION "0.1.0")

add_compile_options(-fPIC)


# 指定头文件搜索路径, 子模块也会共享此查询目录，无需重复设置
include_directories(
    ${PROJECT_SOURCE_DIR}/src/thirdparty/tinyxml2/inc/
)


# 指定源码目录
# aux_source_directory( ${PROJECT_SOURCE_DIR}/src src_dirs) 

# 指定库搜索路径
# link_directories(
#     ${PROJECT_SOURCE_DIR}/src/Thirdparty/gflags/lib/
#     ${PROJECT_SOURCE_DIR}/src/Thirdparty/glog/lib/
#     ${PROJECT_SOURCE_DIR}/src/Thirdparty/osqp/lib/
#     ${PROJECT_SOURCE_DIR}/src/Thirdparty/Qt/lib/
#     ${PROJECT_SOURCE_DIR}/src/Thirdparty/protobuf/lib/
# )


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/bin)


# 指定 编译子目录
add_subdirectory(src)

# 指定可执行文件输出目录
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) 
# 指定可执行文件名及源码
# add_executable(hh-rv20 ${src_dirs})

# 链接外部库
# target_link_libraries(hh-rv20 proxy) 


