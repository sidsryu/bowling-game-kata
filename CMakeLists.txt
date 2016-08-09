PROJECT( bowling-game-kata )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET( Game_SRCS src/Game.cpp src/Scorer.cpp )
IF( WIN32 )
	SET( Game_SRCS ${Game_SRCS} src/Game.h src/Scorer.h )
ENDIF( WIN32 )
ADD_LIBRARY( BowlingGameKata STATIC ${Game_SRCS} )

ADD_SUBDIRECTORY( tests )

INSTALL(TARGETS BowlingGameKata DESTINATION bin )

