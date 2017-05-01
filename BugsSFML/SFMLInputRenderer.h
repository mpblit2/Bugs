#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "../BugsCore/IInputRenderer.h"

class SFMLInputRenderer : public Bugs::IInputRenderer
{
public:
	SFMLInputRenderer();
	virtual ~SFMLInputRenderer();
	void Init() override;
	void BeginFrame() override;
	void EndFrame() override;
	void Shutdown() override;

	bool IsKeyPressed(char key) override;

private:
	std::unique_ptr<sf::RenderWindow> window_;

};

