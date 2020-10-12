/*#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Game from scratch!");

	////// Circle
	sf::CircleShape collision(100.f);
	collision.setPosition({ 200.f, 200.f });
	collision.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		window.draw(collision);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		// on screen
		std::cout << "Mouse pos  " << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n";


		std::cout << "Mouse pos  " << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n";

		window.clear();
	}
	return 0;
}*/