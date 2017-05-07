#include "gtest/gtest.h"
#include "../BugsCore/Circle.h"

using namespace Bugs;

TEST(CircleTests, defaultConstructorTest)
{
	Circle circle = Circle();

	EXPECT_EQ(circle.GetPosition(), Vector2(0, 0));
	EXPECT_FLOAT_EQ(circle.GetRadius(), 1.0f);
}