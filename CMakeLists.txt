project(bowling-game-kata)

cmake_minimum_required(VERSION 3.0)

set(cpputest_home ${PROJECT_SOURCE_DIR}/lib/cpputest)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tests)
