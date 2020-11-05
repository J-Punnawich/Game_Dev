#include "Item.h"

Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	AnimationsItemspeed(texture, imageCount, switchTime)
{

	collum1 = 2;
	collum2 = 3;
	this->speedTexture = *texture;
	
	this->itemspeed.setSize(sf::Vector2f(64.f,64.f));
	this->itemheart.setSize(sf::Vector2f(64.f,64.f));
	this->itemspeed.setTexture(texture);
	this->itemheart.setTexture(texture);

	
	
	///ทำให้ item ติดตัว player
	//this->itemspeed.setOrigin(itemspeed.getSize() / 2.0f);
	
}

const sf::FloatRect Item::getGlobalBounds() const
{
	return this->itemspeed.getGlobalBounds();

}

void Item::UpitemSpeed(float deltatime)
{
	AnimationsItemspeed.Updateinteract(collum1, deltatime);
	itemspeed.setTextureRect(AnimationsItemspeed.uvrect);
}

void Item::Upitemheart(float deltatime)
{
	AnimationsItemspeed.Updateinteract(collum2, deltatime);
	itemheart.setTextureRect(AnimationsItemspeed.uvrect);
}

void Item::Drawitem(sf::RenderTarget& target)
{
	target.draw(this->itemspeed);
	
	target.draw(this->itemheart);
}