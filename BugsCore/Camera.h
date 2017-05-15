#pragma once
#include "BoundingBox.h"

namespace Bugs
{
	class Camera
	{
	public:
		Camera(const float width, const float hight, const Vector2& position)
			: box_(position, Vector2(width/2, hight/2))
		{}

		~Camera()
		{}

	private:
		BoundingBox box_;
	};
}
