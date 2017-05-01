#include "SFMLInputRenderer.h"
#include <memory>

SFMLInputRenderer::SFMLInputRenderer() : posX(400), posY(300)
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
	myTexture.loadFromFile("C:/Projekty/Pictures/animal.png");
	sf::Sprite sprite;
	sprite.setPosition(posX, posY);
	if (this->IsKeyPressed('a'))
	{
		posX -= 10;
	}
	else if (this->IsKeyPressed('d'))
	{
		posX += 10;
	}
	else if (this->IsKeyPressed('w'))
	{
		posY -= 10;
	}
	else if (this->IsKeyPressed('s'))
	{
		posY += 20;
	}

	sprite.setTexture(myTexture);

	window_->draw(sprite);
	window_->display();
}