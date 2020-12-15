#include "Platform.h"


Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position,sf::Vector2u imageCount,float switchTime, float deltaTime) :
	Animations(texture, imageCount, switchTime)
{
	body.setSize(size);
	body.setOrigin(size / 2.f );
	body.setTexture(texture);
	body.setPosition(position);
	
/*	uvrect.width = texture->getSize().x / float(totalImage.x);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน x
	uvrect.height = texture->getSize().y / float(totalImage.y);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน y
	uvrect.left = chooseImage.x * uvrect.width;
	uvrect.top = chooseImage.y * uvrect.height;*/
	Animations.Updateinteract(0, deltaTime);
	body.setTextureRect(Animations.uvrect);
}

const sf::FloatRect Platform::getBounds() const
{
	return this->body.getGlobalBounds();
}
void Platform::updateplat(float deltaTime)
{
	
	
}





void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}



