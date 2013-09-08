cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)
cmake_policy(VERSION 2.6.4)

project(sea-crossing CXX C)

include(CheckIncludeFileCXX)
include(CheckLibraryExists)
include(FindPkgConfig)

if(NOT CMAKE_BUILD_TYPE)
	# default to RelWithDebInfo
	set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

set(STDCXX11_FLAGS "-std=c++11" CACHE STRING "Flags to enable C++11 support in compiler")

option(USE_ZLIB "try to use system zlib, otherwise use embedded miniz" ON)
option(FORCE_ZLIB "use system zlib")
option(BUILD_EXTRA_WARNINGS "enable extra warnings, may require gnu compiler")


set(ZLIB_LDFLAGS "")
set(ZLIB_CFLAGS "")
if(USE_ZLIB OR FORCE_ZLIB)
	check_include_file_cxx(zlib.h HAVE_ZLIB_H)
	check_library_exists(z inflate "" HAVE_LIBZ)
	if(HAVE_ZLIB_H AND HAVE_LIBZ)
		set(ZLIB_LDFLAGS "-lz")
		set(ZLIB_CFLAGS "")
		add_definitions(-DUSE_ZLIB)
	elseif(FORCE_ZLIB)
		message(FATAL_ERROR "couldn't find system zlib. make sure you installed development files for it.")
	endif(HAVE_ZLIB_H AND HAVE_LIBZ)
endif(USE_ZLIB OR FORCE_ZLIB)

pkg_check_modules(GLLIBS REQUIRED gl glew glfw3)

message(STATUS "searching for glm headers")
check_include_file_cxx(glm/glm.hpp HAVE_GLM_HPP)
if(NOT HAVE_GLM_HPP)
	message(FATAL_ERROR "missing glm headers")
endif(NOT HAVE_GLM_HPP)


add_executable(sea-crossing
	src/ai/ai_players.cpp
	src/conf.cpp
	src/engine/controls.cpp
	src/engine/framebufferObject.cpp
	src/engine/GLSLProgram.cpp
	src/engine/material.cpp
	src/engine/mesh.cpp
	src/engine/messageReceiver.cpp
	src/engine/postProcessor.cpp
	src/engine/renderHub.cpp
	src/engine/resourceManager.cpp
	src/engine/scene.cpp
	src/engine/sceneCamera.cpp
	src/engine/sceneEntity.cpp
	src/engine/sceneLightSource.cpp
	src/engine/texture2D.cpp
	src/engine/texture3D.cpp
	src/fbx/fbx_geometry.cpp
	src/fbx/fbx_node_name.cpp
	src/fbx/fbx_opengl_geometry.cpp
	src/fbx/fbx_parser.cpp
	src/fbx/fbx_print.cpp
	src/fbx/fbx_property.cpp
	src/fbx/fbx_reader.cpp
	src/fbx/fbx_unzip.cpp
	src/fbx/fbx_value.cpp
	src/game/board.cpp
	src/game/game.cpp
	src/game/human_players.cpp
	src/game/player.cpp
	src/main.cpp
)

if(BUILD_EXTRA_WARNINGS)
	set(WARN_CPPFLAGS "-g -O2 -g2 -Wall -Wmissing-declarations -Wcast-align -Wsign-compare -Wpointer-arith") # -Wshadow
	set(WARN_LDFLAGS "-g -O2 -g2 -Wall -Wl,--as-needed")
else(BUILD_EXTRA_WARNINGS)
	set(WARN_CPPFLAGS "")
	set(WARN_LDFLAGS "-Wall")
endif(BUILD_EXTRA_WARNINGS)

set(COMMON_LDFLAGS ${WARN_LDFLAGS} ${ZLIB_LDFLAGS} ${GLLIBS_LDFLAGS})
set(COMMON_CPPFLAGS "${STDCXX11_FLAGS} ${WARN_CPPFLAGS} ${ZLIB_CFLAGS} ${GLLIBS_CFLAGS}")

target_link_libraries(sea-crossing ${COMMON_LDFLAGS})
set_target_properties(sea-crossing PROPERTIES COMPILE_FLAGS "${COMMON_CPPFLAGS}")
