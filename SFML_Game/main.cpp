#include <iostream>
#include <SFML/Graphics.hpp>
#include "animations.h"
#include "Player.h"
#include "game.h"

using namespace sf; 
int main()
{   /// use 1720,1000
	sf::RenderWindow window(sf::VideoMode(800,600), "Game", sf::Style::Close | sf::Style::Default);
	
	//game Game;
	

	sf::Texture bodyTexture, enermy1Texture;
	enermy1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf2.png");
	bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");

	sf::Sprite body, enermy1;
	enermy1.setTexture(enermy1Texture);
	body.setTexture(bodyTexture);

	////// เรียกใช้ฟังขั่น  (ตัวTexture , จำนวน (แถว,คอลั่ม) , ความเร็วในการ switch )
	animations animations(&bodyTexture, Vector2u(4, 4), 0.4f) 
		      ,animations2(&enermy1Texture,Vector2u(4,4), 0.9f) ;
    

	Player player(&bodyTexture , sf::Vector2u(4,4), 0.4f, 100.f);

	///// ตั้งให้ deltaTime เป็น 0 แล้วเรียกคำสั่ง clock ซึ่งจะวิ่งค่าเวลาไปเรื่อยๆ
	float deltaTime = 0.f;
	Clock clock;


	
	while (window.isOpen())
	{   //// จะนับเวลาขึ้น เเล้วก้ restart เป็น 0 วนไป จับค่าเท่ากับ deltaTime
		deltaTime = clock.restart().asSeconds();
		
	
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

		//Game.update();


		//Game.render();

		/////// จะอัพเดทให้ player มีการขยับอยู่ตลอดเวลา ตามภาพ png แถวที่ 0 
		/*animations.Update(0, deltaTime);
		animations2.Update(0, deltaTime);*/

		///// ใช้คำสั่ง uvrect ในheader animations คำนวณกำหนดกรอบให้ bodySprite และกำหนดให้แสดงภาพแต่ละจุด ex (0,1) (0,2) ...
		body.setTextureRect(animations.uvrect);
		enermy1.setTextureRect(animations2.uvrect);

		///
		player.Update(deltaTime);

		///
		if (enermy1.getGlobalBounds().intersects(body.getGlobalBounds())) {
			body.setPosition(0.f,0.f);
		}


		window.clear(sf::Color(0,150,150));
		

		window.draw(enermy1);
		player.Draw(window);
		window.display();
		
	
		
	}
		return 0;

}

