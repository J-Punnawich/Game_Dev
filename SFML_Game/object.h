#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "animations.h"
class object
{


private:

	sf::Texture sandbar1Texture;
	sf::RectangleShape object1;

	
	
	


public:

	object(sf::Texture* textureobject, sf::Vector2u totalImage , sf::Vector2u chooseImage);
	sf::IntRect uvrect;
	sf::Vector2u chooseImage;
	sf::Vector2u totalImage;


	void DrawObject(sf::RenderTarget& target);
	void setUvrectObject(sf::Vector2u currentImage);
};

