#include "gtest/gtest.h"
#include "../BugsCore/ShapesCollision.h"

using namespace Bugs;

TEST(ShapesCollisionTests, isCollisionBoxCircleTrue)
{
	BoundingBox box(Vector2(0, 0), Vector2(3, 3));
	Circle circle(Vector2(4, 4), 3);

	EXPECT_TRUE(isCollision(circle, box));
}