#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf; 
int main()
{
	RenderWindow window(VideoMode(1440, 980), "Game from scratch!",Style::Default);
	window.setFramerateLimit(50);

	////// Circle
	CircleShape collision(100.f);
	collision.setPosition({ 200.f, 200.f });
	collision.setFillColor(Color::Red);

	////// Texture สร้างตัวละคร, โหลดจากไฟล์png
	Texture playerTexture;
	playerTexture.loadFromFile("C:/pf_Game/img/heal.png");
	

	////// Sprite สร้างพื้นท่ี่ให้ตัวละคร
	Sprite shapeSprite;
	shapeSprite.setTexture(playerTexture);
	shapeSprite.setTextureRect(IntRect(32,0,32,35));


	while (window.isOpen())
	{
		window.draw(shapeSprite);
		window.draw(collision);
		window.display();

		//// Movement การเคลื่อนที่ 
		shapeSprite.move(0.f, .8f);
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			
				shapeSprite.setTextureRect(IntRect(32, 35, 32, 35));
				shapeSprite.move(.1f, 0.f);
			
			
		}
	    else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			shapeSprite.setTextureRect(IntRect(64, 70, 32, 35));
			
		}
		else if (Keyboard::isKeyPressed(Keyboard::A))
		{
			
			shapeSprite.move(-.1f, 0.f);
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{

			shapeSprite.move(0.f, -.1f);
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		window.clear();
	}
	return 0;
}