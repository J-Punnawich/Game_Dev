#include "object.h"




object::object(sf::Texture* textureobject, sf::Vector2u totalImage,sf::Vector2u chooseImage)
{	
	//this->chooseImage = chooseImage;

	
	this->sandbar1Texture = *textureobject;
	this->object1.setSize(sf::Vector2f(256.f, 128.f));
	this->object1.setTexture(textureobject);
	

	//this->sandbar2.setSize(sf::Vector2f(257.f, 128.f));
	//this->sandbar2Texture = *textureobject;
	
	//SpeedItemTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");

	//sandbar1.setTexture(sandbar1Texture);

	///speedItem.setTexture(SpeedItemTexture);

	
	//player.Update(deltaTime);


	//กำหนดกรอบให้กับ sprite ความกว้าง,ความสูง
	uvrect.width = textureobject->getSize().x / float(totalImage.x);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน x
	uvrect.height = textureobject->getSize().y / float(totalImage.y);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน y
	
	uvrect.left = chooseImage.x * uvrect.width;
	uvrect.top =  chooseImage.y * uvrect.height;


}



void object::setUvrectObject(sf::Vector2u totalImage)
{
     this->object1.setTextureRect(uvrect);
	
}
void object::DrawObject(sf::RenderTarget& target)
{   
	
	target.draw(this->object1);
	
	
}

	
