#include "CppUTest/TestHarness.h"
#include "Game.h"

TEST_GROUP(GameTest)
{
};

TEST(GameTest, InitialScore)
{
	Game game;
	CHECK_EQUAL(0, game.getCurrentScore());
}

TEST(GameTest, AddLargePins)
{
	Game game;
	game.add(100);
	
	// large pins is Knockdown all
	CHECK_EQUAL(10, game.getScore(1));
}

TEST(GameTest, OneThrow)
{
	Game game;
	game.add(4);

	CHECK_EQUAL(4, game.getScore(1));
}

TEST(GameTest, TwoThrow)
{
	Game game;
	game.add(4);
	game.add(3);

	CHECK_EQUAL(7, game.getScore(1));
}

TEST(GameTest, fiveThrow)
{
	Game game;
	game.add(4);
	game.add(3);
	game.add(8);
	game.add(0);
	game.add(3);

	CHECK_EQUAL(7, game.getScore(1));
	CHECK_EQUAL(15, game.getScore(2));
	CHECK_EQUAL(18, game.getScore(3));
}

TEST(GameTest, Strike)
{
	Game game;
	game.add(10);
	game.add(4);
	game.add(3);

	CHECK_EQUAL(17, game.getScore(1));
	CHECK_EQUAL(24, game.getScore(2));
}

TEST(GameTest, StrikeAfterGutter)
{
	Game game;
	game.add(10);
	game.add(0);
	game.add(3);

	CHECK_EQUAL(13, game.getScore(1));
	CHECK_EQUAL(16, game.getScore(2));
}

TEST(GameTest, Spare)
{
	Game game;
	game.add(7);
	game.add(3);
	game.add(5);
	game.add(2);

	CHECK_EQUAL(15, game.getScore(1));
	CHECK_EQUAL(22, game.getScore(2));
}

TEST(GameTest, Sample)
{
	Game game;
	game.add(1);
	game.add(4);
	game.add(4);
	game.add(5);
	game.add(6);
	game.add(4);
	game.add(5);
	game.add(5);
	game.add(10);
	game.add(0);
	game.add(1);
	game.add(7);
	game.add(3);
	game.add(6);
	game.add(4);
	game.add(10);
	game.add(2);
	game.add(8);
	game.add(6);

	CHECK_EQUAL(5, game.getScore(1));
	CHECK_EQUAL(14, game.getScore(2));
	CHECK_EQUAL(29, game.getScore(3));
	CHECK_EQUAL(49, game.getScore(4));
	CHECK_EQUAL(60, game.getScore(5));
	CHECK_EQUAL(61, game.getScore(6));
	CHECK_EQUAL(77, game.getScore(7));
	CHECK_EQUAL(97, game.getScore(8));
	CHECK_EQUAL(117, game.getScore(9));
	CHECK_EQUAL(133, game.getScore(10));
}
