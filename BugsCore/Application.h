#pragma once

namespace Bugs
{
	struct IInputRenderer;

	class Application
	{
	public:
		Application(IInputRenderer& inputRenderer)
			: inputRenderer_(inputRenderer)
		{}

		~Application();

		int Run();
	
	private:
		IInputRenderer& inputRenderer_;
	};

}

