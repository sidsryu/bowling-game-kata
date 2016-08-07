#include "CppUTest/TestHarness.h"
#include "Game.h"

TEST_GROUP(GameTest)
{
};

TEST(GameTest, InitialScore)
{
	Game game;
	CHECK_EQUAL(0, game.getScore());
}

TEST(GameTest, AddLargePins)
{
	Game game;
	game.add(100);
	
	// Knockdown all
	CHECK_EQUAL(10, game.getScore());
}

TEST(GameTest, OneThrow)
{
	Game game;
	game.add(4);

	CHECK_EQUAL(4, game.getScore());
}

TEST(GameTest, TwoThrow)
{
	Game game;
	game.add(4);
	game.add(3);

	CHECK_EQUAL(7, game.getScore());
}
