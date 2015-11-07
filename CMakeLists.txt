cmake_minimum_required(VERSION 3.0)

project(OPLC_Compiler CXX)

enable_testing()

set(HEADERS
  intcode.h
  mcutable.h
  oplc_compiler.h
)

set(SOURCES
  miscutil.cpp
  iolist.cpp
  intcode.cpp
  circuit.cpp
  ansic.cpp
  schematic.cpp
  loadsave.cpp
  main.cpp
  compilecommon.cpp
)

set(EXECUTABLENAME OPLC_Compiler)

set(CXX_FLAGS -Wall -Werror CACHE STRING "CXX Compiler flags")

add_executable(${EXECUTABLENAME} ${SOURCES} ${HEADERS})
target_compile_options(${EXECUTABLENAME} PRIVATE ${CXX_FLAGS})

# Cross compiler settings.
set(CROSS_CXX_COMPILER "${CMAKE_CXX_COMPILER}" CACHE STRING "The cross CXX compiler")
set(CROSS_CXX_FLAGS "${CXX_FLAGS}" CACHE STRING "The cross CXX compiler FLAGS")

# Tests
add_test(NAME runprogram_noargs COMMAND ${EXECUTABLENAME})
set_tests_properties(runprogram_noargs PROPERTIES WILL_FAIL TRUE)

set(RUNPROGRAM_OUTLADDER "ladder.cpp")
add_test(NAME runprogram COMMAND ${EXECUTABLENAME} "${CMAKE_CURRENT_LIST_DIR}/tests/test.ld" "${RUNPROGRAM_OUTLADDER}")

add_test(NAME laddercompiles COMMAND "${CROSS_CXX_COMPILER}" ${CROSS_CXX_FLAGS} -c "${RUNPROGRAM_OUTLADDER}" "-iquote" "${CMAKE_CURRENT_LIST_DIR}/tests")
set_property(TEST laddercompiles APPEND PROPERTY DEPENDS runprogram)
