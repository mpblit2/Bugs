#pragma once
#include <SFML/Graphics.hpp>
#include "../BugsCore/IRenderer.h"
#include <memory>

class SFMLRenderer : public Bugs::IRenderer
{
public:
	SFMLRenderer();
	~SFMLRenderer() override;
	void Init() override;
	void BeginFrame() override;
	void EndFrame() override;
	void Shutdown() override;

private:
	std::unique_ptr<sf::RenderWindow> window_;
};

