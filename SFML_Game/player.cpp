#include <iostream>
#include "Player.h"
#include "game.h"



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	Animationsplayer(texture, imageCount, switchTime)
{
	
	this->speed = speed;
	row = 0;
	
	this->bodyTexture = *texture;
	
	this->body.setSize(sf::Vector2f(128.f, 128.f));
	this->body.setTexture(&bodyTexture);
	this->body.setOrigin(body.getSize()/2.0f);
	this->body.setScale(0.8, 0.8);

	 
	
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
	sf::Vector2f velocity(0.0f, 1.f);
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		row = 1;
		velocity.x -= speed * deltatime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{	
		row = 2;
		velocity.x += speed * deltatime;
	}
	
	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	
	Animationsplayer.Update(row, deltatime);
	body.setTextureRect(Animationsplayer.uvrect);
	
	body.move(velocity);
	
	//std::cout << velocity.x << "\n" ;

}

void Player::setPosition()
{
	this->body.setPosition(0.f,0.f);  //origin spawn point 
	std::cout << "collision!!" << "\n";
}



float Player::getPoints()
{ // แสดงผลคะแนน
	this->Points = (body.getPosition().y)/5;
  // std::cout << this->Points/20 <<" m" << "\n";
	return Points;
}

void Player::Drawplayer(sf::RenderTarget& target)
{
	target.draw(this->body);

}

