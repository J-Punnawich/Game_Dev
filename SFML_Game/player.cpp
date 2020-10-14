#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	Animations(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceright = true;
	this->bodyTexture = *texture;

	this->Texture();
	this->Sprite();
	
	

	
	


	
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
void Player::Texture()
{
	this->enermy1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/enermy1.png");
	//this->bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
	this->SpeedItemTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");
}
void Player::Sprite()
{
	
	this->body.setTexture(this->bodyTexture);
	this->enermy1.setTexture(this->enermy1Texture);
	this->speedItem.setTexture(this->SpeedItemTexture);
}




void Player::Draw(sf::RenderTarget& target)
{
	target.draw(this->body);

	
}
