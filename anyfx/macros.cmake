IF(WIN32)
	SET(OUTPUT_DEFAULT_DIR ${CMAKE_HOME_DIRECTORY}/bin/win32)
ELSEIF(UNIX)
	SET(OUTPUT_DEFAULT_DIR ${CMAKE_HOME_DIRECTORY}/bin/linux)
ELSEIF(APPLE)
	SET(OUTPUT_DEFAULT_DIR ${CMAKE_HOME_DIRECTORY}/bin/macos)
ENDIF()

MACRO(SET_DEFAULT_OUTPUT TargetName)
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUTPUT_DEFAULT_DIR})
	SET_TARGET_PROPERTIES(${TargetName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${OUTPUT_DEFAULT_DIR})
ENDMACRO(SET_DEFAULT_OUTPUT)