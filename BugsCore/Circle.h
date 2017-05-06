#pragma once
#include "Vector2.h"

namespace Bugs
{
	class Circle
	{
	public:
		Circle(const Vector2& position = Vector2(0, 0), float radius = 1.0f) : position_(position) ,radius_(radius)
		{}

		~Circle()
		{}

		float GetRadius() const
		{
			return radius_;
		}

		const Vector2& GetPosition() const
		{
			return position_;
		}

	private:
		float radius_;
		Vector2 position_;
	};
}