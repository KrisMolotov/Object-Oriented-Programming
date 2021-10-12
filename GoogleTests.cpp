#include "gtest\gtest.h"
#include "../lib/src/ChainLine.h"
using namespace Lab2;
#include <tchar.h>
TEST(Chain_Line_Constructor, Default_Constructor)
{
    Chain c1;
    ASSERT_EQ(1, c1.getX());
    ASSERT_EQ(1, c1.getA());
}

TEST(Chain_Line_Constructor, Init_Constructor)
{
    Chain c2(3);
    ASSERT_EQ(3, c2.getX());
    ASSERT_EQ(1, c2.getA());

    Chain c3(5, 7);
    ASSERT_EQ(7, c3.getX());
    ASSERT_EQ(5, c3.getA());
}

TEST(Chain_Line_Constructor, Test_Exception)
{
    ASSERT_ANY_THROW(Chain(0, 5));
    ASSERT_ANY_THROW(Chain(-1, 5));
}

TEST(Chain_Line_Methods, Setters)
{
    Chain c3;
    c3.setA(1);
    ASSERT_EQ(1, c3.getA());
    ASSERT_ANY_THROW(c3.setA(0));
    ASSERT_ANY_THROW(c3.setA(-1));

    c3.setX(1);
    ASSERT_EQ(1, c3.getX());

    c3.setAX(1, 1);
    ASSERT_EQ(1, c3.getA());
    ASSERT_EQ(1, c3.getX());
    ASSERT_ANY_THROW(c3.setAX(0, 1));
    ASSERT_ANY_THROW(c3.setAX(-1, 1));
}

TEST(Chain_Line_Methods, Parameters)
{
    Chain c4;
    const double err = 0.00001;
    ASSERT_NEAR(1.54308, c4.ordinate(), err);
    ASSERT_NEAR(1.17520, c4.ArcLength(), err);
    ASSERT_NEAR(2.38109, c4.RCurvature(), err);
    ASSERT_NEAR(0.54308, c4.CoordinatesOfCenter(), err);
    ASSERT_EQ(0, c4.Square(1, 1));

    Lab2::Chain c5(2, 3);
    ASSERT_EQ(2*cosh(3.0/2), c5.ordinate());
    ASSERT_EQ(2*sinh(3.0/2), c5.ArcLength());
    ASSERT_EQ(2* pow(cosh(3.0/2), 2), c5.RCurvature());
    ASSERT_EQ(4*(sinh(9.0/2) - sinh(5.0/2)), c5.Square(5, 9));
    ASSERT_EQ(2*(cosh(3.0/2) - 1), c5.CoordinatesOfCenter());
}

int _tmain(int argc, _TCHAR* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

