#include "Game.h"

void Game::add(size_t pins)
{
	if (10 < pins)	pins = 10;
	knockdownPins.push_back(pins);
}

size_t Game::getScore() const
{
	size_t score {0};
	for (auto pins : knockdownPins)
	{
		score += pins;
	}
	
	return score;
}
