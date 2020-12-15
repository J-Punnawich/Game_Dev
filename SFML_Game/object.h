#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "animations.h"
#include "Collider.h"
class object
{


private:

	sf::Texture objectTexture, portTexture;
	
public:

	object(sf::Texture* textureobject, sf::Vector2u totalImage);
	sf::IntRect uvrect;
	sf::Vector2u chooseImage;
	sf::Vector2u totalImage;
	sf::RectangleShape ob[15],port[4];
	
	Collider GetCollider() { return Collider(ob[0]); }


	void uvrectOb(sf::RectangleShape* shape, sf::Vector2u chooseImage);
	void DrawObject(sf::RenderTarget& target);

};
