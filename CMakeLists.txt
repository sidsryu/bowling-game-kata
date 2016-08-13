project(bowling-game-kata)

cmake_minimum_required(VERSION 2.4)

set(cpputest_home ${PROJECT_SOURCE_DIR}/lib/cpputest)
set(CMAKE_CONFIGURATION_TYPES Debug Release)

include(ExternalProject)

set(cpputest_cmake_args
	-DCMAKE_INSTALL_PREFIX=${cpputest_home}
	-DTESTS=OFF
)
ExternalProject_Add(CppUTest
	PREFIX cpputest-master
	GIT_REPOSITORY https://github.com/cpputest/cpputest.git	
	CMAKE_ARGS ${cpputest_cmake_args}	
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tests)
add_dependencies(AllTests CppUTest)
