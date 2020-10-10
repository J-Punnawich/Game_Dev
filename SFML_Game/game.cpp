/*#include "game.h"
#include "player.h"

//Private Functions
void game::titleVariable()
{
    this->window = nullptr;
   
}

void game::titleWindow()
{
    this->videoMode.height = 800;
    this->videoMode.width = 600;
    this->window = new sf::RenderWindow(this->videoMode, "Game",sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
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
void game::titlePlayer()
{
    this->Player = new  player();
}


//Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
 
game::game()  /// เรียกใช้ฟังชั่นตัวแปรเริ่มต้น กับ หน้าต่างเริ่มต้น
{
    this->titleVariable();
    this->titleWindow();
    this->titlePlayer();
    this->pollEvent();
}

void game::regame()
{
    delete this->window;
    delete this->Player;
}
    
//checker
const bool game::running() const
{
    return this->window->isOpen();
}





///Functions    /// ต้องเรียกใช้เป็นจุดๆไป เช่น game.update

void game::updatplayer()
{
    this->Player->Update();
}

void game::renderplayer()
{
    this->Player->render(this->window);
}





 
void game::update()
{
    this->pollEvent();
    this->updatplayer();
    
   

}




void game::render()
{
    this->window->clear(sf::Color(0, 150, 150));


    ///render stuff
    this->renderplayer();
    
    

    this->window->display(); //ต้องเอาไว้ล่างสุด
    
    
}*/






