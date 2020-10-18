#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
class Player
{
private:

	sf::Texture bodyTexture;
	sf::Sprite body;


	//Variable
	unsigned int row;
	float speed;
	
	//Class added
	animations Animationsplayer;


	//function
	void Sprite();
	
	
	


public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
	
	

	//functions
	void Updateplayer(float deltatime);
	void Drawplayer(sf::RenderTarget& target);
	
};
