#pragma once
#include <string>
#include "Vector2.h"

namespace Bugs
{
	class Bug
	{
	public:
		Bug(std::string textureId, float positionX, float positionY);
		Bug(std::string textureId, const Vector2& position);
		~Bug();

		const std::string& GetTextureID() const
		{
			return this->textureId_;
		}

		//Tu zwracamy sta³¹ referencjê bo nie chcemy ¿eby ta wartoœæ by³a zmieniana poza klas¹.
		const Vector2& GetPosition() const
		{
			return  this->position_;
		}

		void MoveLeft();
		void MoveRight();

	private:
		std::string textureId_;
		Vector2 position_;
	};
}