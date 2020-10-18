#include "Enermy.h"

Enermy::Enermy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	Animationsenermy(texture, imageCount, switchTime)
{
	this->enermyTexture = *texture;
	collum = 0;

	this->Sprite();
}



void Enermy::UpdateEnermy(float deltaTime)
{
	Animationsenermy.Updateinteract(collum, deltaTime);
	enermy.setTextureRect(Animationsenermy.uvrect);
}

void Enermy::Sprite()
{
	this->enermy.setTexture(this->enermyTexture);
}

void Enermy::Drawenermy(sf::RenderTarget& target)
{
	target.draw(this->enermy);
}
