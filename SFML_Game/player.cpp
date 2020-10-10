#include "Player.h"
#include "animations.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) : 
	Animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 0;
	faceright = true;

	enermy1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf2.png");
	bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");

	enermy1.setTexture(enermy1Texture);
	body.setTexture(bodyTexture);
}

void Player::Update(float deltatime)
{
}

void Player::Draw(sf::RenderWindow window)
{
	window.draw(body);
	window.draw(enermy1);
}
