#pragma once
 #include <SFML\Graphics.hpp>
#include "animations.h"
#include "SFML\System.hpp"
class Item
{
private:

	//Variable
	unsigned int collum1, collum2,collum3 ;


	//Class added
	animations AnimationsItemspeed;


	//function


public:
	Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	const sf::FloatRect getGlobalBounds() const;

	sf::Texture speedTexture;
	sf::RectangleShape itemspeed, itemheart,enermyInk;

	//functions
	void UpitemSpeed(float deltatime);
	void Upitemheart(float deltatime);
	void UpenermyInk(float deltatime);
	void Drawitem(sf::RenderTarget& target);

		

};

