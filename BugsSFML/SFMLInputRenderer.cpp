#include "SFMLInputRenderer.h"
#include <memory>


SFMLInputRenderer::SFMLInputRenderer()
{
}

SFMLInputRenderer::~SFMLInputRenderer()
{
}

void SFMLInputRenderer::Shutdown()
{
}

bool SFMLInputRenderer::IsKeyPressed(char key)
{
	auto sfKey = static_cast<sf::Keyboard::Key>(key - 'a');
	return sf::Keyboard::isKeyPressed(sfKey);
}

void SFMLInputRenderer::Init()
{
	window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "BugsSFML");
	window_->setFramerateLimit(60);
}

void SFMLInputRenderer::BeginFrame()
{
	window_->clear(sf::Color::Black);
}

void SFMLInputRenderer::EndFrame()
{
	sf::Texture myTexture;
	myTexture.loadFromFile("C:/Projekty/Pictures/worm.png");
	sf::Sprite sprite;
	sprite.setTexture(myTexture);

	window_->draw(sprite);
	window_->display();
}