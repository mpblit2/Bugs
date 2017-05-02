#pragma once
#include <string>

namespace Bugs
{
	class Bug
	{
	public:
		Bug(std::string textureId, float positionX, float positionY);
		~Bug();

		const std::string& GetTextureID() const
		{
			return this->textureId_;
		}

		float GetX() const
		{
			return this->positionX_;
		}

		float GetY() const
		{
			return this->positionY_;
		}

		void MoveLeft();
		void MoveRight();

	private:
		std::string textureId_;
		float positionX_;
		float positionY_;
	};
}