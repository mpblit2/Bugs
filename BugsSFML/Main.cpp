#include <SFML/Graphics.hpp>
#include "SFMLRenderer.h"
#include "SFMLInput.h"
#include "../BugsCore/Application.h"

int main()
{
	SFMLRenderer renderer;
	SFMLInput input;
	Bugs::Application application(renderer, input);
	
	return application.Run();
}