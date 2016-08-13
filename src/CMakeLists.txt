set(game_src
	game.cpp
	scorer.cpp
)

set(game_inc
	${PROJECT_SOURCE_DIR}/include/game.h
	${PROJECT_SOURCE_DIR}/include/scorer.h
)

add_library(BowlingGameKata STATIC ${game_src} ${game_inc})
install(FILES ${game_inc} DESTINATION include)
install(TARGETS BowlingGameKata DESTINATION bin)
