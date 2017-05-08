#pragma once
#include<cmath>
#include "Vector2.h"

/* TODO:
	+ Napisaæ metodê sprawdzaj¹c¹ kolizjê dwóch boxów,
	+ Napisaæ metodê sprawdzaj¹c¹ czy jeden box zawiera drugi box,
		(box zawiera inny box wówczas kiedy zawiera go w ca³oœci).

		Powy¿sze funkcje zrobiæ w osobnym nag³ówku
	- Te same metody zastosowaæ dla klasy Circle,

	+ Do boxa dodaæ metody ustawiaj¹ce wysokoœæ i szerokoœæ,
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