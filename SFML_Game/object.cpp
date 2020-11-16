#include "object.h"




object::object(sf::Texture* textureobject, sf::Vector2u totalImage)
{	
	//this->chooseImage = chooseImage;
	this->objectTexture = *textureobject;
	

	for (int i = 0; i < 14; i++)
	{
		this->ob[i].setSize(sf::Vector2f(64.f, 64.f));
		this->ob[i].setScale(1.f, 1.f);
	}

	


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


void object::uvrectOb(sf::RectangleShape* shape ,sf::Vector2u chooseImage)
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

	
