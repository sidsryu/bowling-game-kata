#pragma once

#include <array>

class Game
{
public:
	void add(int pins);	
	void clear();

	int getScore(int frame) const;
	int getCurrentScore() const;	

private:
	std::array<int, 23> knockdownPins {};
	int rollCount {0};
};
