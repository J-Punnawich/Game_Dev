#pragma once

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
	Enermy* enermy;
	Player* player;
	object* Object;
	
	sf::Texture bodyTexture,enermyTexture,sandbarTexture;
	
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
	
	
	
	
};
