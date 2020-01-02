cmake_minimum_required(VERSION 3.14)
project(HFNUCGPEngineAPIForCpp)

#引擎名
set(ENGINE_NAME RandomEngine)
#引擎作者
set(ENGINE_AUTHOR mdmbct)
#引擎版本
set(ENGINE_VERSION v1.0)
#引擎dll文件输出路径
set(ENGINE_OUTPUT_PATH D:/Projects/IdeaProjects/HFNUCGPForConnect5/CGPData/ExtEngines)

#引擎dll文件名，形如“RandomEngine_mdmbct_v1.0.dll”，引擎名、作者名、版本必须用‘_’分隔，否则平台无法解析
set(DLL_NAME ${ENGINE_NAME}_${ENGINE_AUTHOR}_${ENGINE_VERSION})
include_directories(src/core/include)
include_directories(src/engine/include)

aux_source_directory(src dir_srcs)
aux_source_directory(src/core api_core)
aux_source_directory(src/engine example_engine)

set(CMAKE_CXX_STANDARD 11)
set(MAIN ${dir_srcs} ${api_core} ${example_engine} src)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
#生成可执行文件
#add_executable(HFNUCGPEngineAPIForCpp ${MAIN})
#生成动态链接库
add_library(${DLL_NAME} SHARED ${MAIN})
set_target_properties(${DLL_NAME} PROPERTIES LINKER_LANGUAGE C)
set_target_properties(${DLL_NAME} PROPERTIES PREFIX "")
SET(LIBRARY_OUTPUT_PATH ${ENGINE_OUTPUT_PATH})