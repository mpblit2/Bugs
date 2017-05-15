#include "stdafx.h"
#include <memory>
#include <vector>
#include "Application.h"
#include "IInputRenderer.h"

using namespace Bugs;

Application::~Application()
{
}

int Bugs::Application::Run()
{		
	std::vector<std::unique_ptr<Bug>> bugs;
	bugs.emplace_back(std::make_unique<Bug>("default", Vector2(400,300)));
	bugs.emplace_back(std::make_unique<Bug>("default", Vector2(400, 100)));
	bugs.emplace_back(std::make_unique<Bug>("default", Vector2(200, 300)));

	std::size_t currentBugIndex = 0;

	inputRenderer_.Init();
	inputRenderer_.LoadTexture("C:\\Projekty\\Pictures\\animal.png", "default");

	while (inputRenderer_.IsWindowOpen())
	{
		inputRenderer_.BeginFrame();
		for (auto& bug : bugs)
		{
			inputRenderer_.RenderTexture(bug->GetTextureID(), bug->GetPosition());
		}
		
		inputRenderer_.EndFrame();
		auto& currentBug = *bugs[currentBugIndex];
		
		if (inputRenderer_.IsKeyPressed('c'))
		{
			//currentBug = (currentBug + 1) % bugs.size()
			currentBugIndex += 1;

			if (currentBugIndex >= bugs.size())
			{
				currentBugIndex = 0;
			}
		}

		if (inputRenderer_.IsKeyPressed('a'))
		{
			currentBug.MoveLeft();
		}

		if (inputRenderer_.IsKeyPressed('d'))
		{
			currentBug.MoveRight();
		}

		if (inputRenderer_.IsKeyPressed('q'))
		{
			break;
		}

		
	}

	inputRenderer_.Shutdown();

	return 0;
}