#pragma once

namespace Bugs
{
	struct IRenderer
	{
		virtual ~IRenderer() = default;
		virtual void Init() = 0;
		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;
		virtual void Shutdown() = 0;
	};
}