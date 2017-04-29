
#pragma once
#include "../BugsCore/IInput.h"

class SFMLInput :
	public Bugs::IInput
{
public:
	SFMLInput();
	~SFMLInput() override;
	void Init() override;
	bool IsKeyPressed(char key) const override;
	void Shutdown() override;
};

