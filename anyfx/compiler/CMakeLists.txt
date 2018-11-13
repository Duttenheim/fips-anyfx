#-------------------------------------------------------------------------------
# anyfx compiler
#-------------------------------------------------------------------------------

ADD_SUBDIRECTORY(antlr4)
ADD_SUBDIRECTORY(mcpp)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}
		    ${ANYFX_SOURCE_DIR}/util/code
		    ${ANYFX_SOURCE_DIR}/compiler/code
			${ANYFX_SOURCE_DIR}/compiler/antlr4/src
			${ANYFX_SOURCE_DIR}/exts/glslang
		    ${ANYFX_SOURCE_DIR}/compiler/mcpp
)
					

FILE(GLOB SRC "code/*.cc")
FILE(GLOB HEAD "code/*.h")
SOURCE_GROUP("compiler" FILES ${SRC} ${HEAD})
LIST(APPEND CODE ${SRC} ${HEAD})

FILE(GLOB SRC "code/expressions/*.cc")
FILE(GLOB HEAD "code/expressions/*.h")
SOURCE_GROUP("compiler\\expressions" FILES ${SRC} ${HEAD})
LIST(APPEND CODE ${SRC} ${HEAD})

FILE(GLOB SRC "code/generators/*.cc")
SOURCE_GROUP("compiler\\generators" FILES ${SRC} ${HEAD})
LIST(APPEND CODE ${SRC} ${HEAD})

FILE(GLOB SRC code/parser4/AnyFXParser.cpp code/parser4/AnyFXLexer.cpp)
FILE(GLOB HEAD code/parser4/AnyFXParser.h code/parser4/AnyFXLexer.h)
SOURCE_GROUP("parser" FILES ${SRC} ${HEAD})
SET_SOURCE_FILES_PROPERTIES( ${SRC} PROPERTIES LANGUAGE "CXX" )
LIST(APPEND CODE ${SRC} ${HEAD})
	
IF (ANYFX_BUILD_COMPILER_LIBRARY)

	# remove main from cmake
	FILE(GLOB MAIN "code/main.cc")
	LIST(REMOVE_ITEM CODE ${MAIN})
	
	ADD_DEFINITIONS(-D__ANYFX_COMPILER_LIBRARY__)
	ADD_LIBRARY(compiler STATIC ${CODE})
ELSE()
	ADD_EXECUTABLE(compiler ${CODE})	
ENDIF()

	ADD_DEPENDENCIES(compiler
		#GenerateParser
		util
		antlr4
		glslang
		OGLCompiler
		OSDependent
		SPIRV
		HLSL
		mcpp)
		
	TARGET_LINK_LIBRARIES(compiler
		util
		antlr4
		mcpp
		glslang
		OGLCompiler
		OSDependent
		SPIRV
		HLSL
		${OPENGL_LIBS})
		
SET_DEFAULT_OUTPUT(compiler)

IF (MSVC11)
	ADD_DEFINITIONS(-D_XKEYCHECK_H)
ENDIF()
