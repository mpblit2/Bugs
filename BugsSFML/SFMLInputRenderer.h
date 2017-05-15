#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "../BugsCore/IInputRenderer.h"
#include "../BugsCore/Vector2.h"

class SFMLInputRenderer : public Bugs::IInputRenderer
{
public:
	SFMLInputRenderer();
	virtual ~SFMLInputRenderer();
	
	void Init() override;
	void Shutdown() override;
	virtual bool IsWindowOpen();

	void BeginFrame() override;
	void EndFrame() override;
	bool LoadTexture(const std::string& fileName, const std::string& id) override;
	void UnLoadTexture(const std::string& id) override;
	void RenderTexture(const std::string& id, const Bugs::Vector2& position) override;
	Bugs::Vector2 GetHightWidthRetio() const override;

	bool IsKeyPressed(char key) override;

private:
	std::unique_ptr<sf::RenderWindow> window_;
	std::map<std::string, sf::Texture> textures_;
	Bugs::Vector2 heightWidthRetio_;
};

