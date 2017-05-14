#pragma once
#include "Circle.h"
#include "BoundingBox.h"

namespace Bugs
{
	inline bool IsContaining(const Circle& circle, const BoundingBox& box)
	{
		auto distance = circle.GetPosition() - box.GetPosition();

		return std::abs(distance.GetX()) + (box.GetHalves()[0] * box.GetHalves()[0] + box.GetHalves()[1] * box.GetHalves()[1]) <= circle.GetRadius()
			& std::abs(distance.GetY()) + (box.GetHalves()[0] * box.GetHalves()[0] + box.GetHalves()[1] * box.GetHalves()[1]) <= circle.GetRadius();
	}

	inline bool IsContaining(const BoundingBox& box, const Circle& circle)
	{
		auto distance = circle.GetPosition() - box.GetPosition();

		return
			(std::abs(distance.GetX() + circle.GetRadius() <= box.GetHalves()[0]))
			& (std::abs(distance.GetY()) + circle.GetRadius() <= box.GetHalves()[1]);
	}
}
