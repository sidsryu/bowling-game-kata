#include "Game.h"
#include "Scorer.h"
#include <algorithm>
#include <assert.h>

using namespace std;

Game::Game()
	: scorer(std::make_unique<Scorer>())
{}

Game::~Game() = default;

bool Game::add(int pins)
{
	if (!isValid(pins))	return false;

	scorer->add(pins);
	calculateCurrentFrame(pins);
	return true;
}

bool Game::isValid(int pins) const
{
	if (pins < 0)	return false;
	if (is_first_ball && 10 < pins)	return false;	
	if (10 < last_knockdown_pins + pins)	return false;

	return true;
}

void Game::calculateCurrentFrame(int pins)
{
	if (isLastBallInFrame(pins))
	{
		current_frame = min(10, current_frame + 1);
		last_knockdown_pins = 0;
		is_first_ball = true;
	}
	else
	{
		last_knockdown_pins = pins;
		is_first_ball = false;
	}
}

bool Game::isLastBallInFrame(int pins) const
{
	return isStrike(pins) || !is_first_ball;
}

bool Game::isStrike(int pins) const
{
	return is_first_ball && pins == 10;
}

void Game::reset()
{
	scorer->reset();
}

int Game::getScore(int frame) const
{
	return scorer->getScore(frame);
}

int Game::getCurrentScore() const
{
	return getScore(current_frame);
}
