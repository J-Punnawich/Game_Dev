#include <iostream>
#include <SFML/Graphics.hpp>
#include "animations.h"
#include "Player.h"
#include "game.h"
#include "object.h"

using namespace sf; 
int main()
{  
/* /// use 1720,1000
	sf::RenderWindow window(sf::VideoMode(800,600), "Game", sf::Style::Close | sf::Style::Default);
	*/
	
	std::srand(static_cast<unsigned>(time(NULL))); 
	
	game Game;
	/*sf::Texture bodyTexture, enermyTexture, SpeedItemTexture, sandbarTexture;
	enermyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/enermy1.png");
	bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");

	sf::Sprite body, enermy, speedItem, sandbar;

	enermy.setTexture(enermyTexture);
	body.setTexture(bodyTexture);
	sf::Texture bodyTexture, enermy1Texture,SpeedItemTexture,sandbarTexture;
	enermy1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/enermy1.png");
	bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
	SpeedItemTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");
	sandbarTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar.png");
	
	sf::Sprite body, enermy1, speedItem,sandbar;

	enermy1.setTexture(enermy1Texture);
	body.setTexture(bodyTexture);
	speedItem.setTexture(SpeedItemTexture);
	sandbar.setTexture(sandbarTexture);


	object sandbarSprite(&sandbarTexture, Vector2u(4, 1), 0.5f);


	////// เรียกใช้ฟังขั่น  (ตัวTexture , จำนวน (แถว,คอลั่ม) , ความเร็วในการ switch )
	animations animationsBody(&bodyTexture, Vector2u(4, 4), 0.4f)
		, animationsEnermy1(&enermy1Texture, Vector2u(2, 6), 0.4f)
		, animationsSpeedItem(&SpeedItemTexture, Vector2u(8, 4), 0.4f);
			
    

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

		Game.update();


		Game.render();

		/////// จะอัพเดทให้ player มีการขยับอยู่ตลอดเวลา ตามภาพ png แถวที่ 0 
		animationsBody.Update(0, deltaTime);
		animationsEnermy1.Updateinteract(0, deltaTime);
		animationsSpeedItem.Updateinteract(2, deltaTime);

		///// ใช้คำสั่ง uvrect ในheader animations คำนวณกำหนดกรอบให้ bodySprite และกำหนดให้แสดงภาพแต่ละจุด ex (0,1) (0,2) ...
		body.setTextureRect(animationsBody.uvrect);
		enermy1.setTextureRect(animationsEnermy1.uvrect);
		speedItem.setTextureRect(animationsSpeedItem.uvrect);
		sandbar.setTextureRect(sandbarSprite.uvrect);
		
		sandbar.setPosition(200.f, 300.f);
		///
		player.Update(deltaTime);


		///
		


		
		///if (enermy1.getGlobalBounds().intersects(body.getGlobalBounds())) {
			body.setPosition(0.f,0.f);
		}



		window.clear(sf::Color(0,150,150));
			
		
		window.draw(speedItem);
		
		window.draw(enermy1);
		window.draw(sandbar);
		//player.Draw(window);
		window.display();
		
	
		
	}*/
	Game.run();
	

}

