#include "player.h"

player::player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animations(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 0;

	
	
	sf::Sprite body;
	body.setTexture(playerTexture);


}   



/*void player::Update(float deltaTime,Sprite body)
{
	
	  
	if (Keyboard::isKeyPressed(Keyboard::D))
		body.move(0.f, .2f);


	animations.Update(float deltaTime);
	body.move();
} */

void player::Draw(RenderWindow window)
{
	window.draw(body);
}
