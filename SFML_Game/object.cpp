#include "object.h"

#include "animations.h"


object::object(sf::Texture* textureobject, sf::Vector2u imageCount,float switchTime):
	AnimationsItem(textureobject, imageCount ,switchTime)
{
	this->sandbarTexture = *textureobject;
	this->Sprite();
	
	

	//SpeedItemTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");

	sandbar.setTexture(sandbarTexture);
	///speedItem.setTexture(SpeedItemTexture);

	
	//player.Update(deltaTime);


	//กำหนดกรอบให้กับ sprite ความกว้าง,ความสูง
	uvrect.width = textureobject->getSize().x / float(imageCount.x);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน x
	uvrect.height = textureobject->getSize().y / float(imageCount.y);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน y
}

void object::Sprite()
{
	this->sandbar.setTexture(this->sandbarTexture);
	this->sandbar.setPosition(200.f, 200.f);
}

void object::setUvrectObject(sf::Texture* textureobject, sf::Vector2u imageCount)
{
	sandbar.setTextureRect(uvrect);
}
void object::DrawObject(sf::RenderTarget& targetobject)
{
	targetobject.draw(sandbar);
}

	
