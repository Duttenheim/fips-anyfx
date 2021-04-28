PROJECT(AnyFX)
cmake_minimum_required(VERSION 2.8)
get_filename_component(FIPS_ROOT_DIR "../fips" ABSOLUTE)
include("${FIPS_ROOT_DIR}/cmake/fips.cmake")

ADD_DEFINITIONS(-DANTLR4CPP_STATIC)

if(NOT FIPS_IMPORT)
	fips_project(anyfx)
	fips_setup()
endif()

	SET(ANYFX_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
	get_filename_component(ANYFX_SOURCE_DIR "anyfx" ABSOLUTE)

	fips_add_subdirectory(code)

    IF(BUILD_COMPILER)
        fips_add_subdirectory(anyfxcompiler)
    ENDIF()
if(NOT FIPS_IMPORT)
    fips_finish()
endif()
