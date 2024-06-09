#-------------------------------------------------------------------------------
# anyfxcompiler
#-------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 17)

fips_begin_app(anyfxcompiler cmdline)
     fips_vs_warning_level(3)
     fips_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
     fips_deps(anyfx antlr4 mcpp glslang)
     if(FIPS_LINUX OR FIPS_APPLE)
          fips_deps(anyfx stdc++fs)
     endif()
     fips_files(
          shadercompilerapp.cc
          shadercompilerapp.h
          singleshadercompiler.cc
          singleshadercompiler.h   
          argh.h
     )
fips_end_app()
