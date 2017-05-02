#include "SFMLInputRenderer.h"
#include <memory>
//#include "Bug.h"

SFMLInputRenderer::SFMLInputRenderer() : posX(400), posY(300)
{
}

SFMLInputRenderer::~SFMLInputRenderer()
{
}

void SFMLInputRenderer::Shutdown()
{
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

void SFMLInputRenderer::RenderTexture(const std::string & id, float x, float y)
{
	auto it = textures_.find(id);
	if (it != textures_.end())
	{
		auto& texture = it->second;
		sf::Sprite sprite;
		sprite.setPosition(x, y);
		sprite.setTexture(texture);
		window_->draw(sprite);
	}
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
	/*sf::Texture* myTexture = new sf::Texture();
	myTexture->loadFromFile("C:/Projekty/Pictures/animal.png");
	sf::Sprite sprite;
	sprite.setPosition(this->posX, this->posY);
	sprite.setTexture(*myTexture);
	
	if (this->IsKeyPressed('a'))
	{
		this->posX -= 10;
	}
	else if (this->IsKeyPressed('d'))
	{
		this->posX += 10;
	}

	window_->draw(sprite);
	*/


	window_->display();
}