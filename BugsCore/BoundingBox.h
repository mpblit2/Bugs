#pragma once
#include<cmath>
#include "Vector2.h"

/* TODO:
	+ Napisa� metod� sprawdzaj�c� kolizj� dw�ch box�w,
	+ Napisa� metod� sprawdzaj�c� czy jeden box zawiera drugi box,
		(box zawiera inny box w�wczas kiedy zawiera go w ca�o�ci).

		Powy�sze funkcje zrobi� w osobnym nag��wku
	- Te same metody zastosowa� dla klasy Circle,

	+ Do boxa doda� metody ustawiaj�ce wysoko�� i szeroko��,
		+ metoda skalowania,
*/

namespace Bugs
{
	class BoundingBox
	{
	public:
		BoundingBox(const Vector2& position, const Vector2& halves) : position_(position), halves_(halves)
		{}

		~BoundingBox()
		{}

		const Vector2& GetPosition() const
		{
			return position_;
		}

		const Vector2& GetHalves() const
		{
			return halves_;
		}

		void SetHeight(float height)
		{
			halves_[1] = height / 2;
		}

		void SetWidth(float width)
		{
			halves_[0] = width / 2;
		}

		void Scale(float scale)
		{
			halves_ *= scale;
		}

		bool IsCollision(const BoundingBox& box) const
		{
			//distance - length between two center positions of boxes
			auto distance = this->position_ - box.position_;
			auto halvesSum = this->halves_ + box.halves_;

			return
				(std::abs(distance.GetX()) <= halvesSum.GetX())
				& (std::abs(distance.GetY()) <= halvesSum.GetY());
		}

		bool IsContaining(const BoundingBox& box) const
		{
			//distance - length between two center positions of boxes
			auto distance = this->position_ - box.position_;
			auto halvesDiff = this->halves_ - box.halves_;

			return
				(std::abs(distance.GetX()) <= halvesDiff.GetX())
				& (std::abs(distance.GetY()) <= halvesDiff.GetY());
		}

	private:
		Vector2 position_;
		Vector2 halves_;
	};
}