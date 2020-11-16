#pragma once
#include <SFML\Graphics.hpp>

class Collider
{
public:
	Collider(sf::RectangleShape& body);

	bool Checkcollision(Collider& other);
	sf::Vector2f Getpos() { return body.getPosition(); }
	sf::Vector2f Gethalfsize() { return body.getSize() / 2.f; }


private:

	sf::RectangleShape& body;




};