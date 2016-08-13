set(test_src
	AllTests.cpp
	GameTest.cpp
)

set(cpputest_lib 
	CppUTestd.lib
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
foreach (IT ${CMAKE_CONFIGURATIONS_TYPES})
	string(TOUPPER ${IT} IT)
	set_target_properties(AllTests PROPERTIES RUNTIME_OUTPUT_DIRECTORY_${IT} ${CMAKE_CURRENT_BINARY_DIR})
endforeach ()

target_link_libraries(AllTests BowlingGameKata ${cpputest_lib})
