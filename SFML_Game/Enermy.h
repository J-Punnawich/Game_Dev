#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
class Enermy
{	
private:
	sf::Texture  enermy1Texture;
	sf::Sprite  enermy1;
	sf::Vector2u imageCount;
	

	animations Animationsenermy;


	
	unsigned int collum;
	float speed;



	



public: 
	Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	

	void UpdateEnermy(float deltaTime);
	void Drawenermy(sf::RenderTarget& target);
	void enermySprite();
	void spawnEnermy(float pos_x, float pos_y);
};

