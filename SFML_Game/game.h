#pragma once

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

#include "player.h"
#include "animations.h"



class game
{
private:
	
	//Variable

	
	//Window
	sf::RenderWindow* window;
	
	sf::Event ev;
	sf::Vector2u imageCount;
	
	
	//Private Functions
	void pollEvent();
	void titleWindow();
	void titlePlayer();



	//Game objects
	Player * player;
	sf::Texture bodyTexture;

public:

	//constructor 
	game();
	void regame();


	//checker
	

	//function
	
	void run();

	void update();
	void render();
	
	
	float deltaTime = 0.f;
	sf::Clock clock;
	
	
};