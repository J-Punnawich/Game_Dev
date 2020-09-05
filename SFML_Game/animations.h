
#include <SFML/Graphics.hpp>
#include<iostream>


class animations
{    
public:
	animations(sf::Texture* texture, sf::Vector2u imageCount , float switchTime);

	void Update(int row, float deltaTime);



public: 
	sf::IntRect uvrect;

private: 
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

