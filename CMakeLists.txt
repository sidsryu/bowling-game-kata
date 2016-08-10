CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT( bowling-game-kata )

SET( Game_SRCS src/Game src/Scorer )
IF( WIN32 )
	SET( Game_SRCS ${Game_SRCS} include/Game include/Scorer )
ENDIF( WIN32 )

INCLUDE_DIRECTORIES( include )
ADD_LIBRARY( BowlingGameKata STATIC ${Game_SRCS} )

ADD_SUBDIRECTORY( tests )

INSTALL(TARGETS BowlingGameKata DESTINATION bin )

