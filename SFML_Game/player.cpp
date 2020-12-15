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
	this->body.setOrigin(0.f, 0.f);

	this->titlePhysics();
}
void Player::titlePhysics()
{
	this->velocityMax = 4.5f;
	this->accerlerate = 1.f;

}
const sf::FloatRect Player::getGlobalBounds() const
{
	return this->body.getGlobalBounds();
}

void Player::Updateplayer(float deltatime)
{	
	sf::Vector2f velocity( 0.f , speedPlayer *this->accerlerate);
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 30)
	{
		
		row = 1;
		velocity.x -= speedPlayer * this->accerlerate;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) /*|| sf::Joystick::getAxisPosition(0, sf::Joystick::X) > -30*/)
	{
		
		row = 2;
		velocity.x += speedPlayer * this->accerlerate;
	}
	
	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	if (this->accerlerate < 4.5f)
	{
		this->accerlerate += 0.001f;
	}

	

	
	body.setTextureRect(Animationsplayer.uvrect);
	
	body.move(velocity);
	
	//std::cout << "VEc: " << velocity.x << "   "  << velocity.y << "\n" ;

	printf("%.2f \n", this->body.getPosition().y);
	

}

void Player::setPos()
{
	this->body.setPosition(500.f,0.f);  //origin spawn point 
	
}

void Player::animateplayer(float deltatime)
{
	Animationsplayer.Update(row, deltatime);
}



float Player::getPoints()
{ // แสดงผลคะแนน
	this->Points = int(((body.getPosition().y)/7.f)-57  );
  // std::cout << this->Points/20 <<" m" << "\n";
	return this->Points;
}

void Player::Drawplayer(sf::RenderTarget& target)
{
	target.draw(this->body);
}

