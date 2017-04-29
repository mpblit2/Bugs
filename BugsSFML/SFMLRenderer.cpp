#include "SFMLRenderer.h"

SFMLRenderer::SFMLRenderer()
{
}

SFMLRenderer::~SFMLRenderer()
{
}

void SFMLRenderer::Init()
{
	window_= std::make_unique<sf::RenderWindow>(sf::VideoMode{ 800, 600 }, "BugsSFML");
	window_->setFramerateLimit(60);
}

void SFMLRenderer::BeginFrame()
{
	window_->clear(sf::Color::Black);
}

void SFMLRenderer::EndFrame()
{
	window_->display();
}

void SFMLRenderer::Shutdown()
{
}
