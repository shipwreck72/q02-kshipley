/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, dropPiece_x)
{
	Piezas tst;
	ASSERT_EQ(X, tst.dropPiece(0));
}

TEST(PiezasTest, dropPiece_o)
{
	Piezas tst;
	tst.dropPiece(0);
	ASSERT_EQ(O, tst.dropPiece(0));
}

TEST(PiezasTest, dropPiece_out)
{
	Piezas tst;
	ASSERT_EQ(Invalid, tst.dropPiece(4));
}

TEST(PiezasTest, dropPiece_out1)
{
	Piezas tst;
	ASSERT_EQ(Invalid, tst.dropPiece(-3));
}

TEST(PiezasTest, dropPiece_full)
{
	Piezas tst;
	tst.dropPiece(1);
	tst.dropPiece(1);
	tst.dropPiece(1);
	ASSERT_EQ(Blank, tst.dropPiece(1));
}

TEST(PiezasTest, pieceAt_outneg1)
{
	Piezas tst;
	ASSERT_EQ(Invalid, tst.pieceAt(-3, 1));
}


TEST(PiezasTest, pieceAt_outneg2)
{
	Piezas tst;
	ASSERT_EQ(Invalid, tst.pieceAt(2, -1));
}

TEST(PiezasTest, pieceAt_outpos1)
{
	Piezas tst;
	ASSERT_EQ(Invalid, tst.pieceAt(3,0));
}

TEST(PiezasTest, pieceAt_outpos2)
{
	Piezas tst;
	ASSERT_EQ(Invalid, tst.pieceAt(0,4));
}

TEST(PiezasTest, pieceAt_blk)
{
	Piezas tst;
	ASSERT_EQ(Blank, tst.pieceAt(2,0));
}

TEST(PiezasTest, pieceAt_x)
{
	Piezas tst;
	tst.dropPiece(2);
	ASSERT_EQ(X, tst.pieceAt(2,2));
}

TEST(PiezasTest, gamestate_inc)
{
	Piezas tst;
	tst.dropPiece(2);
	tst.dropPiece(2);
	ASSERT_EQ(Invalid, tst.gameState());
}

TEST(PiezasTest, gamestate_tie)
{
	Piezas tst;
	tst.dropPiece(2);
	tst.dropPiece(2);
	tst.dropPiece(2);
	tst.dropPiece(1);
	tst.dropPiece(1);
	tst.dropPiece(1);
	tst.dropPiece(0);
	tst.dropPiece(0);
	tst.dropPiece(0);
	tst.dropPiece(3);
	tst.dropPiece(3);
	tst.dropPiece(3);
	ASSERT_EQ(Blank, tst.gameState());
}

TEST(PiezasTest, gamestate_x)
{
	Piezas tst;
	tst.dropPiece(0);
	tst.dropPiece(0);
	tst.dropPiece(1);
	tst.dropPiece(1);
	tst.dropPiece(2);
	tst.dropPiece(2);
	tst.dropPiece(3);
	tst.dropPiece(0);
	tst.dropPiece(3);
	tst.dropPiece(1);
	tst.dropPiece(3);
	tst.dropPiece(2);
	ASSERT_EQ(O, tst.gameState());
}

TEST(PiezasTest, gamestate_o)
{
	Piezas tst;
	tst.dropPiece(0);
	tst.dropPiece(0);
	tst.dropPiece(0);
	tst.dropPiece(1);
	tst.dropPiece(2);
	tst.dropPiece(1);
	tst.dropPiece(3);
	tst.dropPiece(2);
	tst.dropPiece(1);
	tst.dropPiece(3);
	tst.dropPiece(2);
	tst.dropPiece(3);
	ASSERT_EQ(X, tst.gameState());
}

TEST(PiezasTest, reset)
{
	Piezas tst;
	tst.dropPiece(0);
	tst.dropPiece(0);
	tst.dropPiece(0);
	tst.reset();
	ASSERT_EQ(Blank, tst.pieceAt(0,0));
}
