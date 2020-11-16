#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2u totalImage, sf::Vector2u chooseImage);
	
	const sf::FloatRect getBounds() const;
	
	void Draw(sf::RenderWindow& window);


	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	sf::IntRect uvrect;
	
};