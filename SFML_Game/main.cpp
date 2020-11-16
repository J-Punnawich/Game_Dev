#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "animations.h"
#include "Player.h"
#include "game.h"
#include "object.h"
#include "Item.h"
#include "Platform.h"
#include <Vector>
#include <fstream>
#include <sstream>
using namespace sf; 
bool sortinrev(const pair<int, string>& a, const pair<int, string>& b)
{
	return(a.first > b.first);
}
int main()
{  
	/// use 1720,1000
	//sf::RenderWindow window(sf::VideoMode(800,600), "Game", sf::Style::Close | sf::Style::Default);
	
	
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
	} */




	sf::Font font;
	if (!font.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/fonts/FFFFORWA.ttf"))
	{
		std::cout << "Error::Game::titlefont:: could not load FFFFORWA.ttf" << "\n";
	}

	
	

	


	



vector<pair<int, string>>pairScoreName;
ifstream Ifile("HighscoreFile.txt");
sf::Text highscoreNameText[5], highscoreScoreText[5], highscoreTitle;
highscoreTitle.setFont(font);
highscoreTitle.setCharacterSize(70);
highscoreTitle.setString("HIGHSCORE");
highscoreTitle.setOrigin(highscoreTitle.getGlobalBounds().width, highscoreTitle.getGlobalBounds().height);
highscoreTitle.setFillColor(sf::Color::White);
highscoreTitle.setPosition(200 + 1333 / 2, 50 + 768 / 20);

string line;
do
{
	Ifile >> line;
	string highscoreScore = line.substr(0, line.find(','));
	string highscoreName = line.substr(line.find(',') + 1, line.length());
	pairScoreName.push_back(make_pair(atoi(highscoreScore.c_str()), highscoreName));
} while (Ifile.good());//Read until EOF
sort(pairScoreName.begin(), pairScoreName.end(), sortinrev);
Ifile.close();
for (int i = 0; i < 5; i++)
{
	highscoreNameText[i].setString(pairScoreName[i].second);
	highscoreScoreText[i].setString(to_string(pairScoreName[i].first));
}
for (int i = 0; i < 5; i++)
{
	highscoreNameText[i].setFont(font);
	highscoreNameText[i].setFillColor(sf::Color::White);
	highscoreNameText[i].setCharacterSize(40);
	highscoreNameText[i].setPosition(sf::Vector2f(320, 100 + 100 * (i + 1)));

	highscoreScoreText[i].setFont(font);
	highscoreScoreText[i].setFillColor(sf::Color::White);
	highscoreScoreText[i].setCharacterSize(40);
	highscoreScoreText[i].setPosition(sf::Vector2f(800, 100 + 100 * (i + 1)));
}

	 
	while (Game.window->isOpen())
	{

		if (Game.menuState == true)
		{
			Game.menu();
			
		}

		if (Game.playState == true)
		{
			
			//Game.pollEvent();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Game.menuState = true;
				Game.playState = false;
			}

			if (Game.endGame == true) //แพ้
			{    
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && Game.millis - Game.delay >= 300 && Game.playerName.length() > 0)
				{
					Game.delay = Game.millis;
					Game.endGame = false;
					Game.menuState = true;
					pairScoreName.push_back(make_pair(Game.Score, Game.playerName));
					sort(pairScoreName.begin(), pairScoreName.end(), sortinrev);

					ofstream highscoreWriter;
					highscoreWriter.open("HighscoreFile.txt");
					for (int i = 0; i < 5; i++)//only write top 5 score
					{
						highscoreWriter << pairScoreName[i].first << "," << pairScoreName[i].second << "\n";
					}
					highscoreWriter.close();

					Ifile.open("HighscoreFile.txt");
					pairScoreName.clear();
					do
					{
						Ifile >> line;
						string highscoreScore = line.substr(0, line.find(','));
						string highscoreName = line.substr(line.find(',') + 1, line.length());
						pairScoreName.push_back(make_pair(atoi(highscoreScore.c_str()), highscoreName));
					} while (Ifile.good());//Read until EOF
					Ifile.close();
					for (size_t i = 0; i < 5; i++)
					{
						highscoreNameText[i].setString(pairScoreName[i].second);
						highscoreScoreText[i].setString(to_string(pairScoreName[i].first));
					}
					Game.playerName = "";
					Game.playerNametext.setString(Game.playerName);
					Game.cursor.setPosition(480, 450);
				}
				/////////////////////////////////////////////////
				if (Game.evnt.type == sf::Event::EventType::TextEntered)
				{
					if (Game.last_char != Game.evnt.text.unicode && Game.evnt.text.unicode == 8 &&
						Game.playerName.length() > 0) // delete
					{
						Game.last_char = Game.evnt.text.unicode;
						Game.playerName.erase(Game.playerName.length() - 1);
						Game.playerNametext.setString(Game.playerName);
						Game.cursor.setPosition(480.0f + Game.playerNametext.getGlobalBounds().width + 5, 450.0f);

					}
					else if (Game.playerName.length() < 12 && Game.last_char != Game.evnt.text.unicode &&
						(Game.evnt.text.unicode >= 'a' && Game.evnt.text.unicode <= 'z' ||
							Game.evnt.text.unicode >= 'A' && Game.evnt.text.unicode <= 'Z' ||
							Game.evnt.text.unicode >= '0' && Game.evnt.text.unicode <= '9'))
					{
						Game.last_char = Game.evnt.text.unicode;

						Game.playerName += Game.evnt.text.unicode;

						Game.playerNametext.setString(Game.playerName);

						Game.cursor.setPosition(480.0f + Game.playerNametext.getGlobalBounds().width + 5, 450.0f);
					}

				}

				if (Game.evnt.type == sf::Event::EventType::KeyReleased && Game.last_char != ' ')
				{
					Game.last_char = ' ';
				}
				//scoreText.setPosition(700, 320);
				Game.window->clear();
				Game.window->draw(Game.bar);
				Game.totalTime += Game.clock.restart().asSeconds();
				if (Game.totalTime >= 0.5)
				{
					Game.totalTime = 0;
					Game.state = !Game.state;
				}
				if (Game.state == true)
				{
					Game.window->draw(Game.cursor);
				}
				Game.window->draw(Game.endGameText);
				//Game.window->draw(scoreText);
				//Game.window.draw(YourScoreText);
				//window.draw(EnterYourNameText);
				Game.window->draw(Game.playerNametext);
				Game.window->display();
			}
			else
			{
				Game.deltaTime = Game.clock.restart().asSeconds();
				Game.update();
				Game.render();
			}
		}


			
		}
		if (Game.scoreState == true)
		{
			Game.window->clear();
			Game.window->draw(highscoreTitle);
			for (int i = 0;i < 5;i++)
			{
				Game.window->draw(highscoreNameText[i]);
				Game.window->draw(highscoreScoreText[i]);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Game.menuState = true;
				Game.scoreState = false;
			}

			Game.window->display();
		}

	}
	
	
	



