﻿#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position,sf::Vector2u totalImage, sf::Vector2u chooseImage)
{
	body.setSize(size);
	body.setOrigin(size / 2.f );
	body.setTexture(texture);
	body.setPosition(position);

	uvrect.width = texture->getSize().x / float(totalImage.x);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน x
	uvrect.height = texture->getSize().y / float(totalImage.y);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน y
	uvrect.left = chooseImage.x * uvrect.width;
	uvrect.top = chooseImage.y * uvrect.height;
	
	body.setTextureRect(uvrect);
}

const sf::FloatRect Platform::getBounds() const
{
	return this->body.getGlobalBounds();
}





void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
