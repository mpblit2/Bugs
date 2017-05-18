#include "SFMLInputRenderer.h"
#include <iostream>
#include <memory>
#include "../BugsCore/Vector2.h"

using namespace Bugs;

SFMLInputRenderer::SFMLInputRenderer()
{
}

SFMLInputRenderer::~SFMLInputRenderer()
{
}

void SFMLInputRenderer::Shutdown()
{
}

bool SFMLInputRenderer::IsWindowOpen()
{
	return window_->isOpen();
}

bool SFMLInputRenderer::LoadTexture(const std::string & fileName, const std::string & id)
{
	//TODO: Here can be an error in sytutaion when whe have wrong fileName or path
	//Write code to predict this
	auto& texture = textures_[id];
	texture.loadFromFile(fileName);

	return true;
}

void SFMLInputRenderer::UnLoadTexture(const std::string & id)
{
	textures_.erase(id);
}

void SFMLInputRenderer::RenderTexture(const std::string & id, const Bugs::Vector2& position)
{
	auto it = textures_.find(id);
	if (it != textures_.end())
	{
		auto& texture = it->second;
		sf::Sprite sprite;
		sprite.setPosition(position.GetX(), position.GetY());
		sprite.setTexture(texture);
		window_->draw(sprite);
	}
}

std::optional<Vector2> SFMLInputRenderer::GetHightWidthRetio() const
{
	return heightWidthRetio_;
}

bool SFMLInputRenderer::IsKeyPressed(char key)
{
	auto sfKey = static_cast<sf::Keyboard::Key>(key - 'a');
	return sf::Keyboard::isKeyPressed(sfKey);
}

void SFMLInputRenderer::DrawCamera(float width, float height, const Bugs::Vector2& position)
{
	sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(width, height));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(1);
	rectangle.setPosition(position.GetX(), position.GetY());

	window_->draw(rectangle);
}

void SFMLInputRenderer::Init()
{
	window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "BugsSFML");
	window_->setFramerateLimit(60);
}

void SFMLInputRenderer::BeginFrame()
{
	sf::Event event;

	auto actualVectorSize = sf::Vector2u();
	auto newVectorSize = sf::Vector2u();
	
	actualVectorSize = window_->getSize();
	
	heightWidthRetio_ = std::nullopt;

	while (window_->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window_->close();
		}
		else if(event.type == sf::Event::Resized)
		{
			heightWidthRetio_ = Vector2(static_cast<float>(event.size.width) / static_cast<float>(actualVectorSize.x),
				static_cast<float>(event.size.height) / static_cast<float>(actualVectorSize.y));
		}
	}
	
	window_->clear(sf::Color::Black);
}

void SFMLInputRenderer::EndFrame()
{
	window_->setActive();
	window_->display();
}