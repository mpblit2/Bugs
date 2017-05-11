#pragma once
#include "Circle.h"
#include "BoundingBox.h"

namespace Bugs
{
	inline bool isCollision(const Circle& circle, const BoundingBox& box)
	{
		auto distance = circle.GetPosition() - box.GetPosition();
		auto boxXandRadiusSum = box.GetHalves()[0] + circle.GetRadius();
		auto boxYandRadiusSum = box.GetHalves()[1] + circle.GetRadius();

		return ((std::abs(distance.GetX()) <= boxXandRadiusSum)
			| (std::abs(distance.GetY()) <= boxYandRadiusSum))
			& 
			((std::abs(distance.GetX() <= box.GetHalves()[0]) 
			| (std::abs(distance.GetY() <= box.GetHalves()[1]))));
/*
			& ((std::abs(distance.GetY()) <= box.GetHalves()[1]) 
			| (std::abs(distance.GetX()) <= box.GetHalves()[0]));
	*/}
	
	template<typename A, typename B> bool IsCollision(const A& a, const B& b)
	{
		return isCollision(a, b);
	}
}