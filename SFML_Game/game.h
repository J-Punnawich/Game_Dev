#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

#include "player.h"
#include "animations.h"
#include "Enermy.h"
#include "object.h"

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
	
	
	
	//Private Functions
	void pollEvent();
	void titleWindow();
	void titlePlayer();
	void titleEnermy();
	void titleObject();

	//Game objects

	std::vector<Enermy*> enemies;
	Enermy* enermy;
	Player* player;
	object* Object;

	sf::RectangleShape* bg1,body, enermy1;
	sf::Texture bodyTexture,enermyTexture,sandbarTexture,bgTexture;
	//sf::Sprite body, enermy1;
	
public:

	//constructor 
	game();
	void regame();

	
	//variable
	float deltaTime = 0.f;
	sf::Clock clock;


	//function
	
	void run();

	void upenemies();

	void update();
	void render();
	
	
	
	
};
