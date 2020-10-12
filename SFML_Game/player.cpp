#include "Player.h"
#include "animations.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	Animations(texture, imageCount, switchTime)
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
	sf::Vector2f movement(0.0f, 0.01f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		row = 1;
		movement.x -= speed * deltatime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{	
		row = 2;
		movement.x += speed * deltatime;
	}
	
	if (movement.x == 0.0f)
	{
		row = 0;
	}
	
	Animations.Update(row, deltatime);
	body.setTextureRect(Animations.uvrect);
	body.move(movement);
}


void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	
}
