cmake_minimum_required(VERSION 3.5)
project(RegTest)

# 生成compile_commands.json（用于代码补全/静态分析）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 明确指定使用clang编译器
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(MOLD_LINKER mold)

if(MOLD_LINKER)
    # 使用clang兼容的链接器选项格式
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fuse-ld=mold")
else()
    message(WARNING "mold链接器未找到，使用默认链接器")
endif()

# 保持-Wl选项
# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--no-as-needed")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")

# 只收集项目源码目录的.cpp文件（排除构建目录）
file(GLOB_RECURSE CPP_SOURCES
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# 排除构建目录下的所有文件
file(GLOB_RECURSE BUILD_DIR_FILES
    "${CMAKE_BINARY_DIR}/*"
)
list(REMOVE_ITEM CPP_SOURCES ${BUILD_DIR_FILES})

message(STATUS "Final source files: ${CPP_SOURCES}")

# 添加可执行文件（只包含.cpp文件）
add_executable(reg_test ${CPP_SOURCES})