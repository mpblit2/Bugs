#pragma once
#include "Vector2.h"

/* TODO:
	-
*/

namespace Bugs
{
	class Circle
	{
	public:
		Circle(const Vector2& position, float radius) : position_(position) ,radius_(radius)
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