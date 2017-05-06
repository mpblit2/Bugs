#pragma once
#include "Vector2.h"

namespace Bugs
{
	class Rectangle
	{
	public:
		Rectangle(const Vector2& position = Vector2(0, 0), float a = 1.0f, float b = 1.0f) : position_(position), a_(a), b_(b)
		{}

		~Rectangle()
		{}

		const Vector2& GetPosition() const
		{
			return position_;
		}

		float GetA()
		{
			return a_;
		}

		float GetB()
		{
			return b_;
		}

	private:
		Vector2 position_;
		float a_;
		float b_;
	};
}
