cmake_minimum_required(VERSION 2.8)
get_filename_component(FIPS_ROOT_DIR "../fips" ABSOLUTE)
include("${FIPS_ROOT_DIR}/cmake/fips.cmake")

IF(WIN32)
	SET(OUTPUT_DEFAULT_DIR ${CMAKE_HOME_DIRECTORY}/bin/win32)
ELSEIF(UNIX)
	SET(OUTPUT_DEFAULT_DIR ${CMAKE_HOME_DIRECTORY}/bin/linux)
ENDIF()

MACRO(SET_DEFAULT_OUTPUT TargetName)
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${OUTPUT_DEFAULT_DIR})
ENDMACRO(SET_DEFAULT_OUTPUT)
		
fips_setup()
fips_project(fips-anyfx)

    fips_begin_lib(anyfx)

		get_filename_component(ANYFX_SOURCE_DIR "anyfx" ABSOLUTE)
		#SET(ANYFX_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/anyfx)

		IF(NOT DEFINED ANYFX_FOLDER)
			SET(ANYFX_FOLDER "anyfx")
		ENDIF()

		SET(ANYFX_HAS_METAL OFF)
		SET(ANYFX_HAS_DX12 OFF)
		IF (WIN32)
			SET(OPENGL_LIBS glu32.lib opengl32.lib)
		ELSEIF(APPLE)
			LINK_DIRECTORIES(/System/Library/Frameworks /usr/X11R6/lib /opt/local/lib)
			INCLUDE_DIRECTORIES(/System/Library/Frameworks /usr/X11R6/include /opt/local/include)
			FIND_PACKAGE(OpenGL REQUIRED)
			INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})
			SET(OPENGL_LIBS ${OPENGL_LIBRARIES} X11)
		ELSEIF(UNIX)
			SET(OPENGL_LIBS GL X11)
		ENDIF()

		# set compiler definitions
		IF(WIN32)
			ADD_DEFINITIONS(-D__WIN32__)
		ELSEIF(APPLE)
			ADD_DEFINITIONS(-D__APPLE__)
		ELSEIF(UNIX)
			ADD_DEFINITIONS(-D__UNIX__)
		ENDIF()

		IF(MSVC)
			ADD_DEFINITIONS(-D__MSVC__)
		ELSEIF(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
			ADD_DEFINITIONS(-D__GNUCXX__)
		ENDIF()
		
		OPTION(ANYFX_BUILD_DEMO "Build AnyFX Demo" OFF)
		OPTION(ANYFX_BUILD_COMPILER_LIBRARY "Build AnyFX Compiler as a library" ON)
		OPTION(ANYFX_TRANSPOSE_MATRICES "Builds AnyFX with automatic matrix transposing for variables")

		ADD_DEFINITIONS(-DANTLR4CPP_STATIC)
		
		fips_src(anyfx/api/ NO_RECURSE)
		#fips_src(anyfx/api/highlevel/ NO_RECURSE)
		#fips_src(anyfx/api/highlevel/internal/ NO_RECURSE)
		#fips_src(anyfx/api/highlevel/loaders/ NO_RECURSE)

		fips_include_directories(anyfx/api)
		fips_include_directories(anyfx/api/lowlevel)
		fips_include_directories(anyfx/api/highlevel)
		fips_include_directories(anyfx/compiler/code)
		fips_include_directories(anyfx/compiler/antlr4/src)
		fips_include_directories(anyfx/compiler/mcpp)
		fips_include_directories(anyfx/util/code)
		fips_src(anyfx/api/lowlevel/ NO_RECURSE)
		fips_src(anyfx/api/lowlevel/base/ NO_RECURSE)
		fips_src(anyfx/api/lowlevel/dx12/ NO_RECURSE)
		fips_src(anyfx/api/lowlevel/gl4/ NO_RECURSE)
		fips_src(anyfx/api/lowlevel/loaders/ NO_RECURSE)
		fips_src(anyfx/api/lowlevel/mtl/ NO_RECURSE)
		fips_src(anyfx/api/lowlevel/vk/ NO_RECURSE)
		
		fips_src(anyfx/compiler/code/ NO_RECURSE)
		fips_src(anyfx/compiler/code/expressions/ NO_RECURSE)
		fips_src(anyfx/compiler/code/generators/ NO_RECURSE)
		fips_src(anyfx/compiler/code/parser4/ NO_RECURSE)
		
		fips_src(anyfx/util/code/ NO_RECURSE)			
		
		#ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/api)
		#ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/compiler)
		#ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/util)
		#ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/exts/eastl)
		#ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/exts/glslang)
		#ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/compiler/mcpp)
		#ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/compiler/antlr)
		
		ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/compiler/mcpp)
		ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/compiler/antlr4)
	#	fips_dir(${ANYFX_SOURCE_DIR}/exts/eastl)
	#	fips_files(*.*)
	#	fips_dir(${ANYFX_SOURCE_DIR}/exts/glslang)
	#	fips_files(*.*)

	IF (MSVC)
			IF(CMAKE_CL_64)
				SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "/wd4267")
			ENDIF()
		ENDIF()

		# set target subdirs
		SET_TARGET_PROPERTIES(mcpp PROPERTIES FOLDER Extlibs)
		SET_TARGET_PROPERTIES(antlr4 PROPERTIES FOLDER Extlibs)

		ADD_LIBRARY(libglslang INTERFACE)
		TARGET_LINK_LIBRARIES(libglslang INTERFACE glslang)
		
		IF(ANYFX_TRANSPOSE_MATRICES)
			ADD_DEFINITIONS(-D__ANYFX_TRANSPOSE_MATRIX__)
		ENDIF()

		IF(ANYFX_BUILD_DEMO)
			ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/demo)
			SET_TARGET_PROPERTIES(demo PROPERTIES FOLDER ${ANYFX_FOLDER})
		ENDIF()
		
	fips_end_lib()
	
	#FILE(GLOB SRC anyfx/compiler/code/parser/AnyFXParser.c anyfx/compiler/code/parser/AnyFXLexer.c)
	FILE(GLOB SRC anyfx/compiler/code/parser4/AnyFXParser.cpp anyfx/compiler/code/parser4/AnyFXLexer.cpp anyfx/compiler/code/parser4/AnyFXLexer.cpp anyfx/compiler/code/parser4/AnyFXBaseListener.cpp anyfx/compiler/code/parser4/AnyFXListener.cpp)
	SET_SOURCE_FILES_PROPERTIES( ${SRC} PROPERTIES LANGUAGE "CXX" )
	
	FIND_PACKAGE(Vulkan)
	TARGET_INCLUDE_DIRECTORIES(anyfx PUBLIC ${Vulkan_INCLUDE_DIR})

fips_finish()

