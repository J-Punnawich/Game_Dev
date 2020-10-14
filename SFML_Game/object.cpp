#include "object.h"

#include "animations.h"

object::object(sf::Texture* texture, sf::Vector2u imageCount, float switchTime):
	Animations(texture, imageCount ,switchTime)
{
	sandbarTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar.png");

	sandbar.setTexture(sandbarTexture);

	
	//player.Update(deltaTime);


	//กำหนดกรอบให้กับ sprite ความกว้าง,ความสูง
	uvrect.width = texture->getSize().x / float(imageCount.x);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน x
	uvrect.height = texture->getSize().y / float(imageCount.y);  // ขนาดรูป หารด้วย จำนวนภาพในรูปแกน y
}


void object::Draw(sf::RenderWindow& window)
{
	window.draw(sandbar);
}


