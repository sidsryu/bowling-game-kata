#pragma once

#include <vector>

class Game
{
public:
	void add(size_t pins);	
	size_t getScore() const;

private:
	std::vector<size_t> knockdownPins;
};
