#include "SFMLInput.h"
#include <SFML/Graphics.hpp>

SFMLInput::SFMLInput()
{
}


SFMLInput::~SFMLInput()
{
}

void SFMLInput::Init()
{
}

bool SFMLInput::IsKeyPressed(char key) const
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
}

void SFMLInput::Shutdown()
{
}
