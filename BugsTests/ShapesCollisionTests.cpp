#include "gtest/gtest.h"
#include "../BugsCore/ShapesCollision.h"

using namespace Bugs;

TEST(ShapesCollisionTests, isCollisionBoxCircleOnX)
{
	BoundingBox box(Vector2(0.0f, 0.0f), Vector2(3.0f, 3.0f));
	Circle circle(Vector2(3.0f, 4.0f), 1.0f);

	EXPECT_TRUE(IsCollision(circle, box));
}

TEST(ShapesCollisionTests, isCollisionBoxCircleOnY)
{
	BoundingBox box(Vector2(0, 0), Vector2(3, 3));
	Circle circle(Vector2(4, 3), 1);

	EXPECT_TRUE(IsCollision(circle, box));
}

TEST(ShapesCollisionTests, isCollisionBoxCircleInCorner)
{
	BoundingBox box(Vector2(0, 0), Vector2(3, 3));
	Circle circle(Vector2(4, 4), 2);

	EXPECT_TRUE(IsCollision(circle, box));
}

TEST(ShapesCollisionTests, isCollisionBoxCircleOnChangedParameterOrder)
{
	BoundingBox box(Vector2(0, 0), Vector2(3, 3));
	Circle circle(Vector2(4, 4), 2);

	EXPECT_TRUE(IsCollision(box, circle));
}