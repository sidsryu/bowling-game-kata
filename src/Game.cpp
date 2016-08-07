#include "Game.h"
#include <algorithm>

using namespace std;

void Game::add(int pins)
{
	rollCount++;
	knockdownPins[rollCount] = pins;	
}

void Game::clear()
{
	knockdownPins.fill(0);
}

int Game::getScore(int frame) const
{
	int score {0};
	int ball {1};
	bool isFirstBall = true;
	int frameScore {0};

	for (int i = 1; i <= frame; )
	{
		if (isFirstBall && 10 <= knockdownPins[ball])
		{
			frameScore = min(knockdownPins[ball], 10);
			frameScore += min(knockdownPins[ball + 1], 10);
			frameScore += min(knockdownPins[ball + 2], 10);
			ball++;
			i++;
			score += frameScore;
			frameScore = 0;
		}
		else if (isFirstBall)
		{
			frameScore += knockdownPins[ball];
			isFirstBall = false;
			ball++;
		}
		else
		{
			frameScore += knockdownPins[ball];
			frameScore = min(frameScore, 10);
			if (10 <= frameScore)
			{
				frameScore += knockdownPins[ball + 1];
			}

			ball++;
			i++;
			isFirstBall = true;
			score += frameScore;
			frameScore = 0;
		}
	}

	return score;
}

int Game::getCurrentScore() const
{
	return getScore(10);
}
