SET( CPPUTEST_HOME ${CMAKE_SOURCE_DIR}/lib/cpputest )

IF( gcc )
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h" )
	SET( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h" )
ELSE( gcc)	
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FI${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h" )
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FI${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h" )
ENDIF( gcc )


INCLUDE_DIRECTORIES( ${CPPUTEST_HOME}/include )
LINK_DIRECTORIES( ${CPPUTEST_HOME}/lib )

SET( Test_SRCS AllTests GameTest )
ADD_EXECUTABLE( AllTests ${Test_SRCS} )

TARGET_LINK_LIBRARIES( AllTests BowlingGameKata CppUTestd )

INSTALL( TARGETS AllTests DESTINATION bin )

ADD_TEST( Alltests Alltests )

