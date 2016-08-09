SET( CPPUTEST_HOME ../lib/cpputest )

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h" )
SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h" )

SET( Test_SRCS tests/AllTests.cpp tests/GameTest.cpp )
ADD_EXECUTABLE( AllTests ${Test_SRCS} )

INCLUDE_DIRECTORIES( ${CPPUTEST_HOME}/include )

FIND_LIBRARY( CPPUTEST_LIBS NAMES cpputest PATHS ${CPPUTEST_HOME}/lib NO_DEFAULT_PATH )
TARGET_LINK_LIBRARIES( CppUTest RELEASE ${Test_SRCS} )
TARGET_LINK_LIBRARIES( CppUTestd DEBUG ${Test_SRCS} )

INSTALL( TARGETS AllTests DESTINATION bin )

