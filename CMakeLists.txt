cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(cYt-dlp)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

# 设置c++17
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else() # gcc clang
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif(MSVC)


if(MSVC)
set(PLATFORM win)
set(LINK_LIBRARY_DIR lib)
set(LINK_LIBRARY python37 python3)
endif()

add_executable(cYt-dlp main.cpp)

#添加头文件目录
target_include_directories(cYt-dlp PUBLIC ${CMAKE_SOURCE_DIR}/sdk/include)

# 添加库目录
target_link_directories(cYt-dlp PUBLIC ${CMAKE_SOURCE_DIR}/sdk/${PLATFORM}/${LINK_LIBRARY_DIR})


# 链接动态库
target_link_libraries(cYt-dlp PUBLIC ${LINK_LIBRARY})


if(MSVC)
	# 后处理脚本，将sdk bin目录复制到生成文件夹
	add_custom_command(
	TARGET cYt-dlp POST_BUILD
	COMMAND  xcopy "\"${CMAKE_SOURCE_DIR}/sdk/win/bin\"" "$(Outdir)" /E /Y
	)

	# 设置vs调试目录
	set_target_properties(cYt-dlp PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "$(OutDir)")
endif()