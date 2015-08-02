cmake_minimum_required (VERSION 2.6)

project (LibRetroServerTest)

add_subdirectory("${PROJECT_SOURCE_DIR}/../../LibRetroServer/build" "${PROJECT_SOURCE_DIR}/../../LibRetroServer_build")
include_directories("${PROJECT_SOURCE_DIR}/../../3rdParty/libretro")
include_directories("${PROJECT_SOURCE_DIR}/../../core/inc")
include_directories("${PROJECT_SOURCE_DIR}/../../Platform/inc")
include_directories("${PROJECT_SOURCE_DIR}/../../LibRetroServer/inc")


###############################################
#exe
###############################################
file(GLOB_RECURSE lrt_src1 "${PROJECT_SOURCE_DIR}/../src/*.h")
file(GLOB_RECURSE lrt_src2 "${PROJECT_SOURCE_DIR}/../src/*.cpp")
list(APPEND lrt_src ${lrt_src1})
list(APPEND lrt_src ${lrt_src2})

add_executable(LibRetroServerTest WIN32 $<TARGET_OBJECTS:platform> $<TARGET_OBJECTS:LibRetroServer> ${lrt_src})
						
set_property(TARGET LibRetroServerTest APPEND PROPERTY COMPILE_FLAGS "-WX -W4")
