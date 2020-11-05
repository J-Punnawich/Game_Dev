#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
#include "player.h"
class Enermy
{	
private:
	sf::Texture  enermyTexture;
	
	sf::Vector2u imageCount;
	

	animations Animationsenermy;
	Player* player;

	
	unsigned int collum;
	


public: 
	Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	sf::RectangleShape  enermy1;
	const sf::FloatRect getGlobalBounds() const;

	void UpdateEnermy(float deltaTime);
	void Drawenermy(sf::RenderTarget& target);
	
	void spawnEnermy(float pos_x, float pos_y);
	
	void titleAi();
	
	
};

