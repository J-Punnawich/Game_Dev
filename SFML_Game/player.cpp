#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	Animationsplayer(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	
	this->bodyTexture = *texture;
	

	this->Sprite();

	
}

void Player::Updateplayer(float deltatime)
{	
	sf::Vector2f movement(0.0f, 0.9f);

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

void Player::Sprite()
{
	this->body.setTexture(this->bodyTexture);
	
}

void Player::Drawplayer(sf::RenderTarget& target)
{
	target.draw(this->body);

}

