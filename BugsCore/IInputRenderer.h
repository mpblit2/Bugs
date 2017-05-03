#pragma once
#include<string>

namespace Bugs
{
	class Vector2;

	struct IInputRenderer
	{
		virtual ~IInputRenderer() = default;
		virtual void Init() = 0;
		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;
		virtual void Shutdown() = 0;
		virtual bool LoadTexture(const std::string& fileName, const std::string& id) = 0;
		virtual void UnLoadTexture(const std::string& id) = 0;
		virtual void RenderTexture(const std::string& id, const Vector2& position) = 0;

		virtual bool IsKeyPressed(char key) = 0;
	};
}