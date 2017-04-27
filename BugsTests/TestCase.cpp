// unittest_SimpleMath.cpp : Defines the entry point for the console application.

#include "gtest/gtest.h"
//#include <boost/system/config.hpp>


TEST(testMath, myCubeTest)
{
	int grabarz = 1000;
	EXPECT_EQ(1000, grabarz);
}

TEST(testMath, grabarzTest)
{
	int grabarz = 101;
	EXPECT_EQ(101, grabarz);
}