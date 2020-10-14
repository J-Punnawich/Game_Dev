#pragma once
#include <SFML\Graphics.hpp>
#include "animations.h"
class Player
{
private:
	sf::Texture bodyTexture, enermy1Texture, SpeedItemTexture;
	sf::Sprite body, enermy1, speedItem;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	animations Animations;
	
	
	float totalTime;
	float switchTime;
	unsigned int row;
	
	float speed;
	bool faceright;


public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed);
	

	void Update(float deltatime);
	void Sprite();
	void Texture(); 


	void Draw(sf::RenderTarget& target);

};
