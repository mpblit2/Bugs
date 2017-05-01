#include "stdafx.h"
#include "Application.h"
#include "IInputRenderer.h"

using namespace Bugs;

Application::~Application()
{
}

int Bugs::Application::Run()
{
	inputRenderer_.Init();

	while (true)
	{
		inputRenderer_.BeginFrame();
		inputRenderer_.EndFrame();

		if (inputRenderer_.IsKeyPressed('d'))
		{

		}

		if (inputRenderer_.IsKeyPressed('q'))
		{
			break;
		}
	}

	inputRenderer_.Shutdown();

	return 0;
}
