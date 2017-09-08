cmake_minimum_required(VERSION 3.5)
project(LeadSorterModul)

# substitute with your GNSDK home directory
set(GNSDK_DIR "/media/intruso/HDDLinux/Programming/APIs/gracenote/gnsdk")
message(STATUS "GNSDK directory at " ${GNSDK_DIR})
set(MYTARGET ${CMAKE_PROJECT_NAME})
message(STATUS "CMaking project " ${CMAKE_PROJECT_NAME} " to target " ${MYTARGET})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # optional

# add include and link directories
include_directories("${GNSDK_DIR}/include")
include_directories("${GNSDK_DIR}/include/linux_x86-64")
link_directories("${GNSDK_DIR}/lib/linux_x86-64")

# List include dirs
#get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
#foreach(dir ${dirs})
#    message(STATUS "dir='${dir}'")
#endforeach()

# add source files
set(SOURCE_FILES main.c)
add_executable(${MYTARGET} ${SOURCE_FILES})

# add link libraries
file(GLOB GNSDK_LIB "${GNSDK_DIR}/lib/linux_x86-64/*")
file(GLOB GNSDK_LIB_STATIC "${GNSDK_DIR}/lib_static/linux_x86-64/*")
message(STATUS "GNSDK_LIB: " ${GNSDK_LIB})
target_link_libraries(${MYTARGET} ${GNSDK_LIB})
#target_link_libraries(${MYTARGET} ${GNSDK_LIB_STATIC}) # no need for static libs