#include "stdafx.h"
#include "Bug.h"

using namespace Bugs;

Bugs::Bug::Bug(std::string textureId, const Vector2 & position) : textureId_(textureId), position_(position)
{
}

Bug::~Bug()
{
}

void Bug::MoveLeft()
{
	position_.GetX() -= 10;
}

void Bug::MoveRight()
{
	position_.GetX() += 10;
}
