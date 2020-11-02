#include <iostream>
#include "game.h"
#include "Player.h"
#include "animations.h"

 ///Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
void game::titleWindow()
{
   this->window = new  sf::RenderWindow (sf::VideoMode(800, 600), "Game",sf::Style::Default);
   this->window->setFramerateLimit(80);
   this->window->setVerticalSyncEnabled(false);
    
   ///set size View
   mainView.setSize(800, 600);
   //mainView.setViewport(FloatRect(0,0,800,600));


   ///set bg
   bg1 = new sf::RectangleShape(sf::Vector2f(256.f, 256.f));
   bgTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/background.png");
   bg1->setTexture(&bgTexture);

   
}

void game::titlePlayer()
{
   
    this->bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
    
    this->player = new Player(&bodyTexture, sf::Vector2u(4, 4), 0.4f, 100.f);
    
    
}

void game::titleEnermy()
{   
   
    this->enermyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/enermy1.png");
    
    enermy = new Enermy(&enermyTexture, sf::Vector2u(2, 6), 0.3f);
    
    
    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;
        
}

void game::titleObject()
{
    this->sandbar1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar.png");
    this->sandbar2Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/test2.png");
  
    this->Object = new object(&sandbar1Texture, sf::Vector2u(4, 1), sf::Vector2u(0, 0));//, Objectsand2(&sandbar2Texture, sf::Vector2u(4, 1), sf::Vector2u(1, 0));
    
    

    this->Object->setUvrectObject(sf::Vector2u(4,1));
    //Objectsand2.setUvrectObject(sf::Vector2u(4,1));


   
}

void game::titleItem()
{   
    this->speedTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");
    item = new Item(&speedTexture, sf::Vector2u(8, 4), 0.5f);
    this->item->itemspeed.setOrigin(0.f, -500.f);
    
    //// set ให้ item ติดอยู่กับ player ตลอด
    //this->item->itemspeed.setPosition(this->player->body.getPosition().x, this->player->body.getPosition().y + 20);
}


void game::titleFont()
{
    if (!this->font.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/fonts/FFFFORWA.ttf"))
    {
        std::cout << "Error::Game::titlefont:: could not load FFFFORWA.ttf" << "\n" ;
    }
}

void game::titleText()
{
    this->pointText.setFont(this->font);
    this->pointText.setFillColor(sf::Color::Transparent);
    this->pointText.setCharacterSize(18);
    this->pointText.setPosition(380.f, 10.f);
  
}

void game::ResizeView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(800 * aspectRatio, 600);
}

void game::renderGUI(sf::RenderTarget* targetGUI)
{
    targetGUI->draw(this->pointText);
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
        case sf::Event::Resized:
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
    this->titleItem();
    this->titleObject();
    this->titleFont();
    this->titleText();
}

void game::regame()
{
    delete this->window;
    delete this->player;
    delete this->enermy;
    delete this->item;

}

///Functions    /// ต้องเรียกใช้เป็นจุดๆไป เช่น game.update

void game::run()
{
    while (this->window->isOpen())
    {
        
        this->update();
        this->render();
        this->pollEvent();


    }
    
}


void game::randomenemies()
{   ///เวลาในการ spawn
    this->spawnTimer += 0.4f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {   
        this->enermy->spawnEnermy(this->player->body.getPosition().x + rand()%400, this->mainView.getCenter().y - 400 );
        this->spawnTimer = 0.f;
    }
  
}

void game::updateCollision()
{
    if (this->player->getGlobalBounds().intersects(this->enermy->getGlobalBounds())) //เช็คชน enermy
    {
        this->player->setPosition();
        
    }

    if (this->player->getGlobalBounds().intersects(this->item->getGlobalBounds())) //เช็คชนไอเท็ม
    {
        item->itemspeed.setPosition(this->player->body.getPosition().x + (rand()%500)+300 , (this->player->body.getPosition().y +(rand()%900))+100);
        std::cout <<"item pos"<< item->itemspeed.getPosition().x << "   "<<item->itemspeed.getPosition().y;
      
    }
}


void game::updateGUI()
{
    std::stringstream mm;

    
    mm << this->player->getPoints() << " m";


    this->pointText.setString(mm.str());

}


///
void game::update()
{   
    this->deltaTime = clock.restart().asSeconds();
    this->pollEvent();
    std::cout <<"\n "<< this->player->body.getPosition().x << "  " << this->player->body.getPosition().y;
    ///update movement & animations
    this->mainView.setCenter((this->player->body.getPosition().x), (this->player->body.getPosition().y));
    // std::cout << << "\n" ;
    this->player->Updateplayer(this->deltaTime);
    this->enermy->UpdateEnermy(this->deltaTime);
    this->item->UpitemSpeed(this->deltaTime);

    ///enermies and collision
    this->updateCollision();
    this->randomenemies();
    
    ///GUI
    this->renderGUI(this->window);
    this->player->getPoints();
    this->updateGUI();
}


void game::render()
{
    this->window->clear(sf::Color(0, 150, 150));

    
    ///render stuff
    this->window->setView(mainView);
    this->window->draw(*this->bg1);
    
    this->player->Drawplayer(*this->window);
    this->enermy->Drawenermy(*this->window);
    this->Object->DrawObject(*this->window);
    this->item->Drawitem(*this->window);
    
    
    
    //ทำให้ GUI อยู่ในขอบ View ด้วย
   this->window->setView(window->getDefaultView());
   this->renderGUI(this->window);
    ///ต้องเอาไว้ล่างสุด
    this->window->display(); 
    

}






 