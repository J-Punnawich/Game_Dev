#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <map>
#include <vector>
#include <ctime>
#include <sstream>

#include "player.h"
#include "Collider.h"
#include "animations.h"
#include "object.h"
#include "Platform.h"
#include "Enermy.h"
#include "Item.h"
#include "PauseMenu.h"

using namespace sf;
using namespace std;
class game
{

private:
	
	//Variable
	sf::Vector2u imageCount;
	float spawnTimer;
	float spawnTimerMax;
	float speedNow;
	float itemtimer;
	float itemtimerMax;
	float timeCount;	
	float timeSet;
	unsigned hpMax;
	unsigned hp;
	bool quit;
	
	int mode;
	bool paused;
	
	bool showScore;
	bool fck = true;


	

	//Window
	
	
	sf::Font font;
	sf::Text pointText;
	
	sf::Text highscoreNameText[5], highscoreScoreText[5], highscoreTitle;
	sf::Text StartText, howtoPlay,ScoreText,QuitText;
	
	//View
	sf::View mainView;
	
	
	//Private Functions
	
	

	
	
	


	
	bool sortinrev(const pair<unsigned, string>& a, const pair<unsigned, string>& b);
	void titleWindow();
	void titlebg();
	void titlePlayer();
	void titleEnermy();
	void titleObject();
	void titleItem();
	void titleFont();
	void titleText();
	void titlehighScore();
	
	//void titlePmenu();

	void ResizeView(sf::RenderWindow& window,sf::View& view);
	void renderGUI(sf::RenderTarget* targetGUI);
	void updateGUI();


	//Game objects

	
	std::vector<object> Objects;
	std::vector<Platform> Platforms;
	Enermy* enermy;
	Player* player;
	Item* item;
	object *Object;
	Platform *platform;
	//Collider* playerCollision;
	
	//PauseMenu pmenu;
	
	
	
public:

	//constructor 
	game();
	void regame();

	
	//variable
	float deltaTime = 0.f;
	sf::Clock clock;

	bool scoreState;
	bool menuState;
	bool playState;
	bool endGame;
	int Score;
	sf::RectangleShape bar;
	sf::RectangleShape cursor;
	sf::Clock timeMliis;
	sf::Clock timeSec;
	unsigned long millis;
	int delay = 0 ;
	unsigned long timeGame;
	unsigned long pausetimeGame;
	sf::RenderWindow* window;
	sf::Event evnt;
	sf::Text endGameText;



	float totalTime = 0;

	bool state = false;

	char last_char = ' ';

	std::string playerName;

	sf::Text playerNametext;
	//function
	
	void run();


	void pollEvent();
	void updateBg(const float& dt);
	void updateInput(const float& dt);
	void update();
	void render();
	void endState();
	void pauseState();
	void unpauseState();
	void menu();
	void highScoreMenu();

	void chasing(const float& dt);
	void randomObject();
	void updateSpawnOb(sf::RectangleShape* ob, float gabOb_y, float forwardOb);
	void randomenemies();
	void updateCollision();
	void itemTimer();
	
	sf::RectangleShape* bg[6], 
					  * sandbar1,* sandbar2,* sandbar3,* sandbar4,
					  * port[3],
					  * heart[3];

	sf::CircleShape Select;

	sf::Texture bodyTexture, 
				enermyTexture, 
				sandbar1Texture,  sandbar2Texture,sandbar3Texture ,sandbar4Texture, 
				bgTexture, 
				speedTexture, 
				objectTexture,
				interfaceTexture,
				portTexture[3];
	
}; 
