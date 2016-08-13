enable_testing()

set(test_src
	AllTests.cpp
	GameTest.cpp
)

set(cpputest_lib 
	CppUTest.lib
)

if (MSVC)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /FI \"${cpputest_home}/include/CppUTest/MemoryLeakDetectorMallocMacros.h\"")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FI \"${cpputest_home}/include/CppUTest/MemoryLeakDetectorNewMacros.h\"")	
else ()	
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include \"${cpputest_home}/include/CppUTest/MemoryLeakDetectorMallocMacros.h\"")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include \"${cpputest_home}/include/CppUTest/MemoryLeakDetectorNewMacros.h\"")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include \"${cpputest_home}/include/CppUTest/MemoryLeakDetectorMallocMacros.h\"")
endif ()

include_directories(${cpputest_home}/include)
link_directories(${cpputest_home}/lib)

add_executable(AllTests ${test_src})

set_target_properties(AllTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(AllTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
set_target_properties(AllTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR})

if (COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif (COMMAND cmake_policy)

if (WIN32)
    target_link_libraries(AllTests BowlingGameKata ${cpputest_lib} winmm.lib)
else ()
	target_link_libraries(AllTests BowlingGameKata ${cpputest_lib})
endif ()

add_custom_command(TARGET AllTests POST_BUILD COMMAND AllTests)
