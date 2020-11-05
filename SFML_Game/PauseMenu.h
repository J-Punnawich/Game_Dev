#pragma once
#include "game.h"


#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <map>
#include <vector>
#include <ctime>
#include <sstream>

#include "player.h"
#include "animations.h"
#include "Enermy.h"

#include "Item.h"
class PauseMenu
{
private:
	sf::RectangleShape background;
	sf::RectangleShape container;

	


public:
	PauseMenu(sf::RenderWindow& window);
	virtual ~PauseMenu();
	//function
	void update();
	void render(sf::RenderTarget& target);


};