#pragma once
#include "Circle.h"
#include "BoundingBox.h"

namespace Bugs
{
	inline bool IsCollision(const Circle& circle, const BoundingBox& box)
	{
		auto distance = circle.GetPosition() - box.GetPosition();

		auto absoluteDistance = Vector2(std::abs(distance.GetX()), std::abs(distance.GetY()));
		auto distanceHalvesDiff = absoluteDistance - box.GetHalves();
		auto circleRadiusSquare = circle.GetRadius() * circle.GetRadius();

		return distanceHalvesDiff.GetX() <= circle.GetRadius()
			&
			distanceHalvesDiff.GetY() <= circle.GetRadius()
			&
			(distanceHalvesDiff.GetX() * distanceHalvesDiff.GetX())
			+
			(distanceHalvesDiff.GetY() * distanceHalvesDiff.GetY()) <= circleRadiusSquare;
	}

	template<typename A, typename B> bool IsCollision(const A& a, const B& b)
	{
		return IsCollision(b, a);
	}
}