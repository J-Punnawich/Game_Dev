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
	sf::Vector2f moveVec;
	float spawnTimer;
	float spawnTimerMax;
	float speedNow;
	float itemtimer;
	float itemtimerMax;
	float timeCount;	
	float timeSet;
	unsigned hpMax = 3;
	unsigned hp = 3;
	unsigned int  storeItem = 0;
	unsigned storeMax = 0;
	bool quit;
	bool spawnEnermy = false;
	
	
	
	bool showScore;
	bool fck = true;


	

	//Window
	
	
	sf::Font font;
	
	
	sf::Text highscoreNameText[5], highscoreScoreText[5], highscoreTitle;
	sf::Text StartText, howtoPlay,ScoremenuText,QuitText;
	
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
	animations* Animation;
	//Collider* playerCollision;
	
	//PauseMenu pmenu;
	
	
	
public:

	//constructor 
	game();


	
	//variable
	float deltaTime = 0.f;
	sf::Clock clock;
	std::stringstream mm;
	bool scoreState;
	bool howtoplayState;
	bool menuState;
	bool playState;
	bool endGame;
	bool gethp = false;
	bool losshp = false;
	int Score;
	sf::RectangleShape bar;
	sf::RectangleShape cursor;
	sf::Clock timeMliis;
	sf::Clock timeSec;
	unsigned long millis;
	
	unsigned long timeGame;
	unsigned long pausetimeGame;
	sf::RenderWindow* window;
	sf::Event evnt;
	sf::Text endGameText;
	bool paused;
	sf::SoundBuffer loadIn,loadIn2;
	sf::Sound sound,selectSound;

	int delay = 0;
	int delayEnermy = 0;
	int delayUseitem = 0;
	bool useItem = false;
	sf::Text pointText;
	int delayItem1 = 0;
	bool getItem1 = false;

	int delayItem2 = 0;
	bool getItem2 = false;

	int delayObject = 0;
	bool getObject = false;
	bool getObjectenermy = false;
	int delayObjectenermy1 = 0;
	int mode = 1;

	float totalTime = 0;

	bool state = false;

	char last_char = ' ';

	std::string playerName;

	sf::Text playerNametext,scoreText, YourScoreText, EnterYourNameText;
	sf::Text toMove,touseItem;
	//function
	
	void run();


	
	void updateBg(const float& dt);
	
	void update();
	void render();
	void endState();
	void pauseState();
	void unpauseState();
	void menu();
	void titlehowtoplay();

	bool distance(sf::RectangleShape* other, sf::RectangleShape* other2, sf::Vector2f dis);


	void chasing(const float& dt);
	void randomObject();
	void updateSpawnOb(sf::RectangleShape* ob, float gabOb_y, float forwardOb);
	
	void randomenemies();
	void updateCollision();
	void objectCollision();

	sf::RectangleShape* bg[6],
					  * bgMenu, 
					  * sandbar[4],
					  * port[3],
					  * heart[3],
					  * speed[3],
					  * ripple,
					   howtoplayPic[4];

	sf::CircleShape Select;

	sf::Texture bodyTexture, 
				enermyTexture, 
				sandbar1Texture,  sandbar2Texture,sandbar3Texture ,sandbar4Texture, 
				bgTexture,
				bgMenuTexture,
				speedTexture, 
				objectTexture,
				interfaceTexture,
				rippleTexture,
				portTexture[3],
				slowTexture;
	
}; 
