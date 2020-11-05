#include "object.h"




object::object(sf::Texture* textureobject, sf::Vector2u totalImage)
{	
	//this->chooseImage = chooseImage;
	this->objectTexture = *textureobject;



	this->ob[0].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[1].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[2].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[3].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[4].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[5].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[6].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[7].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[8].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[9].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[10].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[11].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[12].setSize(sf::Vector2f(64.f, 64.f));
	this->ob[13].setSize(sf::Vector2f(64.f, 64.f));

	


	this->ob[0].setTexture(textureobject);
	this->ob[1].setTexture(textureobject);
	this->ob[2].setTexture(textureobject);
	this->ob[3].setTexture(textureobject);
	this->ob[4].setTexture(textureobject);
	this->ob[5].setTexture(textureobject);
	this->ob[6].setTexture(textureobject);
	this->ob[7].setTexture(textureobject);
	this->ob[8].setTexture(textureobject);
	this->ob[9].setTexture(textureobject);
	this->ob[10].setTexture(textureobject);
	this->ob[11].setTexture(textureobject);
	this->ob[12].setTexture(textureobject);
	this->ob[13].setTexture(textureobject);

	this->port[0].setTexture(textureobject);

	//กำหนดกรอบให้กับ sprite ความกว้าง,ความสูง
	uvrect.width = textureobject->getSize().x / float(totalImage.x);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน x
	uvrect.height = textureobject->getSize().y / float(totalImage.y);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน y
	
	


}

void object::uvrectOb(sf::RectangleShape *shape ,sf::Vector2u chooseImage)
{
	uvrect.left = chooseImage.x * uvrect.width;
	uvrect.top = chooseImage.y * uvrect.height;
     shape->setTextureRect(uvrect);
	
}

void object::DrawObject(sf::RenderTarget& target)
{   
	target.draw(this->ob[0]);
	target.draw(this->ob[1]);
	target.draw(this->ob[2]);
	target.draw(this->ob[3]);
	target.draw(this->ob[4]);
	target.draw(this->ob[5]);
	target.draw(this->ob[6]);
	target.draw(this->ob[7]);
	target.draw(this->ob[8]);
	target.draw(this->ob[9]);
	target.draw(this->ob[10]);
	target.draw(this->ob[11]);
	target.draw(this->ob[12]);
	target.draw(this->ob[13]);


}

	
