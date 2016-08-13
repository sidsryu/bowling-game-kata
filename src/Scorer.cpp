#include "Scorer.h"
#include <algorithm>

using namespace std;

void Scorer::add(int pins)
{	
	knockdown_pins[total_ball_count] = pins;
	total_ball_count++;
}

void Scorer::reset()
{
	knockdown_pins.fill(0);
}

int Scorer::getScore(int frame)
{
	ball_cursor = 0;

	int score {0};
	for (int i = 0; i < frame; i++)
	{
		if (isStrike())
		{
			score += getThreeBallScore();	// strike(1 ball) + 2 bonus balls score
			ball_cursor++;
		}
		else if (isSpare())
		{
			score += getThreeBallScore();	// spare(2 balls) + 1 bonus ball score
			ball_cursor += 2;
		}
		else
		{
			score += getTwoBallScore();
			ball_cursor += 2;
		}
	}

	return score;
}

bool Scorer::isStrike() const
{
	return knockdown_pins[ball_cursor] == 10;
}

bool Scorer::isSpare() const
{
	auto first_ball_score = knockdown_pins[ball_cursor];
	auto second_ball_score = knockdown_pins[ball_cursor + 1];

	return (first_ball_score + second_ball_score) == 10;
}

int Scorer::getThreeBallScore() const
{
	return knockdown_pins[ball_cursor] +
		knockdown_pins[ball_cursor + 1] + 
		knockdown_pins[ball_cursor + 2];
}

int Scorer::getTwoBallScore() const
{
	return knockdown_pins[ball_cursor] +
		knockdown_pins[ball_cursor + 1];
}
