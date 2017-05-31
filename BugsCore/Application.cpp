#include "stdafx.h"
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <functional>
#include "Application.h"
#include "IInputRenderer.h"
#include "Camera.h"
#include "../BugsCore/Circle.h"

using namespace Bugs;

Application::~Application()
{}

int Bugs::Application::Run()
{	
	KeyMap keyMap;
	
	Camera camera(800.0f, 600.0f, Vector2(0, 0));

	//Keys map to operate on Camera object.
	keyMap[KeyCode::I] = [&]() { camera.ZoomIn(); };
	keyMap[KeyCode::O] = [&]() { camera.ZoomOut(); };
	keyMap[KeyCode::ArrowUp] = [&]() { camera.MoveUp(); };
	keyMap[KeyCode::ArrowDown] = [&]() { camera.MoveDown(); };
	keyMap[KeyCode::ArrowLeft] = [&]() { camera.MoveLeft(); };
	keyMap[KeyCode::ArrowRight] = [&]() { camera.MoveRight(); };


	BoundingBox myBox = BoundingBox(Vector2(100.0f, 100.0f), Vector2(50.0f, 100.0f));
	Circle myCircle = Circle(Vector2(300.0f, 100.0f), 25.0f);

	std::vector<std::unique_ptr<Bug>> bugs;
	bugs.emplace_back(std::make_unique<Bug>("default", Vector2(400,300)));
	bugs.emplace_back(std::make_unique<Bug>("default", Vector2(400, 100)));
	bugs.emplace_back(std::make_unique<Bug>("default", Vector2(200, 300)));

	std::size_t currentBugIndex = 0;

	//Keys map to operate on Bugs
	keyMap[KeyCode::C] = [&]() { 
		
		currentBugIndex += 1; 
		
		if (currentBugIndex >= bugs.size())
		{
			currentBugIndex = 0;
		}
	};

	keyMap[KeyCode::A] = [&]() {
		auto& currentBug = *bugs[currentBugIndex]; 
		currentBug.MoveLeft();
	};

	keyMap[KeyCode::D] = [&]() {
		auto& currentBug = *bugs[currentBugIndex];
		currentBug.MoveRight();
	};

	inputRenderer_.Init();
	inputRenderer_.LoadTexture("C:\\Projekty\\Pictures\\animal.png", "default");

	inputRenderer_.SetKeyMap(keyMap);

	while (inputRenderer_.IsWindowOpen())
	{
		inputRenderer_.BeginFrame(camera);
		for (auto& bug : bugs)
		{
			//inputRenderer_.RenderTexture(bug->GetTextureID(), bug->GetPosition());
			inputRenderer_.Render(bug->GetBox());
		}

		inputRenderer_.Render(myBox);
		inputRenderer_.Render(myCircle);

		inputRenderer_.EndFrame();
		auto& currentBug = *bugs[currentBugIndex];

		inputRenderer_.ProcessKeys();
	}

	inputRenderer_.Shutdown();

	return 0;
}