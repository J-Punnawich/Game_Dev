#include "animations.h"
#include<iostream>

animations::animations(sf::Texture * texture ,sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.f;
	currentImage.x = 0;

	uvrect.width  = texture->getSize().x / float(imageCount.x);
	uvrect.height = texture->getSize().y / float(imageCount.y);
}


void animations::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	
	if (totalTime >= switchTime) 
	{
		totalTime -= switchTime;
		currentImage.x++;
		if(currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvrect.left = currentImage.x * uvrect.width;
	uvrect.top = currentImage.y * uvrect.height;
}
