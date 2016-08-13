set(game_src
	Game.cpp
	Scorer.cpp
)

set(game_inc
	${PROJECT_SOURCE_DIR}/include/Game.h
	${PROJECT_SOURCE_DIR}/include/Scorer.h
)

add_library(BowlingGameKata STATIC ${game_src} ${game_inc})
install(FILES ${game_inc} DESTINATION include)
install(TARGETS BowlingGameKata DESTINATION lib)
