#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
class Player
{
private:
	sf::Texture bodyTexture, enermy1Texture;
	sf::Sprite body, enermy1;
	

	animations Animations;

	unsigned int row;
	float speed;
	bool faceright;


public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
	

	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);

};
