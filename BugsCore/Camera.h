#pragma once
#include "BoundingBox.h"

namespace Bugs
{
	class Camera
	{
	public:
		Camera(const float width, const float height, const Vector2& position)
			: box_(position, Vector2(width/2, height/2))
		{}

		~Camera()
		{}

		void Scale(const Vector2& ratio)
		{
			if (ratio[0] != 1)
			{
				box_.SetWidth(box_.GetHalves()[0] * 2 * ratio[0]);
				box_.SetHeight(box_.GetHalves()[1] * 2 * ratio[0]);
			}

			if (ratio[1] != 1)
			{
				box_.SetWidth(box_.GetHalves()[0] * 2 * ratio[1]);
				box_.SetHeight(box_.GetHalves()[1] * 2 * ratio[1]);
			}
		}

		float GetWidth() const
		{
			return box_.GetHalves()[0] * 2;
		}

		float GetHeight() const
		{
			return box_.GetHalves()[1] * 2;
		}

		Vector2 GetPosition() const
		{
			return box_.GetPosition();
		}

		void ZoomIn()
		{
			auto halves = box_.GetHalves();

			halves *= 0.99;

			box_.SetHalves(halves);
		}

		void ZoomOut()
		{
			auto halves = box_.GetHalves();

			halves *= 1.01;

			box_.SetHalves(halves);
		}

		void MoveLeft()
		{
			auto position = box_.GetPosition();

			position[0] -= 1.5;

			box_.SetPosition(position);
		}


		void MoveRight()
		{
			auto position = box_.GetPosition();

			position[0] += 1.5;

			box_.SetPosition(position);
		}

		void MoveUp()
		{
			auto position = box_.GetPosition();

			position[1] += 1.5;

			box_.SetPosition(position);
		}

		void MoveDown()
		{
			auto position = box_.GetPosition();

			position[1] -= 1.5;

			box_.SetPosition(position);
		}

	private:
		BoundingBox box_;
	};
}
