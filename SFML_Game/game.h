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
#include "animations.h"
#include "object.h"
#include "Enermy.h"
#include "Item.h"
#include "PauseMenu.h"

using namespace sf;

class game
{

private:
	
	//Variable
	sf::Vector2f sizebg;
	sf::Vector2u imageCount;
	sf::Vector2f BgPos;
	float spawnTimer;
	float spawnTimerMax;
	float itemtimer;
	float itemtimerMax;
	bool quit;
	bool paused;

	float gapOb_y;
	float forwardOb;

	
	//Window
	
	sf::Event ev;
	sf::Font font;
	sf::Text pointText;

	
	
	//View
	sf::View mainView;
	
	
	//Private Functions
	
	void pollEvent();
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

	
	std::vector<Enermy*> enemies;
	Enermy* enermy;
	Player* player;
	Item* item;
	object *Object,*Object2;
	//PauseMenu pmenu;
	
	
	
public:

	//constructor 
	game();
	void regame();

	
	//variable
	float deltaTime = 0.f;
	sf::Clock clock;
	sf::RenderWindow* window;

	//function
	
	void run();



	void updateBg(const float& dt);
	void updateInput(const float& dt);
	void update();
	void render();
	void endState();
	void pauseState();
	void unpauseState();


	void chasing(const float& dt);
	void randomObject();
	void updateSpawnOb(sf::RectangleShape* ob, float gabOb_y, float forwardOb);
	void randomenemies();
	void updateCollision();
	
	
	sf::RectangleShape* bg[3], 
					  * sandbar1,* sandbar2,* sandbar3,* sandbar4,
					  * port[3];
	sf::Texture bodyTexture, 
				enermyTexture, 
				sandbar1Texture,  sandbar2Texture,sandbar3Texture ,sandbar4Texture, 
				bgTexture, 
				speedTexture, 
				objectTexture,
				portTexture[3];
	
}; 
