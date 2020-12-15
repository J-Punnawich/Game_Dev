#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
#include "SFML\System.hpp"
#include "Collider.h"
class Player
{
private:
	
	//sf::Vector2f velocity;


	//Variable
	unsigned int row;
	
	float Points;
	
	//physics
	float velocityMax;
	


	//Class added
	animations Animationsplayer;


	//function
	
	void titlePhysics();
	
	


public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
	
	const sf::FloatRect getGlobalBounds() const;
	float accerlerate;

	sf::Texture bodyTexture;
	sf::RectangleShape body;
	
	sf::Vector2f getPos() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	
	
	
	sf::Vector2f velocity;
	float speedPlayer;
	
	//functions
	void Updateplayer(float deltatime);
	void setPos();
	void animateplayer(float deltatime);
	void Drawplayer(sf::RenderTarget& target);
	
	float getPoints();
};
