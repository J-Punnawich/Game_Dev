#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
#include "SFML\System.hpp"
class Player
{
private:
	
	//sf::Vector2f velocity;


	//Variable
	unsigned int row;
	float speed;
	int Points;
	
	//physics
	float velocityMax;
	float accerlerate;


	//Class added
	animations Animationsplayer;


	//function
	
	void titlePhysics();
	
	


public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
	
	const sf::FloatRect getGlobalBounds() const;
	
	sf::Texture bodyTexture;
	sf::RectangleShape body;

	//functions
	void Updateplayer(float deltatime);
	void setPosition();
	void Drawplayer(sf::RenderTarget& target);
	
	float getPoints();
};
