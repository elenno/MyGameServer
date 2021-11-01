# CMakeList.txt: MyGameServer 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

#link_directories要放在add_executable之前
link_directories(
    "${PROJECT_SOURCE_DIR}/lib/libhv"
)

include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(.)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/servercommon)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE COMMON_FILES "${PROJECT_SOURCE_DIR}/servercommon/*.cpp")

message("Common Files=${COMMON_FILES}")
message("Src Files=${SRC_FILES}")

#使用hv_static静态库，需要声明宏HV_STATICLIB
add_definitions(-DHV_STATICLIB)

# 将源代码添加到此项目的可执行文件。
add_executable (MyGameServer ${COMMON_FILES} ${SRC_FILES})

if (WIN32 OR MSVC)
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
elseif (UNIX)
	set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
endif()


message("${PROJECT_SOURCE_DIR}/lib/libhv")

target_link_libraries(${PROJECT_NAME} hv_static)

