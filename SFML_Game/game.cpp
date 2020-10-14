#include "game.h"
#include "Player.h"
#include "animations.h"


void game::titleWindow()
{
   this->window =      new  sf::RenderWindow (sf::VideoMode(800, 600), "Game", sf::Style::Close | sf::Style::Default);
   this->window->setFramerateLimit(60);
   this->window->setVerticalSyncEnabled(false);
}

void game::titlePlayer()
{
    this->bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
    this->player = new Player(&bodyTexture,sf::Vector2u(4,4),0.4f,100.f);
}

void game::pollEvent()
{
    

   while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();

                break;

            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Key::Escape)
                {
                    this->window->close();
                }
                break;

        }
    }
}






//Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
 
game::game()  /// เรียกใช้ฟังชั่นตัวแปรเริ่มต้น กับ หน้าต่างเริ่มต้น
{
    
    this->titleWindow();
    this->titlePlayer();
   
   // this->pollEvent();
}

void game::regame()
{
    delete this->window;
    delete this->player;
}
    


///Functions    /// ต้องเรียกใช้เป็นจุดๆไป เช่น game.update



void game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();

    }
    
}

void game::update()
{
    this->deltaTime = clock.restart().asSeconds();
  
    this->pollEvent();
    
    this->player->Update(this->deltaTime);
    
   

}




void game::render()
{
    this->window->clear(sf::Color(0, 150, 150));


    ///render stuff
    
   this->player->Draw(*this->window);

 

    this->window->display(); //ต้องเอาไว้ล่างสุด
    
    
}





 