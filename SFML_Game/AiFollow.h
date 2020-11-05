#pragma once
#include "AiOption.h"
class AiFollow :
	public AiOption
{
private:

public:
	AiFollow(Player& player, game& Game);
	
	void update();
	 
};