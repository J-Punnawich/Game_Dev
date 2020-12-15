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
#include <SFML/Audio.hpp>
using namespace sf; 
bool sortinrev(const pair<int, string>& a, const pair<int, string>& b)
{
	return(a.first > b.first);
}
int main()
{	
	
	sf::Music music1;
	if (!music1.openFromFile("C:/source/repos/Game_Dev/SFML_Game/playmusic.ogg"))
	{
		printf("Error \n");
	}


	music1.play();
	music1.setVolume(40);
	music1.setLoop(true);
	
	

	std::srand(static_cast<unsigned>(time(NULL)));



	game Game;




	Game.menuState = true;


	sf::Font font;
	if (!font.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/fonts/FFFFORWA.ttf"))
	{
		std::cout << "Error::Game::titlefont:: could not load FFFFORWA.ttf" << "\n";
	}



	vector<pair<int, string>>pairScoreName;
	ifstream Ifile("HighscoreFile.txt");
	sf::Text highscoreNameText[5], highscoreScoreText[5], highscoreTitle;
	highscoreTitle.setFont(font);
	highscoreTitle.setCharacterSize(48);
	highscoreTitle.setString("HIGHSCORE");
	highscoreTitle.setOrigin(highscoreTitle.getGlobalBounds().width, highscoreTitle.getGlobalBounds().height);
	highscoreTitle.setFillColor(sf::Color::Black);
	highscoreTitle.setPosition(500, 150);


	
	


	///////////////////////////////////////////////////////////////////////////////////////

	/*sf::RectangleShape object;
	object.setSize(sf::Vector2f(300.0f, 70.0f));
	object.setOrigin(sf::Vector2f(150.0f, 35.0f));
	object.setPosition(sf::Vector2f(800, 450.0f));

	sf::RectangleShape cursor;
	cursor.setSize(sf::Vector2f(5.0f, 64.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 32.0f));
	cursor.setPosition(sf::Vector2f(655, 450.0f));
	cursor.setFillColor(sf::Color::Black);

	float totalTime = 0;
	sf::Clock clock;
	bool state = false;

	char last_char = ' ';

	std::string input;

	//sf::Font font;
	//font.loadFromFile(""); //// <- Enter font here

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setPosition(655, 430);*/





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
		highscoreNameText[i].setPosition(sf::Vector2f(300,150 + 100 * (i + 1)));

		highscoreScoreText[i].setFont(font);
		highscoreScoreText[i].setFillColor(sf::Color::White);
		highscoreScoreText[i].setCharacterSize(40);
		highscoreScoreText[i].setPosition(sf::Vector2f(500,float(150 + 100 * (i + 1))));
	}
	

	while (Game.window->isOpen())
	{
		
		Game.millis = Game.timeMliis.getElapsedTime().asMilliseconds();
		
		

		while (Game.window->pollEvent(Game.evnt))
		{
			
			if (Game.evnt.type == sf::Event::Closed)
			{
				Game.window->close();
			}
		}

		if (Game.menuState == true)
		{
			Game.menu();
			
		}
		



		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{

			Game.menuState = false;
			Game.endGame = true;

		}

		if (Game.playState == true)
		{
			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Game.menuState = true;
				Game.playState = false;
				
				
			}
			

			else if (Game.endGame == true) //แพ้
			{

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && Game.millis - Game.delay > 300 && Game.playerName.length() > 0)
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
					Game.playerName = " ";
					Game.playerNametext.setString(Game.playerName);
					Game.cursor.setPosition(480, 460);
					Game.playState = false;
					Game.window->close();
				}
				/////////////////////////////////////////////////

				if ((Game.evnt.type) == (sf::Event::EventType::TextEntered))
				{
					
					
					if (Game.last_char != Game.evnt.text.unicode && Game.evnt.text.unicode == 8 && Game.playerName.length() > 0) // delete
					{
						Game.last_char = Game.evnt.text.unicode;
						Game.playerName.erase(Game.playerName.length() - 1);
						Game.playerNametext.setString(Game.playerName);
						Game.cursor.setPosition(400.0f + Game.playerNametext.getGlobalBounds().width + 5, 455.0f);


					}
					else if (Game.playerName.length() < 12 && Game.last_char != Game.evnt.text.unicode &&
						(Game.evnt.text.unicode >= 'a' && Game.evnt.text.unicode <= 'z' ||
							Game.evnt.text.unicode >= 'A' && Game.evnt.text.unicode <= 'Z' ||
							Game.evnt.text.unicode >= '0' && Game.evnt.text.unicode <= '9'))
					{



						Game.last_char = Game.evnt.text.unicode;

						Game.playerName += Game.evnt.text.unicode;

						Game.playerNametext.setString(Game.playerName);

						Game.cursor.setPosition(480.0f + Game.playerNametext.getGlobalBounds().width + 5, 455.0f);
					}

				}

				if (Game.evnt.type == sf::Event::EventType::KeyReleased && Game.last_char != ' ')
				{
					Game.last_char = ' ';
				}

				

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
				Game.scoreText.setString(Game.mm.str());

				Game.window->draw(Game.endGameText);
				Game.window->draw(Game.scoreText);
				Game.window->draw(Game.YourScoreText);
				Game.window->draw(Game.EnterYourNameText);
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

		
			if (Game.scoreState == true)
			{

				Game.window->clear(sf::Color(49, 193, 217));
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

			if (Game.howtoplayState == true)
			{

				Game.window->clear(sf::Color(49, 193, 217));
				Game.window->draw(Game.toMove);
				Game.window->draw(Game.touseItem);
				Game.window->draw(Game.howtoplayPic[0]);
				Game.window->draw(Game.howtoplayPic[1]);
				Game.window->draw(Game.howtoplayPic[2]);
				Game.window->draw(Game.howtoplayPic[3]);
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					Game.menuState = true;
					Game.howtoplayState = false;
				}
				Game.window->display();

			}



	}

}
