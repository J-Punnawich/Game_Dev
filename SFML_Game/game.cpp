#include <iostream>
#include "game.h"
#include "Player.h"
#include "animations.h"
#include "PauseMenu.h"

 ///Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
void game::titleWindow()
{
   this->window = new  sf::RenderWindow (sf::VideoMode(1720, 1080), "Game",sf::Style::Default);
   this->window->setFramerateLimit(80);
   this->window->setVerticalSyncEnabled(false);
    
   ///set size View
   mainView.setSize(1080,720);
   
   //mainView.setViewport(FloatRect(0,0,800,600));

   this->quit = false;
   this->paused = false;
}

void game::titlebg()
{
    

    bg[0] = new sf::RectangleShape(sf::Vector2f(1080.f, 720.f));
    bg[1] = new sf::RectangleShape(sf::Vector2f(1080.f, 720.f));
    bg[2] = new sf::RectangleShape(sf::Vector2f(1080.f, 720.f));
    
    bgTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/bg2.png");
    
    
    bg[0]->setTexture(&bgTexture);
    bg[1]->setTexture(&bgTexture);
    bg[2]->setTexture(&bgTexture);
    
    bg[1]->setPosition(bg[0]->getPosition().x, bg[0]->getPosition().y + bg[0]->getSize().y);

    bg[2]->setPosition(bg[1]->getPosition().x, bg[1]->getPosition().y + bg[1]->getSize().y);
    
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
    this->objectTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/objects64.png");
    

    this->Object  = new object(&objectTexture, sf::Vector2u(30, 1));
    

    this->Object->uvrectOb(&Object->ob[0], sf::Vector2u(0, 0));
    this->Object->uvrectOb(&Object->ob[1], sf::Vector2u(1, 0));
    this->Object->uvrectOb(&Object->ob[2], sf::Vector2u(2, 0));
    this->Object->uvrectOb(&Object->ob[3], sf::Vector2u(3, 0));
    this->Object->uvrectOb(&Object->ob[4], sf::Vector2u(4, 0));
    this->Object->uvrectOb(&Object->ob[5], sf::Vector2u(5, 0));
    this->Object->uvrectOb(&Object->ob[6], sf::Vector2u(6, 0));
    this->Object->uvrectOb(&Object->ob[7], sf::Vector2u(7, 0));
    this->Object->uvrectOb(&Object->ob[8], sf::Vector2u(8, 0));
    this->Object->uvrectOb(&Object->ob[9], sf::Vector2u(9, 0));
    this->Object->uvrectOb(&Object->ob[10], sf::Vector2u(10, 0));
    this->Object->uvrectOb(&Object->ob[11], sf::Vector2u(11, 0));
    this->Object->uvrectOb(&Object->ob[12], sf::Vector2u(12, 0));
    this->Object->uvrectOb(&Object->ob[13], sf::Vector2u(13, 0));
   

    this->Object->ob[1].setPosition(float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[2].setPosition(-float(rand() % 1000), float(rand() %2000));
    this->Object->ob[3].setPosition(-float(rand() % 500), float(rand() % 2000));
    this->Object->ob[4].setPosition(float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[5].setPosition(float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[6].setPosition(float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[7].setPosition(float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[8].setPosition(-float(rand() % 1000), float(rand() % 2000));
    this->Object->ob[9].setPosition(-float(rand() % 500), float(rand() % 2000));
    this->Object->ob[10].setPosition(float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[11].setPosition(-float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[12].setPosition(float(rand() % 1080), float(rand() % 2000));
    this->Object->ob[13].setPosition(-float(rand() % 1080), float(rand() % 2000));

    


    ///
    sandbar1 = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));
    sandbar2 = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));
    sandbar3 = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));
    sandbar4 = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));

    sandbar1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar1.png");
    sandbar2Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar2.png");
    sandbar3Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar3.png");
    sandbar4Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar4.png");

    sandbar1->setTexture(&sandbar1Texture);
    sandbar2->setTexture(&sandbar2Texture);
    sandbar3->setTexture(&sandbar3Texture);
    sandbar4->setTexture(&sandbar4Texture);
  
    sandbar1->setPosition(float(rand() % 1080) ,float(rand() % 500) );
    sandbar2->setPosition( - float(rand() % 1080),float(rand() % 1200));
    sandbar3->setPosition(float(rand() % 1900) ,float(rand() % 1500));
    sandbar4->setPosition( - float(rand() % 1080),float(rand() % 1900));


    ///
    port[0] = new sf::RectangleShape(sf::Vector2f(192.f, 128.f));

    this->portTexture[0].loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/port1.png");

    port[0]->setTexture(&portTexture[0]);

    port[0]->setPosition(float(rand() % 1080), float(rand() % 500));
   
}

void game::titleItem()
{   
    this->speedTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");
    
    item = new Item(&speedTexture, sf::Vector2u(8, 4), 0.5f);
   
    this->item->itemspeed.setPosition(200.f, 500.f);
    this->item->itemheart.setPosition(500.f, 1000.f);
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
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setCharacterSize(24);
    this->pointText.setPosition(830.f, 50.f);
  
}

/*void game::titlePmenu()
{
    this->pmenu = new PauseMenu(*this->window);
}*/



void game::renderGUI(sf::RenderTarget* targetGUI)
{
    targetGUI->draw(this->pointText);
}

void game::ResizeView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(800 * aspectRatio, 600);
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
    this->titlebg();
    this->titlePlayer();
    this->pollEvent();
    this->titleEnermy();
    this->titleItem();
    this->titleObject();
    this->titleFont();
    this->titleText();
   // this->titlePmenu();
}

void game::regame()
{
    delete this->window;
    delete this->player;
    delete this->enermy;
    delete this->item;
    delete this->Object;

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


void game::chasing(const float& dt)
{
    sf::Vector2f moveVec;
    moveVec.x = this->player->body.getPosition().x  - this->enermy->enermy1.getPosition().x ;
    moveVec.y = this->enermy->enermy1.getPosition().y - this->player->body.getPosition().y ;
    float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
    moveVec /= vecLength;

    if (this->enermy->enermy1.getPosition().x != this->player->body.getPosition().x)
        this->enermy->enermy1.move(moveVec.x * 10.f  , moveVec.y + 2.f );
}

void game::randomObject()
{
    this->updateSpawnOb(this->sandbar1, 2000.f, 1000.f);
    this->updateSpawnOb(this->sandbar2, 2000.f, 1500.f);
    this->updateSpawnOb(this->sandbar3, 2000.f, 1800.f);
    this->updateSpawnOb(this->sandbar4, 2000.f, 1700.f);
    this->updateSpawnOb(this->port[0] , 2000.f, 1000.f);
    this->updateSpawnOb(&Object->ob[1], 1000.f, 750.f);
    this->updateSpawnOb(&Object->ob[2], 1000.f, 850.f);
    this->updateSpawnOb(&Object->ob[3], 1000.f, 950.f);
    this->updateSpawnOb(&Object->ob[4], 1000.f, 1050.f);
    this->updateSpawnOb(&Object->ob[5], 1000.f, 1150.f);
    this->updateSpawnOb(&Object->ob[6], 1000.f, 1250.f);
    this->updateSpawnOb(&Object->ob[7], 1000.f, 1350.f);
    this->updateSpawnOb(&Object->ob[8], 1000.f, 1450.f);
    this->updateSpawnOb(&Object->ob[9], 1000.f, 1550.f);
    this->updateSpawnOb(&Object->ob[10], 1000.f, 1650.f);
    this->updateSpawnOb(&Object->ob[11], 1000.f, 1750.f);
    this->updateSpawnOb(&Object->ob[12], 1000.f, 1850.f);

}

void game::updateSpawnOb(sf::RectangleShape * ob,float gabOb_y,float forwardOb)
{
    if ((this->player->body.getPosition().y - ob->getPosition().y) >= gabOb_y)
    {
        if (this->player->body.getPosition().x < 0)
        {
            ob->setPosition(this->player->body.getPosition().x - rand() % 700, this->mainView.getCenter().y + forwardOb);
        }
        else
        {
            ob->setPosition(this->player->body.getPosition().x + rand() % 700, this->mainView.getCenter().y + forwardOb);  // สุ่มเกิดเกาะ 1
            //std::cout << "sand 1" << this->sandbar1->getPosition().x << "  " << this->sandbar1->getPosition().y << "\n";
        }
    } 
   
}

void game::randomenemies()
{   ///เวลาในการ spawn
    this->spawnTimer += 0.0f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {
        
        this->enermy->spawnEnermy(this->player->body.getPosition().x, this->mainView.getCenter().y - 400 );
        this->spawnTimer = 0.f;
    }
  
}

void game::updateCollision()
{
    if (this->player->getGlobalBounds().intersects(this->enermy->getGlobalBounds())) ///เช็คชน enermy
    {
        //this->player->setPosition();
        //this->player->speedPlayer = 0.f;
        
        std::cout << "collision Enermy";
    }

    if (this->player->getGlobalBounds().intersects(this->item->itemspeed.getGlobalBounds())) ///เช็คชนไอเท็ม
    {
        item->itemspeed.setPosition(this->player->body.getPosition().x + (rand()%500)+300 , (this->player->body.getPosition().y +(rand()%900))+100);  // itemspeed ไปเกิดตรงอื่น
        
        this->player->speedPlayer = 300.f; //วิ่งไว
      
       // std::cout <<"item pos"<< item->itemspeed.getPosition().x << "   "<<item->itemspeed.getPosition().y << "\n "; 
    }
        
    if (this->player->getGlobalBounds().intersects(this->item->itemheart.getGlobalBounds())) ///เช็คชนไอเท็ม
    {
        item->itemheart.setPosition(this->player->body.getPosition().x + (rand() % 1000) + 450, (this->player->body.getPosition().y + (rand() % 1500)) + 400);  // itemheart ไปเกิดตรงอื่น

        std::cout << "item pos" << item->itemheart.getPosition().x << "   " << item->itemheart.getPosition().y << "\n ";
    }


}

void game::updateGUI()
{
    std::stringstream mm;

    
    mm << this->player->getPoints() << " m";


    this->pointText.setString(mm.str());

}

void game::updateBg(const float& dt)
{
    for (int i = 0; i < 3; i++)
    {
        //BgPos = bg[0]->getPosition();

        

        if (this->player->body.getPosition().y >=  (bg[i]->getGlobalBounds().top + bg[i]->getGlobalBounds().height)  + 300.f)
        {
            bg[i]->setPosition(bg[i]->getPosition().x, bg[i]->getPosition().y+1440.f);
            std::cout << "work!" << "\n";
            
        }
    }

}

void game::updateInput(const float &dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (!this->paused)
            this->pauseState();
        //else
            //this->unpauseState();
    }
}

///
void game::update()
{    
    if (!this->paused)  /// unpause update
    {
        this->deltaTime = clock.restart().asSeconds();
        this->pollEvent();

        std::cout << " pp" << this->player->body.getPosition().x << "   " << this->player->body.getPosition().y << "\n";
        ///update movement & animations

        this->updateBg(this->deltaTime);
        this->mainView.setCenter((this->player->body.getPosition().x), (this->player->body.getPosition().y)); //set centerview
        this->player->Updateplayer(this->deltaTime);
        this->enermy->UpdateEnermy(this->deltaTime);
        

        this->item->UpitemSpeed(this->deltaTime);
        this->item->Upitemheart(this->deltaTime);
        ///enermies and collision

        this->updateCollision();

        this->chasing(this->deltaTime);
        this->randomenemies();
        this->randomObject();

        ///GUI

        this->player->getPoints();

        this->updateGUI();

    }
    else //pause update
    {
       // this->menu->update();
    }
}


void game::render()
{
    
    this->window->clear(sf::Color(49, 193, 217));

    ///render stuff

    
    this->window->setView(mainView);
    this->window->draw(*this->bg[0]);
    this->window->draw(*this->bg[1]);
    this->player->Drawplayer(*this->window);
    this->enermy->Drawenermy(*this->window);

    this->Object->DrawObject(*this->window);
    this->window->draw(*this->sandbar1);
    this->window->draw(*this->sandbar2);
    this->window->draw(*this->sandbar3);
    this->window->draw(*this->sandbar4);
    this->window->draw(*this->port[0]);


    this->item->Drawitem(*this->window);
    
    
    
    //ทำให้ GUI อยู่ในขอบ View ด้วย
    this->window->setView(window->getDefaultView());
    this->renderGUI(this->window);
    
    ///ต้องเอาไว้ล่างสุด
    this->window->display(); 
    

    if (this->paused)  // paused menu
    {
      //  this->menu->render(*this->window);
    }

}

void game::endState()
{
    this->quit = true;
}

void game::pauseState()
{
    this->paused = true;
}

void game::unpauseState()
{
    this->paused = false;
}








 