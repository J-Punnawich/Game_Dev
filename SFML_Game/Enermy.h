#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
class Enermy
{	
private:
	sf::Texture  enermyTexture;
	sf::Sprite  enermy;
	sf::Vector2u imageCount;
	

	animations Animationsenermy;


	
	unsigned int collum;
	float speed;



	void Sprite();



public: 
	Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	

	void UpdateEnermy(float deltaTime);
	void Drawenermy(sf::RenderTarget& target);
};

