#include <iostream>
#include "Enermy.h"

Enermy::Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	Animationsenermy(texture, imageCount, switchTime)
{
	this->enermyTexture = *texture;
	collum = 0;

	this->enermy1.setSize(sf::Vector2f(128.f, 128.f));
	this->enermy1.setTexture(texture);
	

	// random positon ในแต่ละครั้งที่ run ได้ (เอาไว้ใช้กับ object ได้ดั)
	//this->enermy1.setPosition(rand() % 500 + 3, rand() % 500 + 5); 
	
	
}


const sf::FloatRect Enermy::getGlobalBounds() const // ให้ enermy sprite เป็น global
{
	return this->enermy1.getGlobalBounds();
}


void Enermy::UpdateEnermy(float deltaTime)
{	
	Animationsenermy.Updateinteract(collum, deltaTime);
	enermy1.setTextureRect(Animationsenermy.uvrect);
	enermy1.move(0.f, 3.f);
	
}

void Enermy::spawnEnermy(float pos_x,float pos_y)
{
	this->enermy1.setPosition(pos_x,pos_y);
}

void Enermy::titleAi()
{
	
}




void Enermy::Drawenermy(sf::RenderTarget& target)
{
	
	target.draw(this->enermy1);
}
