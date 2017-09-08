cmake_minimum_required(VERSION 3.5)
project(LeadSorterModul)

set(MYTARGET ${CMAKE_PROJECT_NAME})
message(STATUS "CMaking project " ${CMAKE_PROJECT_NAME} " to target " ${MYTARGET})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # optional

include_directories(../../include)
include_directories(../../include/linux_x86-64)
link_directories(../../lib/linux_x86-64)

set(SOURCE_FILES main.c)

add_executable(${MYTARGET} ${SOURCE_FILES})

file(GLOB GNSDK_LIB "../../lib/linux_x86-64/*")
file(GLOB GNSDK_LIB_STATIC "../../lib_static/linux_x86-64/*")
message(STATUS "GNSDK_LIB: " ${GNSDK_LIB})

target_link_libraries(${MYTARGET} ${GNSDK_LIB})
#target_link_libraries(${MYTARGET} ${GNSDK_LIB_STATIC}) # no need for static libs