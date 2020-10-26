#include <iostream>
#include "Player.h"
#include "game.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	Animationsplayer(texture, imageCount, switchTime)
{
	
	this->speed = speed;
	row = 0;
	
	this->bodyTexture = *texture;
	
	this->Sprite();
	this->body.setPosition(sf::Vector2f(350.f, 0.f));
	
	
}
void Player::titlePhysics()
{
	this->velocityMax = 10.f;
	this->accerlerate = 1.f;

}
const sf::FloatRect Player::getGlobalBounds() const
{
	return this->body.getGlobalBounds();
}

void Player::Updateplayer(float deltatime)
{	
	sf::Vector2f movement(0.0f, 1.f);
	
	

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
	
	Animationsplayer.Update(row, deltatime);
	body.setTextureRect(Animationsplayer.uvrect);
	body.move(movement);
	

	
}

void Player::setPosition()
{
	this->body.setPosition(350.f,0.f);
	std::cout << "collision!!" << "\n";
}

void Player::Sprite()
{
	this->body.setTexture(this->bodyTexture);
	
	
	
}

void Player::getPoints()
{ // แสดงผลคะแนน
	this->Points = body.getPosition().y;
		std::cout << this->Points/20 <<" m" << "\n";

}

void Player::Drawplayer(sf::RenderTarget& target)
{
	target.draw(this->body);

}

