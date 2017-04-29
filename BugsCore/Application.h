#pragma once

namespace Bugs
{
	struct IRenderer;
	struct IInput;

	class Application
	{
	public:
		Application(IRenderer& renderer, IInput& input)
			: renderer_(renderer), input_(input)
		{}

		~Application();

		int Run();
	
	private:
		IRenderer& renderer_;
		IInput& input_;
	};

}

