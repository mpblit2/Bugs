#pragma once
#include<string>

namespace Bugs
{
	struct IInputRenderer
	{
		virtual ~IInputRenderer() = default;
		virtual void Init() = 0;
		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;
		virtual void Shutdown() = 0;
		virtual bool LoadTexture(const std::string& fileName, const std::string& id) = 0;
		virtual void UnLoadTexture(const std::string& id) = 0;
		virtual void RenderTexture(const std::string& id, float x, float y) = 0;

		virtual bool IsKeyPressed(char key) = 0;
	};
}
