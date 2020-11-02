#pragma once
 #include <SFML\Graphics.hpp>
#include "animations.h"
#include "SFML\System.hpp"
class Item
{
private:

	//Variable
	unsigned int collum;


	//Class added
	animations AnimationsItem;


	//function


public:
	Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	const sf::FloatRect getGlobalBounds() const;

	sf::Texture speedTexture;
	sf::RectangleShape itemspeed;

	//functions
	void UpitemSpeed(float deltatime);
		 	
	void Drawitem(sf::RenderTarget& target);

		

};

