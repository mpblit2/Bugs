#pragma once
#include "Vector2.h"

/* TODO:
	- Napisaæ metodê sprawdzaj¹c¹ kolizjê dwóch boxów,
	- Napisaæ metodê sprawdzaj¹c¹ czy jeden box zawiera drugi box,
		(box zawiera inny box wówczas kiedy zawiera go w ca³oœci).

		Powy¿sze funkcje zrobiæ w osobnym nag³ówku
	- Te same metody zastosowaæ dla klasy Circle,

	- Do boxa dodaæ metody ustawiaj¹ce wysokoœæ i szerokoœæ,
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