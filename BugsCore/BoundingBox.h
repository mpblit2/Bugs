#pragma once
#include "Vector2.h"

/* TODO:
	- Napisa� metod� sprawdzaj�c� kolizj� dw�ch box�w,
	- Napisa� metod� sprawdzaj�c� czy jeden box zawiera drugi box,
		(box zawiera inny box w�wczas kiedy zawiera go w ca�o�ci).

		Powy�sze funkcje zrobi� w osobnym nag��wku
	- Te same metody zastosowa� dla klasy Circle,

	- Do boxa doda� metody ustawiaj�ce wysoko�� i szeroko��,
		- metoda skalowania,
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

	private:
		Vector2 position_;
		Vector2 halves_;
	};
}