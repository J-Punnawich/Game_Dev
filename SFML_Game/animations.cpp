﻿#include "animations.h"
#include<iostream>



animations::animations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.f;
	currentImage.x = 0;


	//กำหนดกรอบให้กับ sprite ความกว้าง,ความสูง
	uvrect.width = texture->getSize().x / float(imageCount.x);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน x
	uvrect.height = texture->getSize().y / float(imageCount.y);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน y
}


void animations::Update(int row, float deltaTime)
{
	currentImage.y = row ;
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
	/*if (faceright)
	{
		uvrect.left = currentImage.x * uvrect.width;
		uvrect.width = abs(uvrect.width);
	}
	else
		uvrect.left = (currentImage.x + 1) * uvrect.width;
	uvrect.width = -abs(uvrect.width);*/

	
}
