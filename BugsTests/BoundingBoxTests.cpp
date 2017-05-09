#include "gtest\gtest.h"
#include "..\BugsCore\BoundingBox.h"

using namespace Bugs;

TEST(BoundingBoxTests, constructorTest)
{
	BoundingBox box(Vector2(1,2), Vector2(2,4));

	EXPECT_EQ(box.GetPosition(), Vector2(1, 2));
	EXPECT_EQ(box.GetHalves(), Vector2(2, 4));
}

TEST(BoundingBoxTests, isContainingMethodTestIsFalse)
{
	BoundingBox box1(Vector2(1, 1), Vector2(2, 2));
	BoundingBox box2(Vector2(1, 2), Vector2(1, 2));

	EXPECT_FALSE(box1.IsContaining(box2));
}

TEST(BoundingBoxTests, isContainingMethodTestIsTrue)
{
	BoundingBox box1(Vector2(1, 1), Vector2(2, 2));
	BoundingBox box2(Vector2(1, 1), Vector2(1, 1));

	EXPECT_TRUE(box1.IsContaining(box2));
}

TEST(BoundingBoxTests, isCollisionMethodTestIsFalse)
{
	BoundingBox box1(Vector2(1, 1), Vector2(2, 2));
	BoundingBox box2(Vector2(10, 1), Vector2(2, 2));

	EXPECT_FALSE(box1.IsCollision(box2));
}

TEST(BoundingBoxTests, isCollisionMethodTestIsTrue)
{
	BoundingBox box1(Vector2(1, 1), Vector2(2, 2));
	BoundingBox box2(Vector2(4, 2), Vector2(2, 2));

	EXPECT_TRUE(box1.IsCollision(box2));
}