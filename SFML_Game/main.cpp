#include <iostream>
#include <SFML/Graphics.hpp>
#include "animations.h"

using namespace sf; 
int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600), "Game", sf::Style::Close | sf::Style::Default);
	
	

	sf::Texture bodyTexture, enermy1Texture;
	enermy1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf2.png");
	bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");

	sf::Sprite body, enermy1;
	enermy1.setTexture(enermy1Texture);
	body.setTexture(bodyTexture);

	////// เรียกใช้ฟังขั่น  (ตัวTexture , จำนวน (แถว,คอลั่ม) , ความเร็วในการ switch )
	animations animations(&bodyTexture, Vector2u(4, 4), 0.4f) 
		      ,animations2(&enermy1Texture,Vector2u(4,4), 0.9f) ;
    
	


	///// ตั้งให้ deltaTime เป็น 0 แล้วเรียกคำสั่ง clock ซึ่งจะวิ่งค่าเวลาไปเรื่อยๆ
	float deltaTime = 0.f;
	Clock clock;



	while (window.isOpen())
	{   //// จะนับเวลาขึ้น เเล้วก้ restart เป็น 0 วนไป จับค่าเท่ากับ deltaTime
		deltaTime = clock.restart().asSeconds();
		
	
	



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			body.move(-5.f, 0.f);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			body.move(5.f, 0.f);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			body.move(0.f, 0.5f);
			
		}
	
		

		/////// จะอัพเดทให้ player มีการขยับอยู่ตลอดเวลา ตามภาพ png แถวที่ 0 
		animations.Update(0, deltaTime, false);
		animations2.Update(0, deltaTime, true);

		///// ใช้คำสั่ง uvrect ในheader animations คำนวณกำหนดกรอบให้ bodySprite และกำหนดให้แสดงภาพแต่ละจุด ex (0,1) (0,2) ...
		body.setTextureRect(animations.uvrect);
		enermy1.setTextureRect(animations2.uvrect);


		window.clear();
		window.draw(body);
		window.draw(enermy1);

		window.display();
		
	
		
	}
		return 0;

}

