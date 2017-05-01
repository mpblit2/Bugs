#pragma once

namespace Bugs
{
	struct IInputRenderer
	{
		virtual ~IInputRenderer() = default;
		virtual void Init() = 0;
		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;
		virtual void Shutdown() = 0;

		virtual bool IsKeyPressed(char key) = 0;
	};
}
