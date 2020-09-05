#include <SFML/Graphics.hpp>
#include <iostream>
#include "animations.h"

using namespace sf; 
int main()
{
	
	RenderWindow window(VideoMode(1440, 980), "Game from scratch!", Style::Default);
	
	Texture playerTexture;
	playerTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
	playerTexture.setSmooth(true);
	playerTexture.setRepeated(true);



	

	////// Square
	RectangleShape collision(Vector2f(100.f,100.f));
	collision.setPosition(500.f, 500.f );
	collision.setFillColor(Color(255,200,100,100));
	


	
	
	////// เรียกใช้ฟังขั่น (ตัวTexture , จำนวน (แถว,คอลั่ม) , ความเร็วในการ switch )
	animations animations(&playerTexture, Vector2u(4, 4), 0.4f);
	
	///// สร้างจุดเกิดของ sprite 
	sf::Vector2f spawnPoint = { 200.f, 0.f };
	body.setPosition(spawnPoint);
	

	///// ตั้งให้ deltaTime เป็น 0 แล้วเรียกคำสั่ง clock ซึ่งจะวิ่งค่าเวลาไปเรื่อยๆ
	float deltaTime = 0.f;
	Clock clock;

	while (window.isOpen())
	{   //// จะนับเวลาขึ้น เเล้วก้ restart เป็น 0 วนไป จับค่าเท่ากับ deltaTime
		deltaTime = clock.restart().asSeconds();
		
		//Event evnt;
		//while (window.pollEvent(evnt))
		//{
			
	
			/////// Movement การเคลื่อนที่ 

			//playerSprite.move(0.f, .2f);
			if (Keyboard::isKeyPressed(Keyboard::D))
			{

				
				body.move(.2f, 0.f);


			}
			else if (Keyboard::isKeyPressed(Keyboard::S))
			{
				

				body.move(0.f, .2f);
			}
			else if (Keyboard::isKeyPressed(Keyboard::A))
			{
				
				body.move(-.2f, 0.f);
			}
			else if (Keyboard::isKeyPressed(Keyboard::W))
			{
				
				body.move(0.f, -.2f);
			}
			

			/////// เช็คว่าวัตถุชนกันไหม
			if (collision.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
			{  
				playerSprite.setPosition(0.f, 0.f);
			}

			//if (evnt.type == evnt.Closed)
			//{
			//	window.close();
			//}
			if (Keyboard::isKeyPressed(Keyboard::Escape)) 
			{  // ถ้ากด x จะปิด
				window.close();
			} 

			
		//}

			/////// จะอัพเดทให้ player มีการขยับอยู่ตลอดเวลา ตามภาพ png แถวที่ 0 
			animations.Update(0, deltaTime);
		    
		   /////// ใช้คำสั่ง uvrect คำนวณกำหนดกรอบให้ playerSprite และกำหนดให้แสดงภาพแต่ละจุด ex (0,1) (0,2) ...
		playerSprite.setTextureRect(animations.uvrect);

		
		window.draw(collision);
		window.display();
		window.clear();
	}
		return 0;

}
