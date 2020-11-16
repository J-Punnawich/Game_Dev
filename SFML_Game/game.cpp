#include <iostream>
#include "game.h"
#include "Player.h"
#include "animations.h"
#include "PauseMenu.h"
#include <fstream>
#include <fstream>
using namespace std;

 ///Construtor ,Destructor /// จะทำงานเเน่ๆ เมื่อเรียกใช้ game.
bool game::sortinrev(const pair<unsigned, string>& a, const pair<unsigned, string>& b)
{
    return(a.first > b.first);
}
void game::titleWindow()
{
    this->window = nullptr;
   this->window = new  sf::RenderWindow (sf::VideoMode(1720, 1080), "Game",sf::Style::Default);
   this->window->setFramerateLimit(60);
   this->window->setVerticalSyncEnabled(false);
    
   ///set size View
   mainView.setSize(1200,980);
   
   //mainView.setViewport(FloatRect(0,0,800,600));

   this->quit = false;
   this->paused = false;
   this->endGame = false;
   this->playState = false;
   this->menuState = true;
   this->scoreState = false;
   this->deltaTime = 0;
   

   Select.setFillColor(sf::Color::White);
   Select.setRadius(10.f);
   Select.setPosition(660.f, 300.f);

   ifstream Ifile("HighscoreFile.txt");
   vector<pair<int, string>>pairScoreName;
}

void game::titlebg()
{
    
    /// set BG
    bgTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/bg2.png");

    bg[0] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[1] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[2] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[3] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[4] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[5] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    
    bg[0]->setTexture(&bgTexture);
    bg[1]->setTexture(&bgTexture);
    bg[2]->setTexture(&bgTexture);
    bg[3]->setTexture(&bgTexture);
    bg[4]->setTexture(&bgTexture);
    bg[5]->setTexture(&bgTexture);
    
    bg[0]->setPosition(0.f, 0.f);
    bg[2]->setPosition(1020.f, 0.f);
    bg[4]->setPosition(-1020.f, 0.f);

    bg[1]->setPosition(bg[0]->getPosition().x, bg[0]->getPosition().y + bg[0]->getSize().y);
   // bg[2]->setPosition(bg[1]->getPosition().x, bg[1]->getPosition().y + bg[1]->getSize().y);
    bg[3]->setPosition(bg[2]->getPosition().x, bg[2]->getPosition().y + bg[2]->getSize().y);
    bg[5]->setPosition(bg[4]->getPosition().x, bg[4]->getPosition().y + bg[4]->getSize().y);
    
}

void game::titlePlayer()
{
   
    this->bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
    
    this->player = new Player(&bodyTexture, sf::Vector2u(4, 4), 0.4f, 100.f);

   // this->player->body.setPosition(window->getPosition().x,0.f);
    
  

    this->hpMax = 3;
    this->hp = this->hpMax;
    this->player->body.setPosition(0.f, 0.f);
    
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

    /// set object
    this->objectTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/objects64.png");
    
    this->Object  = new object(&objectTexture, sf::Vector2u(30, 1));
    

    for (int i = 0; i < 14; i++)
    {
        
        this->Object->uvrectOb(&Object->ob[i], sf::Vector2u(i, 0));
    }

    
    //this->Objects.push_back(object(&objectTexture, sf::Vector2u(30, 1),sf::Vector2u(0,0)));
    

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

    

    /// set sandbar
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
  
    sandbar1->setPosition(   float(rand() % 1080),float(rand() % 500) );
    sandbar2->setPosition( - float(rand() % 1080),float(rand() % 1200));
    sandbar3->setPosition(   float(rand() % 1900),float(rand() % 1500));
    sandbar4->setPosition( - float(rand() % 1080),float(rand() % 1900));


    /// set port (อาจจะไม่ใช้)
    port[0] = new sf::RectangleShape(sf::Vector2f(192.f, 128.f));

    this->portTexture[0].loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/port1.png");

    port[0]->setTexture(&portTexture[0]);

    port[0]->setPosition(float(rand() % 1080), float(rand() % 500)); 
   

    heart[0] = new sf::RectangleShape(sf::Vector2f(24.f, 24.f));
    heart[1] = new sf::RectangleShape(sf::Vector2f(24.f, 24.f));
    heart[2] = new sf::RectangleShape(sf::Vector2f(24.f, 24.f));
    
    interfaceTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interface.png");

    heart[0]->setTexture(&interfaceTexture);
    heart[1]->setTexture(&interfaceTexture);
    heart[2]->setTexture(&interfaceTexture);

    heart[0]->setTextureRect(sf::IntRect(24, 1, 24, 24));
    heart[1]->setTextureRect(sf::IntRect(24, 1, 24, 24));
    heart[2]->setTextureRect(sf::IntRect(24, 1, 24, 24));
  
    heart[0]->setScale(1.5f, 1.5f);
    heart[0]->setPosition(600.f,40.f);
    heart[1]->setScale(1.5f, 1.5f);
    heart[1]->setPosition(635.f, 40.f);
    heart[2]->setScale(1.5f, 1.5f);
    heart[2]->setPosition(670.f, 40.f);

}

void game::titleItem()
{   
    this->speedTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");
    
    item = new Item(&speedTexture, sf::Vector2u(8, 4), 0.5f);
   
    this->item->itemspeed.setPosition(500.f, 1500.f);
    this->item->itemheart.setPosition(500.f, 1000.f);
    //// set ให้ item ติดอยู่กับ player ตลอด
    //this->item->itemspeed.setPosition(this->player->body.getPosition().x, this->player->body.getPosition().y + 20);
    this->itemtimerMax = 50.f;
    this->itemtimer = 0;
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
    bar.setSize(sf::Vector2f(400.0f, 70.0f));
    bar.setOrigin(sf::Vector2f(200.0f, 35.0f));
    bar.setPosition(sf::Vector2f(666, 450.0f));

    cursor.setSize(sf::Vector2f(5.0f, 64.0f));
    cursor.setOrigin(sf::Vector2f(2.5f, 32.0f));
    cursor.setPosition(sf::Vector2f(480, 450.0f));
    cursor.setFillColor(sf::Color::Black);



    this->pointText.setFont(this->font);
    this->pointText.setFillColor(sf::Color::White);
    this->pointText.setCharacterSize(24);
    this->pointText.setPosition(830.f, 50.f);
  

    this->endGameText.setFont(this->font);
    this->endGameText.setFillColor(sf::Color::White);
    this->endGameText.setCharacterSize(48);
    this->endGameText.setPosition(660.f, 200.f);
    this->endGameText.setString("SURF AGAIN!!");

    this->StartText.setFont(this->font);
    this->StartText.setFillColor(sf::Color::White);
    this->StartText.setCharacterSize(32);
    this->StartText.setPosition(700.f, 300.f);
    this->StartText.setString("Play");

    this->ScoreText.setFont(this->font);
    this->ScoreText.setFillColor(sf::Color::White);
    this->ScoreText.setCharacterSize(32);
    this->ScoreText.setPosition(700.f, 400.f);
    this->ScoreText.setString("Score");

    this->howtoPlay.setFont(this->font);
    this->howtoPlay.setFillColor(sf::Color::White);
    this->howtoPlay.setCharacterSize(32);
    this->howtoPlay.setPosition(700.f, 500.f);
    this->howtoPlay.setString("How to play");

    this->QuitText.setFont(this->font);
    this->QuitText.setFillColor(sf::Color::White);
    this->QuitText.setCharacterSize(32);
    this->QuitText.setPosition(700.f, 600.f);
    this->QuitText.setString("Quit");

    this->highscoreTitle.setFont(this->font);
    this->highscoreTitle.setCharacterSize(52);
    this->highscoreTitle.setString("HIGHSCORE");
    this->highscoreTitle.setOrigin(highscoreTitle.getGlobalBounds().width, highscoreTitle.getGlobalBounds().height);
    this->highscoreTitle.setFillColor(sf::Color::White);
    this->highscoreTitle.setPosition(660 , 200);


    playerNametext.setFont(font);
    playerNametext.setCharacterSize(40);
    playerNametext.setFillColor(sf::Color::Black);
    playerNametext.setPosition(480, 425);
    
}



void game::menu()
{
    millis = timeMliis.getElapsedTime().asMilliseconds();
    
    std::cout << " delta" << this->deltaTime << "\n";

    this->player->body.setPosition(0.f, 0.f);
        if (mode == 1)
        {
            Select.setPosition(660, 300);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300 )
            { 
                delay = millis;
                this->playState = true;
                this->menuState = false;
                
                
            }
        }
        ///////////////////////////////////////////////////////////
        if (mode == 2)
        {
            Select.setPosition(660, 400);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300)
            {
                this->scoreState = true;
                this->menuState = false;
                delay = millis;
         
            }
        }
        //////////////////////////////////////////////////////////
        if (mode == 3)
        {
            Select.setPosition(660, 500);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300)
            {
                delay = millis;
            }
        }
        if (mode == 4)
        {
            Select.setPosition(660, 600);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300)
            {
                delay = millis;
                window->close();
            }
        }





        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 30) && millis - delay >= 300)
        {
            mode += 1;
            delay = millis;
            if (mode > 4)
            {
                mode = 1;
            }
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -30) && millis - delay >= 300)
        {
            mode -= 1;
            delay = millis;
            if (mode < 1)
            {
                mode = 4;
            }
        }


        this->window->clear();
        this->window->draw(this->StartText);
        this->window->draw(this->ScoreText);
        this->window->draw(this->howtoPlay);
        this->window->draw(this->QuitText);
        this->window->draw(this->Select);
        this->window->display();
    
}

void game::renderGUI(sf::RenderTarget* targetGUI)
{
    targetGUI->draw(this->pointText);
   
}

void game::ResizeView(sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(800 * aspectRatio, 600);
}

/*void game::titlePmenu()
{
    this->pmenu = new PauseMenu(*this->window);
}*/





 
/// เรียกใช้ฟังชั่นตัวแปรเริ่มต้น กับ หน้าต่างเริ่มต้น
game::game()
{

    this->titleWindow();
    this->titlebg();
    this->titlePlayer();
  
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

///Functions 

void game::run()
{
    
    while (this->window->isOpen())
    {

        if (menuState == true)
        {
            this->menu();
        }

        if (playState == true)
        {
            this->deltaTime = clock.restart().asSeconds();
            this->update();
             this->render();
          
             this->timeCount = clock.getElapsedTime().asSeconds();
        }
        if (scoreState == true)
        {

        }
        
    }
    
}




void game::updateBg(const float& dt)
{
    for (int i = 0; i <= 5; i++)
    {
        if (this->player->body.getPosition().y >= (bg[i]->getGlobalBounds().top + bg[i]->getGlobalBounds().height) + 350.f)
        {
            bg[i]->setPosition(bg[i]->getPosition().x, bg[i]->getPosition().y + 1536.f);
           
        }


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
    this->updateSpawnOb(this->sandbar2, 2000.f, 2000.f);
    this->updateSpawnOb(this->sandbar3, 2000.f, 3000.f);
    this->updateSpawnOb(this->sandbar4, 2000.f, 4000.f);

    /// update spawn object
    for (int i = 0; i < 13; i++)
    {
        this->updateSpawnOb(&Object->ob[i], 1000.f, rand()%1000+750);
    }

    this->updateSpawnOb(this->port[0], 2000.f, 1000.f);
}

void game::updateSpawnOb(sf::RectangleShape* ob, float gabOb_y, float forwardOb)
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

        this->enermy->spawnEnermy(this->player->body.getPosition().x, this->mainView.getCenter().y - 400);
        this->spawnTimer = 0.f;
    }

}

void game::updateCollision()
{
    
    if (this->player->getGlobalBounds().left  < -455.f)
    {
        //this->player->resetVelocity();
        this->player->body.setPosition(-455.f, this->player->getGlobalBounds().top);
    }

     if (this->player->getGlobalBounds().left  >= 1382.f)
    {
        this->player->body.setPosition( 1382.f , this->player->getGlobalBounds().top);
    }


    /// player -> enermya
      
    if (this->player->getGlobalBounds().intersects(this->enermy->getGlobalBounds())) ///เช็คชน enermy
    {
        //this->player->setPosition();
        //this->player->speedPlayer = 0.f;
        
        
            
        
        this->endGame = true;

        std::cout << "collision Enermy";
    }
    /// player -> item

    if (this->player->getGlobalBounds().intersects(this->item->itemspeed.getGlobalBounds())) 
    {
        this->item->itemspeed.setPosition(this->player->body.getPosition().x + (rand() % 500) + 300, (this->player->body.getPosition().y + (rand() % 5000)) + 500);  // itemspeed ไปเกิดตรงอื่น
       
        this->player->speedPlayer = 500.f; //วิ่งไว
        this->itemTimer();
        
    }
    if ( this->player->getGlobalBounds().intersects(this->item->itemheart.getGlobalBounds())) 
    {
        item->itemheart.setPosition(this->player->body.getPosition().x + (rand() % 1000) + 450, (this->player->body.getPosition().y + (rand() % 4000)) + 400);  // itemheart ไปเกิดตรงอื่น
        
        

        
    }

    for (int i = 0; i <= 13; i++)
    {
       
        if (this->player->getGlobalBounds().intersects(this->Object->ob[i].getGlobalBounds()))
        {
            printf("hp : %d", this->hp);
           
            if (this->fck)
            {
                //this->timeSet = this->timeCount + 5;
                this->hp -= 1;
                fck = false;
             
            }
            fck = true;
           /* if (this->timeCount >= this->timeSet  )
            {
                
                if (hp <= 0) { this->endGame = true; }


              
            }*/

        }

    }
   
    
}

void game::itemTimer()
{
    this->itemtimer += 0.5f;

    this->speedNow += this->player->speedPlayer;
 
    
    if (this->player->speedPlayer == 500.f)
    {
        
        if (this->itemtimer >= this->itemtimerMax)
        {
            printf("Speeddd  %.2f", this->speedNow);

            this->player->speedPlayer = this->speedNow;

            this->speedNow = 0.f;
            this->itemtimer = 0.f;
        }
    }
}

void game::updateGUI()
{
    this->Score = this->player->getPoints();
     
    std::stringstream mm;


    mm << this->player->getPoints() << " m";


    this->pointText.setString(mm.str());

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
    




void game::update()
{
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {

        if (!this->paused)  /// unpause update
        {
            
            

            std::cout << " pp" << this->player->body.getPosition().x << "   " << this->player->body.getPosition().y << "\n";
            ///update movement & animations

            this->updateBg(this->deltaTime);
            this->mainView.setCenter(this->player->body.getPosition().x + 50, (this->player->body.getPosition().y)); //set centerview
            this->player->Updateplayer(this->deltaTime);
            this->enermy->UpdateEnermy(this->deltaTime);


            this->item->UpitemSpeed(this->deltaTime);
            this->item->Upitemheart(this->deltaTime);
            

            ///enermies and collision
         
            this->updateCollision();

            this->chasing(this->deltaTime);
            //this->randomenemies();
            this->randomObject();

            ///GUI

            this->player->getPoints();

            this->updateGUI();

            if (this->hp == 2)
            {
                heart[2]->setTextureRect(sf::IntRect(0, 0, 24, 24));
            }
            if (this->hp == 1)
            {
                heart[1]->setTextureRect(sf::IntRect(0, 0, 24, 24));
            }
            if (this->hp == 0)
            {
                heart[0]->setTextureRect(sf::IntRect(0, 0, 24, 24));
            }
            //test
            // this->Objects.push_back(object(&objectTexture, sf::Vector2u(30, 1), sf::Vector2u(0, 0)));
            
        }
        else //pause update
        {
            // this->menu->update();
        }
    }
    else
    {
        this->window->clear();
    }  
}


void game::render()
{
   

        this->window->clear(sf::Color(49, 193, 217));

        ///render stuff


        this->window->setView(mainView);
        this->window->draw(*this->bg[0]);
        this->window->draw(*this->bg[1]);
       this->window->draw(*this->bg[2]);
        this->window->draw(*this->bg[3]);
        this->window->draw(*this->bg[4]);
        this->window->draw(*this->bg[5]);

        this->player->Drawplayer(*this->window);
        this->enermy->Drawenermy(*this->window);

        this->Object->DrawObject(*this->window);
        this->window->draw(*this->sandbar1);
        this->window->draw(*this->sandbar2);
        this->window->draw(*this->sandbar3);
        this->window->draw(*this->sandbar4);
        this->window->draw(*this->port[0]);
        
        this->item->Drawitem(*this->window);

        /// draw object ด้วย vector
        /* for (int i = 0; i < Objects.size(); i++)
        {
            Objects[i].DrawObject(*this->window);
        }*/


        for (Platform& platform : Platforms)
            platform.Draw(*this->window);


        //ทำให้ GUI อยู่ในขอบ View ด้วย
        this->window->setView(window->getDefaultView());
        this->renderGUI(this->window);
        this->window->draw(*this->heart[0]);
        this->window->draw(*this->heart[1]);
        this->window->draw(*this->heart[2]);
        if (this->endGame == true)
        {
            this->window->draw(this->endGameText);
        }

       


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










 