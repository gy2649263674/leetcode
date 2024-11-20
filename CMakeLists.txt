# CMakeList.txt: leetcode 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.8)
project("fff")

# 如果支持，请为 MSVC 编译器启用热重载。
# set(ACTIVE_FILE "$ENV{ACTIVE_FILE}")
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(SOURCES "fff.cpp" "all.h")
add_executable(${PROJECT_NAME} ${SOURCES})

# if(${ACTIVE_FILE})
# get_filename_component(ACTIVE_FILE_NAME ${ACTIVE_FILE} NAME)
# add_executable(${PROJECT_NAME} ${ACTIVE_FILE_NAME})
# else()
# add_executable(${PROJECT_NAME} ${SOURCES})
# endif()

# set_target_properties(${PROJECT_NAME} PROPERTIES
# RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/debug"
# #LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build/debug"
# )

# 将源代码添加到此项目的可执行文件
# if(CMAKE_VERSION VERSION_GREATER 3.12)
# set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
# endif()

# TODO: 如有需要，请添加测试并安装目标。
