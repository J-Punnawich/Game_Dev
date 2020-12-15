#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "animations.h"
#include "Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2u imageCount, float switchTime,float deltaTime);
	const sf::FloatRect getBounds() const;
	animations Animations;
	void Draw(sf::RenderWindow& window);
	void updateplat(float deltaTime);


	Collider GetCollider() { return Collider(body); }
	
private:
	sf::RectangleShape body;
	sf::IntRect uvrect;
	
};