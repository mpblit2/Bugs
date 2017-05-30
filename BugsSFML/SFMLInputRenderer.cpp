#include "SFMLInputRenderer.h"
#include <iostream>
#include <memory>
#include "../BugsCore/Vector2.h"
#include "../BugsCore/BoundingBox.h"
#include "../BugsCore/Circle.h"
#include "../BugsCore/Camera.h"

using namespace Bugs;

SFMLInputRenderer::SFMLInputRenderer()
{
}

SFMLInputRenderer::~SFMLInputRenderer()
{
}

void SFMLInputRenderer::Shutdown()
{
	//window_->close();
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

void SFMLInputRenderer::Render(const BoundingBox & box)
{
	sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(Convert(box.GetHalves()[0] * 2), Convert(box.GetHalves()[1] * 2)));
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(1);
	rectangle.setPosition(Convert(box.GetPosition()));

	window_->draw(rectangle);
}

void SFMLInputRenderer::Render(const Circle & circle)
{
	sf::CircleShape sfCircle = sf::CircleShape(Convert(circle.GetRadius()));
	sfCircle.setOutlineColor(sf::Color::Blue);
	sfCircle.setOutlineThickness(1);
	sfCircle.setPosition(Convert(circle.GetPosition()));

	window_->draw(sfCircle);
}

void SFMLInputRenderer::SetKeyMap(const Bugs::KeyMap & keyMap)
{
	for (auto& data : keyMap)
	{
		keyMap_[ConvertKey(data.first)] = data.second;
	}
}

void SFMLInputRenderer::ProcessKeys()
{
	for (auto& data : keyMap_)
	{
		
		if (sf::Keyboard::isKeyPressed(data.first))
		{
			data.second();
		}
	}
}

sf::Vector2f SFMLInputRenderer::Convert(const Bugs::Vector2 & vector) const
{
	Bugs::Vector2 result = a_ * (vector - b_);
	return sf::Vector2f(result.GetX(), result.GetY());
}

float SFMLInputRenderer::Convert(float length) const
{
	return a_.GetX() * length;
}

sf::Keyboard::Key SFMLInputRenderer::ConvertKey(Bugs::KeyCode key) const
{
	static const std::map < KeyCode, sf::Keyboard::Key> keyConversion = {
		{Bugs::KeyCode::ArrowUp, sf::Keyboard::Key::Up}, 
		{Bugs::KeyCode::ArrowDown, sf::Keyboard::Key::Down},
		{Bugs::KeyCode::ArrowLeft, sf::Keyboard::Key::Left},
		{Bugs::KeyCode::ArrowRight, sf::Keyboard::Key::Right},
		{Bugs::KeyCode::I, sf::Keyboard::Key::I},
		{Bugs::KeyCode::O, sf::Keyboard::Key::O}
	};

	auto it = keyConversion.find(key);

	return it->second;
}

void SFMLInputRenderer::Init()
{
	window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "BugsSFML");
	window_->setFramerateLimit(60);
}

void SFMLInputRenderer::BeginFrame(const Camera& camera)
{
	sf::Event event;

	auto actualVectorSize = sf::Vector2u();
	auto newVectorSize = sf::Vector2u();
	
	actualVectorSize = window_->getSize();
	
	heightWidthRetio_ = std::nullopt;

	while (window_->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window_->close();
			}
		}
		else if (event.type == sf::Event::Closed)
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
	//b - vector przesuniêcia
	b_ = Vector2(camera.GetPosition()[0] - camera.GetWidth()/2, camera.GetPosition()[1] + camera.GetHeight()/2);
	
	//a - vector skalowania
	a_ = Vector2(window_->getSize().x / camera.GetWidth() , - (window_->getSize().y / camera.GetHeight()));
}

void SFMLInputRenderer::EndFrame()
{
	window_->setActive();
	window_->display();
}