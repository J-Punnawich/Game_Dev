#include <iostream>
#include "Enermy.h"

Enermy::Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	Animationsenermy(texture, imageCount, switchTime)
{
	this->enermyTexture = *texture;
	collum = 0;

	this->enermy.setSize(sf::Vector2f(128.f, 128.f));
	this->enermy.setTexture(texture);
	

	// random positon ในแต่ละครั้งที่ run ได้ (เอาไว้ใช้กับ object ได้ดั)
	//this->enermy1.setPosition(rand() % 500 + 3, rand() % 500 + 5); 
	
	
}


const sf::FloatRect Enermy::getGlobalBounds() const // ให้ enermy sprite เป็น global
{
	return this->enermy.getGlobalBounds();
}


void Enermy::UpdateEnermy(float deltaTime)
{	
	Animationsenermy.Updateinteract(collum, deltaTime);
	enermy.setTextureRect(Animationsenermy.uvrect);
	enermy.move(0.f, 3.f);
	
}

void Enermy::spawnEnermy(float pos_x,float pos_y)
{
	this->enermy.setPosition(pos_x,pos_y);
}

void Enermy::chasing()
{ 
	if (this->player->body.getGlobalBounds().top > this->enermy.getPosition().x)
	{
		
	}
}


void Enermy::Drawenermy(sf::RenderTarget& target)
{
	
	target.draw(this->enermy);
}
