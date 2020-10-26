#include <iostream>
#include "Enermy.h"

Enermy::Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	Animationsenermy(texture, imageCount, switchTime)
{
	this->enermy1Texture = *texture;
	collum = 0;

	this->enermySprite();

	// random positon ในแต่ละครั้งที่ run ได้ (เอาไว้ใช้กับ object ได้ดั)
	//this->enermy1.setPosition(rand() % 500 + 3, rand() % 500 + 5); 
	
	
}

const sf::FloatRect Enermy::getGlobalBounds() const
{
	return this->enermy1.getGlobalBounds();
}



void Enermy::UpdateEnermy(float deltaTime)
{	
	Animationsenermy.Updateinteract(collum, deltaTime);
	enermy1.setTextureRect(Animationsenermy.uvrect);
	enermy1.move(0.f, 4.f);
	
}

void Enermy::enermySprite()
{
	this->enermy1.setTexture(this->enermy1Texture);


}



void Enermy::spawnEnermy(float pos_x,float pos_y)
{
	this->enermy1.setPosition(pos_x,pos_y);
}

void Enermy::Drawenermy(sf::RenderTarget& target)
{
	
	target.draw(this->enermy1);
}
