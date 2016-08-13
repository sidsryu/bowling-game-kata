project(bowling-game-kata)

cmake_minimum_required(VERSION 2.6)

set(cpputest_home ${PROJECT_SOURCE_DIR}/lib/cpputest)

include(CTest)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tests)

set(INCLUDE_INSTALL_DIR "include")
set(LIB_INSTALL_BIN "bin")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
