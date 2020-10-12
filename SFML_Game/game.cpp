/*#include "game.h"
#include "Player.h"
#include "animations.h"

void game::titleWindow()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Close | sf::Style::Default);
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





//Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
 
game::game()  /// เรียกใช้ฟังชั่นตัวแปรเริ่มต้น กับ หน้าต่างเริ่มต้น
{
    this->titleVariable();
    this->titleWindow();
   
    this->pollEvent();
}

void game::regame()
{
    delete this->window;
    delete this->player;
}
    
//checker
const bool game::running() const
{
    return this->window->isOpen();
}






///Functions    /// ต้องเรียกใช้เป็นจุดๆไป เช่น game.update

 







void game::update()
{
    this->pollEvent();
    this->player->Update(this->);
    
   

}




void game::render()
{
    this->window->clear(sf::Color(0, 150, 150));


    ///render stuff
    
    this->player->Draw(this->window);
    
    

    this->window->display(); //ต้องเอาไว้ล่างสุด
    
    
}*/






 