#include "animations.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class player
{ 
public:
	player();

	void Update(float deltaTime);
	void Draw(RenderWindow window);
private: 
	Texture playerTexture;
	animations animations;
	float speed;
};

