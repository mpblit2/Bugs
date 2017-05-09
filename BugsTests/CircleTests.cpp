#include "gtest/gtest.h"
#include "../BugsCore/Circle.h"

using namespace Bugs;

TEST(CircleTests, constructorTest)
{
	Circle circle(Vector2(1, 2), 4);

	EXPECT_EQ(circle.GetPosition(), Vector2(1, 2));
	EXPECT_EQ(circle.GetRadius(), 4);
}

TEST(CircleTests, isContaingingMethodTestIsFalse)
{
	Circle circle1(Vector2(1, 1), 2);
	Circle circle2(Vector2(1, 2), 2);

	EXPECT_FALSE(circle1.IsContaining(circle2));
}

TEST(CircleTests, isContainingMethodTestIsTrue)
{
	Circle circle1(Vector2(1, 1), 4);
	Circle circle2(Vector2(1, 1), 2);

	EXPECT_TRUE(circle1.IsContaining(circle2));
}

TEST(CircleTests, isCollisionMethodTestIsFalse)
{
	Circle circle1(Vector2(1, 1), 2);
	Circle circle2(Vector2(10, 1), 2);

	EXPECT_FALSE(circle1.IsCollision(circle2));
}

TEST(CircleTests, isCollisionMethodTestIsTrue)
{
	Circle circle1(Vector2(1, 1), 2);
	Circle circle2(Vector2(4, 2), 2);

	EXPECT_TRUE(circle1.IsCollision(circle2));
}