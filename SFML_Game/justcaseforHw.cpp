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

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		// on screen
	//	std::cout << "Mouse pos  " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << "\n";


	//	std::cout << "Mouse pos  " << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n";

	//	std::cout << collision.getGlobalBounds().top + collision.getGlobalBounds().height << "\n";

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			
			collision.setPosition((float)mousePos.x, (float)mousePos.y);
			// top
			if (collision.getGlobalBounds().top <= 0.f)
			{
				collision.setPosition(collision.getPosition().x, 0.f);
			}
			// bottom                       จุดบน         +      ความสูง     = จุดล่างง
			if (collision.getGlobalBounds().top + collision.getGlobalBounds().height >= window.getSize().y)
			{
				collision.setPosition(collision.getPosition().x , window.getSize().y - collision.getGlobalBounds().height );
			}
			//left
			if (collision.getGlobalBounds().left <= 0.f)
			{
				collision.setPosition(0.f, collision.getPosition().y);
			}
			//right
			if (collision.getGlobalBounds().left + collision.getGlobalBounds().width >= window.getSize().x)
			{
				collision.setPosition(window.getSize().x - collision.getGlobalBounds().width,collision.getPosition().y);
			}
		}
		

		window.clear();
	}
	return 0;
}*/