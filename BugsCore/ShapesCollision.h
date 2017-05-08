#pragma once
#include "Circle.h"
#include "BoundingBox.h"

namespace Bugs
{
	inline bool isCollision(const Circle& circle, const BoundingBox& Box)
	{
		return true;
	}
	
	template<typename A, typename B> bool IsCollision(const A& a, const B& b)
	{
		return isCollision(a, b);
	}
}