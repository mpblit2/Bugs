#include "stdafx.h"
#include <iostream>
#include <memory>
#include <vector>
#include "Application.h"
#include "IInputRenderer.h"
#include "Camera.h"
#include "../BugsCore/Circle.h"

using namespace Bugs;

Application::~Application()
{
}

int Bugs::Application::Run()
{	
	/*
	Camera camera(200.0f, 200.0f, Vector2(400, 300));
	*/

	BoundingBox myBox = BoundingBox(Vector2(100.0f, 100.0f), Vector2(50.0f, 100.0f));
	Circle myCircle = Circle(Vector2(300.0f, 100.0f), 25.0f);

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

		/*
		auto ratio = inputRenderer_.GetHightWidthRetio();


		if (ratio)
		{
			
			std::cout << "Ratio: " << (*ratio).GetX() << ", " << (*ratio).GetY() << std::endl;
			std::cout << "Befor: " << camera.GetWidth() << "x" << camera.GetHeight() << std::endl;
		
			camera.Scale(*ratio);

			
			std::cout << "After: " << camera.GetWidth() << "x" << camera.GetHeight() << std::endl;
		
		}
		//std::cout << "After: " << camera.GetWidth() << "x" << camera.GetHeight() << std::endl;
		//inputRenderer_.DrawCamera(camera.GetWidth(), camera.GetHeight(), camera.GetPosition());
		*/
		inputRenderer_.Render(myBox);
		inputRenderer_.Render(myCircle);

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