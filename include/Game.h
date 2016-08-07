#pragma once

#include <memory>

class Scorer;

class Game
{
public:
	Game();
	~Game();

	bool add(int pins);
	void reset();

	int getScore(int frame) const;
	int getCurrentScore() const;	

private:
	void calculateCurrentFrame(int pins);
	bool isLastBallInFrame(int pins) const;
	bool isStrike(int pins) const;
	bool isValid(int pins) const;

private:	
	bool is_first_ball {true};
	int last_knockdown_pins {0};
	int current_frame {0};
	std::unique_ptr<Scorer> scorer;
};
