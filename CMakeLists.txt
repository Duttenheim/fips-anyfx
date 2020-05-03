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

if(NOT FIPS_IMPORT)
	fips_setup()
	fips_project(fips-anyfx)
endif()

	get_filename_component(ANYFX_SOURCE_DIR "anyfx" ABSOLUTE)

	ADD_DEFINITIONS(-DANTLR4CPP_STATIC)

	ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/compiler/mcpp)
	ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/compiler/antlr4)
	# set target subdirs
	SET_TARGET_PROPERTIES(mcpp PROPERTIES FOLDER Extlibs)
	SET_TARGET_PROPERTIES(antlr4 PROPERTIES FOLDER Extlibs)

    fips_begin_lib(anyfx)

		
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



        # explicitly only enable implemented generators
        fips_files(anyfx/compiler/code/generators/glslgenerator.cc)
        
		fips_src(anyfx/api/ NO_RECURSE)
		#fips_src(anyfx/api/highlevel/ NO_RECURSE)
		#fips_src(anyfx/api/highlevel/internal/ NO_RECURSE)
		#fips_src(anyfx/api/highlevel/loaders/ NO_RECURSE)

		fips_include_directories(anyfx/api)
		fips_include_directories(anyfx)
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
		fips_src(anyfx/compiler/code/parser4/ NO_RECURSE)
		fips_src(anyfx/util/code/ NO_RECURSE)
        
		IF (MSVC)
			IF(CMAKE_CL_64)
				SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4267")
			ENDIF()
		ENDIF()

		

		IF(ANYFX_TRANSPOSE_MATRICES)
			ADD_DEFINITIONS(-D__ANYFX_TRANSPOSE_MATRIX__)
		ENDIF()

		IF(ANYFX_BUILD_DEMO)
			ADD_SUBDIRECTORY(${ANYFX_SOURCE_DIR}/demo)
			SET_TARGET_PROPERTIES(demo PROPERTIES FOLDER ${ANYFX_FOLDER})
		ENDIF()

	fips_deps(antlr4 mcpp glslang)

	fips_end_lib()


	if(NOT BUILD_COMPILER AND ${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.16.0")
			set_target_properties(anyfx PROPERTIES UNITY_BUILD ON)
			set_target_properties(anyfx PROPERTIES UNITY_BUILD_BATCH_SIZE 20)
			set_property(SOURCE anyfx/api/lowlevel/vk/vksampler.cc PROPERTY SKIP_UNITY_BUILD_INCLUSION ON)
			set_property(SOURCE anyfx/util/code/binreader.cc PROPERTY SKIP_UNITY_BUILD_INCLUSION ON)
			set_property(SOURCE anyfx/compiler/code/structure.cc PROPERTY SKIP_UNITY_BUILD_INCLUSION ON)
			set_property(SOURCE anyfx/compiler/code/effect.cc PROPERTY SKIP_UNITY_BUILD_INCLUSION ON)
	endif()

	FILE(GLOB SRC anyfx/compiler/code/parser4/AnyFXParser.cpp anyfx/compiler/code/parser4/AnyFXLexer.cpp anyfx/compiler/code/parser4/AnyFXLexer.cpp anyfx/compiler/code/parser4/AnyFXBaseListener.cpp anyfx/compiler/code/parser4/AnyFXListener.cpp)
	SET_SOURCE_FILES_PROPERTIES( ${SRC} PROPERTIES LANGUAGE "CXX" )

    IF(BUILD_COMPILER)
        fips_add_subdirectory(anyfxcompiler)
    ENDIF()
if(NOT FIPS_IMPORT)
    fips_finish()
endif()
