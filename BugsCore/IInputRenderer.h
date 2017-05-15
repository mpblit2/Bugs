#pragma once
#include<string>

namespace Bugs
{
	class Vector2;

	struct IInputRenderer
	{
		//Constructors
		virtual ~IInputRenderer() = default;

		//General methodes
		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual bool IsWindowOpen() = 0;

		//Rendering methodes
		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;
		virtual bool LoadTexture(const std::string& fileName, const std::string& id) = 0;
		virtual void UnLoadTexture(const std::string& id) = 0;
		virtual void RenderTexture(const std::string& id, const Vector2& position) = 0;
		virtual Vector2 GetHightWidthRetio() const = 0;

		//Input methodes
		virtual bool IsKeyPressed(char key) = 0;
	};
}