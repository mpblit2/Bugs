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

		void Scale(float scale)
		{
			radius_ *= scale;
		}

		bool IsCollision(const Circle& circle) const
		{
			//distance - length between two center positions of circle
			auto distance = this->position_ - circle.position_;
			auto radiusSum = this->radius_ + circle.radius_;

			return (std::abs(distance.GetX()) <= radiusSum)
				& (std::abs(distance.GetY()) <= radiusSum);
		}

		bool IsContaining(const Circle& circle) const
		{
			//distance - length between two center positions of circle
			auto distance = this->position_ - circle.position_;
			auto radiusDiff = this->radius_ - circle.radius_;

			return (std::abs(distance.GetX()) <= radiusDiff)
				& (std::abs(distance.GetY()) <= radiusDiff);
		}

	private:
		float radius_;
		Vector2 position_;
	};
}