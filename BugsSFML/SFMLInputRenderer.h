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
	bool LoadTexture(const std::string& fileName, const std::string& id) override;
	void UnLoadTexture(const std::string& id) override;
	void RenderTexture(const std::string& id, float x, float y) override;

	bool IsKeyPressed(char key) override;

private:
	std::unique_ptr<sf::RenderWindow> window_;
	std::map<std::string, sf::Texture> textures_;
};

