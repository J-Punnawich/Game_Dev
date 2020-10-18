#include "game.h"
#include "Player.h"
#include "animations.h"

//Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
void game::titleWindow()
{
   this->window = new  sf::RenderWindow (sf::VideoMode(800, 600), "Game", sf::Style::Close | sf::Style::Default);
   this->window->setFramerateLimit(60);
   this->window->setVerticalSyncEnabled(false);
}



void game::titlePlayer()
{
   
    this->bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
    this->player = new Player(&bodyTexture, sf::Vector2u(4, 4), 0.4f, 100.f);
    
    
}

void game::titleEnermy()
{
    this->enermyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/enermy1.png");
    this->enermy = new Enermy(&enermyTexture, sf::Vector2u(2, 6), 0.5f);
}

void game::titleObject()
{
    this->sandbarTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar.png");
    this->Object = new object(&sandbarTexture,sf::Vector2u(4,1),0.5f);
    this->Object->setUvrectObject(&sandbarTexture, sf::Vector2u(4,1));
   
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


 


/// เรียกใช้ฟังชั่นตัวแปรเริ่มต้น กับ หน้าต่างเริ่มต้น
game::game() 
{

    this->titleWindow();
    this->titlePlayer();
    this->pollEvent();
    this->titleEnermy();
    this->titleObject();
  
}

void game::regame()
{
    delete this->window;
    delete this->player;
    delete this->enermy;
   

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
  
    //update movement & animation Player
    this->player->Updateplayer(this->deltaTime);

    this->enermy->UpdateEnermy(this->deltaTime);
   
    
}




void game::render()
{
    this->window->clear(sf::Color(0, 150, 150));

    
    ///render stuff
    
   this->player->Drawplayer(*this->window);
   this->enermy->Drawenermy(*this->window);
   this->Object->DrawObject(*this->window);

   ///ต้องเอาไว้ล่างสุด
    this->window->display(); 
    
    
}





 