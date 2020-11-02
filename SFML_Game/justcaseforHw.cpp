/*#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Game from scratch!");

	////// Circle
	sf::RectangleShape shape;
	shape.setSize({ 200.f, 200.f });
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		window.draw(shape);
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
		
		std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << "\n"; 
		
		
		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i MousePos = sf::Mouse::getPosition(window);

			shape.setPosition(MousePos.x,MousePos.y);
		}
		
		
		if (shape.getGlobalBounds().top <= 0.f)
		{
			shape.setPosition(shape.getPosition().x, 0.f);

		}
		if (shape.getGlobalBounds().top + shape.getGlobalBounds().height >= window.getSize().y)
		{
			shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getGlobalBounds().height);
		}
		//left           จุดซ้าย          <=  หน้าต่างซ้าย
		if (shape.getGlobalBounds().left <= 0.f)
		{
			shape.setPosition(0.f, shape.getPosition().y);
		}
		//right        จุดซ้าย                                                    +       ความกว้าง      =จุดขวา                      
		if (shape.getGlobalBounds().left + shape.getGlobalBounds().width >= window.getSize().x)
		{
			shape.setPosition(window.getSize().x - shape.getGlobalBounds().width, shape.getPosition().y);
		}


		window.clear();
	}
	return 0;
}*/