#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "animations.h"
class object
{


private:

	sf::Texture sandbarTexture, SpeedItemTexture;
	sf::Sprite sandbar, speedItem;

	
	animations AnimationsItem;
	


public:

	object(sf::Texture* textureobject, sf::Vector2u imageCount, float switchTime);
	sf::IntRect uvrect;


	void DrawObject(sf::RenderTarget& targetobject);
	void Sprite();
	void setUvrectObject(sf::Texture* textureobject, sf::Vector2u imageCount);
};

