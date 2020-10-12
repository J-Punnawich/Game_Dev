/*#pragma once

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

	//Private Functions
	void pollEvent();
	void titleVariable();

	void titleWindow();
	void titlePlayer();



	//Game objects
	Player  *player;
	
	

public:

	//constructor 
	game();
	void regame();


	//checker
	const bool running() const;

	//function
	
	void update();
	void render();
	
	

	
	
};*/