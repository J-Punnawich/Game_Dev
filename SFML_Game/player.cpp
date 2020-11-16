#include <iostream>
#include "Player.h"
#include "game.h"



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	Animationsplayer(texture, imageCount, switchTime)
{
	
	this->speedPlayer = speed;
	row = 0;
	
	this->bodyTexture = *texture;
	
	this->body.setSize(sf::Vector2f(128.f, 128.f));
	this->body.setTexture(&bodyTexture);
	this->body.setScale(0.8f, 0.8f);	
	
	
}
void Player::titlePhysics()
{
	this->velocityMax = 500.f;
	this->accerlerate = 0.5f;

}
const sf::FloatRect Player::getGlobalBounds() const
{
	return this->body.getGlobalBounds();
}

void Player::Updateplayer(float deltatime)
{	
	sf::Vector2f velocity( 0.f , speedPlayer * deltatime);
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		row = 1;
		velocity.x -= speedPlayer * deltatime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{	
		row = 2;
		velocity.x += speedPlayer * deltatime;
	}
	
	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	/**
	if (abs(velocity.x) > velocityMax)
	{
		if (velocity.x < 0.f)
		{
			velocity.x = -1.f * velocityMax;
		}
		else
		{
			velocity.x = velocityMax;
		}
	}
	if ( velocity.y > velocityMax)
	{
		velocity.y = velocityMax;
	}*/


	Animationsplayer.Update(row, deltatime);
	body.setTextureRect(Animationsplayer.uvrect);
	
	body.move(velocity);
	
	std::cout << "VEc " << velocity.y << "\n" ;

}

void Player::setPos()
{
	this->body.setPosition(500.f,0.f);  //origin spawn point 
	
}



float Player::getPoints()
{ // แสดงผลคะแนน
	this->Points = int((body.getPosition().y)/7.f);
  // std::cout << this->Points/20 <<" m" << "\n";
	return this->Points;
}

void Player::Drawplayer(sf::RenderTarget& target)
{
	target.draw(this->body);
}

