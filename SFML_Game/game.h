#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <ctime>
#include <sstream>

#include "player.h"
#include "animations.h"
#include "Enermy.h"
#include "object.h"
#include "Item.h"

using namespace sf;

class game
{
private:
	
	//Variable
	float spawnTimer;
	float spawnTimerMax;
	
	sf::Vector2u imageCount;
	
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::Font font;
	sf::Text pointText;

	
	
	//View
	sf::View mainView;
	
	
	//Private Functions
	void pollEvent();
	void titleWindow();
	void titlePlayer();
	void titleEnermy();
	void titleObject();
	void titleItem();
	void titleFont();
	void titleText();
	void ResizeView(sf::RenderWindow& window,sf::View& view);
	void renderGUI(sf::RenderTarget* targetGUI);
	void updateGUI();


	//Game objects
	std::vector<Enermy*> enemies;
	Enermy* enermy;
	Player* player;
	object* Object;
	Item*   item;

	sf::RectangleShape* bg1;
	sf::Texture bodyTexture,enermyTexture,sandbar1Texture, sandbar2Texture,bgTexture,speedTexture;
	
	
public:

	//constructor 
	game();
	void regame();

	
	//variable
	float deltaTime = 0.f;
	sf::Clock clock;


	//function
	
	void run();

	void update();
	void render();

	
	
	void randomenemies();
	void updateCollision();
	
	
}; 
