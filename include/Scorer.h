#pragma once

#include <array>

class Scorer
{
public:
	void add(int pins);
	void reset();
	int getScore(int frame);

private:
	bool isStrike() const;
	bool isSpare() const;
	int getThreeBallScore() const;
	int getTwoBallScore() const;

private:
	std::array<int, 23> knockdown_pins {};
	int total_ball_count {0};
	int ball_cursor {0};
};
