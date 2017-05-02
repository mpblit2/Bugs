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
	Bug myBug("default", 400, 300);
	inputRenderer_.LoadTexture("C:\\Projekty\\Pictures\\animal.png", "default");

	while (true)
	{
		inputRenderer_.BeginFrame();
		inputRenderer_.RenderTexture(myBug.GetTextureID(), myBug.GetX(), myBug.GetY());
		inputRenderer_.EndFrame();

		if (inputRenderer_.IsKeyPressed('a'))
		{
			myBug.MoveLeft();
		}

		if (inputRenderer_.IsKeyPressed('d'))
		{
			myBug.MoveRight();
		}

		if (inputRenderer_.IsKeyPressed('q'))
		{
			break;
		}
	}

	inputRenderer_.Shutdown();

	return 0;
}
