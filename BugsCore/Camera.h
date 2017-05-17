#pragma once
#include "BoundingBox.h"

namespace Bugs
{
	class Camera
	{
	public:
		Camera(const float width, const float height, const Vector2& position)
			: width_(width), height_(height), box_(position, Vector2(width/2, height/2))
		{}

		~Camera()
		{}

		void Scale(const Vector2& ratio)
		{
			box_.SetWidth(width_ * ratio[0]);
			box_.SetHeight(height_ * ratio[1]);
			//box_.Scale(ratio[0] / ratio[1]);
			//box_.SetHeight(box_.GetHalves()[1] * 2 * ratio[0]);
			//box_.SetHeight(box_.GetHalves()[0] * 2 * ratio[1]);
			//box_.SetWidth(box_.GetHalves()[0] * 2 * ratio[1]);
			//box_.SetWidth(box_.GetHalves()[1] * 2 * ratio[0]);

			//box_.Scale(ratio[1] / ratio[0]);
		}

		float GetWidth() const
		{
			return box_.GetHalves()[0] * 2;
		}

		float GetHeight() const
		{
			return box_.GetHalves()[1] * 2;
		}

	private:
		BoundingBox box_;
		float width_;
		float height_;
	};
}
