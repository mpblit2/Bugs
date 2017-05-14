#include "gtest/gtest.h"
#include "../BugsCore/ShapesContaining.h"

using namespace Bugs;

TEST(ShapesContainingTests, circleIsContainingBoxTrue)
{
	BoundingBox box(Vector2(0, 0), Vector2(1, 1));
	Circle circle(Vector2(0, 0), 5);

	EXPECT_TRUE(IsContaining(circle, box));
}

TEST(ShapesContainingTests, circleIsContainingBoxFalse)
{
	BoundingBox box(Vector2(5, 0), Vector2(1, 1));
	Circle circle(Vector2(0, 0), 5);

	EXPECT_FALSE(IsContaining(circle, box));
}

TEST(ShapesContainingTests, boxIsContainingCircleTrue)
{
	BoundingBox box(Vector2(0, 0), Vector2(5, 5));
	Circle circle(Vector2(0, 0), 1);

	EXPECT_TRUE(IsContaining(box, circle));
}

TEST(ShapesContainingTests, boxIsContainingCircleFalse)
{
	BoundingBox box(Vector2(0, 0), Vector2(5, 5));
	Circle circle(Vector2(5, 7), 1);

	EXPECT_FALSE(IsContaining(box, circle));
}