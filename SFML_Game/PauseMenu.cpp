#include "PauseMenu.h"
#include "game.h"


PauseMenu::PauseMenu(sf::RenderWindow& window)
{ 
	this->background.setSize(
		sf::Vector2f(
		static_cast<float>(window.getSize().x), 
		static_cast<float>(window.getSize().x)
		)
	);
	
	this->background.setFillColor(sf::Color(20, 20, 20, 100));

	this->container.setSize(sf::Vector2f(
		static_cast<float>(window.getSize().x) / 4.f,
		static_cast<float>(window.getSize().y)));

	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(
		static_cast<float>(window.getSize().x) / 2.f - this->container.getSize().x / 2.f,
		0.f
	);
}

PauseMenu::~PauseMenu()
{
	
}



void PauseMenu::update()
{
}

void PauseMenu::render(sf::RenderTarget& target)
{
	target.draw(background);
	target.draw(container);
}
