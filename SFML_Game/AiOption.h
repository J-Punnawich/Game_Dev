#pragma once
#include "game.h"
class AiOption
{
protected: 
	game& Game;
	Player& player;
public:
	AiOption(Player& player, game& Game)
		: player(player) , Game(Game)
	{

	}

	virtual void update() = 0;
};