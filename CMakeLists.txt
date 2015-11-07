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

add_executable(${EXECUTABLENAME} ${SOURCES} ${HEADERS})

add_test(NAME runprogram COMMAND ${EXECUTABLENAME} ${CMAKE_CURRENT_LIST_DIR}/tests/test.ld)

