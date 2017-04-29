#include "stdafx.h"
#include "Application.h"
#include "IRenderer.h"
#include "IInput.h"

using namespace Bugs;

Application::~Application()
{
}

int Bugs::Application::Run()
{
	renderer_.Init();
	input_.Init();

	while (true)
	{
		renderer_.BeginFrame();
		renderer_.EndFrame();

		if (input_.IsKeyPressed('q'))
		{
			break;
		}
	}

	renderer_.Shutdown();
	input_.Shutdown();

	return 0;
}
