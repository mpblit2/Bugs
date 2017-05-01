#include <SFML/Graphics.hpp>
#include "SFMLInputRenderer.h"
#include "../BugsCore/Application.h"

int main()
{
	SFMLInputRenderer inputRenderer;
	Bugs::Application application(inputRenderer);
	
	return application.Run();
}