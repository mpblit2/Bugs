#pragma once

#include <optional>
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

	void BeginFrame(const Bugs::Camera& camera) override;
	void EndFrame() override;
	bool LoadTexture(const std::string& fileName, const std::string& id) override;
	void UnLoadTexture(const std::string& id) override;
	void RenderTexture(const std::string& id, const Bugs::Vector2& position) override;
	std::optional<Bugs::Vector2> GetHightWidthRetio() const override;
	void Render(const Bugs::BoundingBox& box) override;
	void Render(const Bugs::Circle& circle) override;

	bool IsKeyPressed(char key) override;

	void DrawCamera(float width, float height, const Bugs::Vector2& position) override;

private:
	sf::Vector2f Convert(const Bugs::Vector2& vector) const;
	float Convert(float length) const;

	std::unique_ptr<sf::RenderWindow> window_;
	std::map<std::string, sf::Texture> textures_;
	std::optional<Bugs::Vector2> heightWidthRetio_;
	Bugs::Vector2 a_, b_;
};

