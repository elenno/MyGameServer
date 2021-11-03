# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("MyGameServer")

include_directories(${PROJECT_SOURCE_DIR}/include)

message("SOURCE_DIR=${PROJECT_SOURCE_DIR}")

# 包含子项目。
add_subdirectory ("MyGameServer")
