cmake_minimum_required(VERSION 3.5)
project(RegTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 17) # inline variables need cpp standrad >= 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_options(-O3)
else()
    add_compile_options(-O2)
endif()

find_program(MOLD_LINKER mold)

if(MOLD_LINKER)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=mold")
else()
    message(WARNING "mold链接器未找到，使用默认链接器")
endif()

# 保持-Wl选项
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl")

file(GLOB_RECURSE CPP_SOURCES
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

message("Status: CPP_SOURCES: ${CPP_SOURCES}")

file(GLOB_RECURSE BUILD_DIR_FILES
    "${CMAKE_BINARY_DIR}/*"
)
list(REMOVE_ITEM CPP_SOURCES ${BUILD_DIR_FILES})

message(STATUS "Final source files: ${CPP_SOURCES}")

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/init
)

add_executable(reg_test ${CPP_SOURCES})
