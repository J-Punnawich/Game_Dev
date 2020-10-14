#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "animations.h"
class object
{


private:

	sf::Texture sandbarTexture;

	sf::Sprite sandbar;

	//Player player;
	animations Animations;
	


public:

	object(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void Draw(sf::RenderWindow& window);
	sf::IntRect uvrect;
};

