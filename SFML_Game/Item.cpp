#include "Item.h"

Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	AnimationsItem(texture, imageCount, switchTime)
{

	collum = 2;
	this->speedTexture = *texture;
	this->itemspeed.setSize(sf::Vector2f(64.f,64.f));
	this->itemspeed.setTexture(texture);
	///ทำให้ item ติดตัว player
	//this->itemspeed.setOrigin(itemspeed.getSize() / 2.0f);
	
}

const sf::FloatRect Item::getGlobalBounds() const
{
	return this->itemspeed.getGlobalBounds();
}

void Item::UpitemSpeed(float deltatime)
{
	AnimationsItem.Updateinteract(collum, deltatime);
	itemspeed.setTextureRect(AnimationsItem.uvrect);
}

void Item::Drawitem(sf::RenderTarget& target)
{
	target.draw(this->itemspeed);
}