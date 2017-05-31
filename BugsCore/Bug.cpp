#include "stdafx.h"
#include "Bug.h"

using namespace Bugs;

Bugs::Bug::Bug(std::string textureId, const Vector2 & position) 
	: textureId_(textureId), position_(position), box_(position, Vector2(50,50))
{
}

Bug::~Bug()
{
}

void Bug::MoveLeft()
{
	position_.GetX() -= 10;
	box_.SetPosition(position_);
}

void Bug::MoveRight()
{
	position_.GetX() += 10;
	box_.SetPosition(position_);
}
