#include "stdafx.h"
#include "Bug.h"

using namespace Bugs;

Bug::Bug(std::string textureId, float positionX, float positionY) : textureId_(textureId), positionX_(positionX), positionY_(positionY)
{
}

Bug::~Bug()
{
}

void Bug::MoveLeft()
{
	positionX_ -= 10;
}

void Bug::MoveRight()
{
	positionX_ += 10;
}
