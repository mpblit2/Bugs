#pragma once

namespace Bugs
{
	struct IInput
	{
		virtual ~IInput() = default;
		virtual void Init() = 0;
		virtual bool IsKeyPressed(char key) const = 0;
		virtual void Shutdown() = 0;
	};
}