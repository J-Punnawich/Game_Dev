#include <iostream>
#include "game.h"
#include "Player.h"
#include "animations.h"
#include "PauseMenu.h"
#include <fstream>
#include <fstream>
#include <SFML/Audio.hpp>
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

   this->quit       = false;
   this->paused     = false;
   this->endGame    = false;
   this->playState  = false;
   this->menuState  = true;
   this->scoreState = false;
   this->ischase = true;
   this->deltaTime  = 0;
   


   ifstream Ifile("HighscoreFile.txt");
   vector<pair<int, string>>pairScoreName;
}


void game::titlebg()
{
    /// set BG
    bgTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/bg2.png");
    bgMenuTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/bg1.png");

    bg[0] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[1] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[2] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[3] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[4] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bg[5] = new sf::RectangleShape(sf::Vector2f(1024.f, 768.f));
    bgMenu = new sf::RectangleShape(sf::Vector2f(1720.f,1080.f));

    bg[0]->setTexture(&bgTexture);
    bg[1]->setTexture(&bgTexture);
    bg[2]->setTexture(&bgTexture);
    bg[3]->setTexture(&bgTexture);
    bg[4]->setTexture(&bgTexture);
    bg[5]->setTexture(&bgTexture);
    bgMenu->setTexture(&bgMenuTexture);
    
    bg[0]->setPosition(0.f, 0.f);
    bg[2]->setPosition(1020.f, 0.f);
    bg[4]->setPosition(-1020.f, 0.f);

    bg[1]->setPosition(bg[0]->getPosition().x, bg[0]->getPosition().y + bg[0]->getSize().y);
    // bg[2]->setPosition(bg[1]->getPosition().x, bg[1]->getPosition().y + bg[1]->getSize().y);
    bg[3]->setPosition(bg[2]->getPosition().x, bg[2]->getPosition().y + bg[2]->getSize().y);
    bg[5]->setPosition(bg[4]->getPosition().x, bg[4]->getPosition().y + bg[4]->getSize().y);
    
  

    if (!loadIn.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/UGH.wav"))
    {
        printf("Error \n");
    }
    if (!loadIn2.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/selectSound.wav"))
    {
        printf("Error \n");
    }
    sound.setBuffer(loadIn);
    selectSound.setBuffer(loadIn2);
    selectSound.setVolume(30);
    sound.setPitch(-5);
    
            
}


void game::titlePlayer()
{
   
    this->bodyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/surf.png");
    
    this->player = new Player(&bodyTexture, sf::Vector2u(4, 4), 0.4f, 0.f);

  
    
    this->hpMax = 3;
    
    this->player->body.setPosition(0.f, 500.f);
    
}


void game::titleEnermy()
{   
   
    this->enermyTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/enermy1.png");
    
    enermy = new Enermy(&enermyTexture, sf::Vector2u(2, 6), 0.3f);
    

  
}


void game::titleObject()
{


    /// set object
    this->objectTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/objects64.png");
    this->slowTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/slowdown.png");
    this->Object  = new object(&objectTexture, sf::Vector2u(30, 1));
    
    for (int i = 0; i < 14; i++)
    {   
        this->Object->uvrectOb(&Object->ob[i], sf::Vector2u(i, 0));
    }

    
    //this->Objects.push_back(object(&objectTexture, sf::Vector2u(30, 1)));
    
    

    this->Object->ob[0].setPosition(500.f,700.f);
    this->Object->ob[1].setPosition(-300.f, 500.f);
    this->Object->ob[2].setPosition(-100.f, 1010.f);
    this->Object->ob[3].setPosition(-10, 1200.f);
    this->Object->ob[4].setPosition(900.f, 168.f);
    this->Object->ob[5].setPosition(850.f, 550.f);
    this->Object->ob[6].setPosition(-782.f,574.f);
    this->Object->ob[7].setPosition(924.f,524.f);
    this->Object->ob[8].setPosition(1000.f,1000.f);
    this->Object->ob[9].setPosition(-785.f, 784.f);
    this->Object->ob[10].setPosition(567.f,577.f);
    this->Object->ob[11].setPosition(1052.f, 1045.f);
    this->Object->ob[12].setPosition(987.f,789.f);
    this->Object->ob[13].setPosition(-666.f,777.f);

  
    /// set sandbar
    sandbar[0] = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));
    sandbar[1] = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));
    sandbar[2] = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));
    sandbar[3] = new sf::RectangleShape(sf::Vector2f(256.f, 128.f));

    sandbar[0]->setOrigin(this->sandbar[0]->getSize()/2.f);
    sandbar[1]->setOrigin(this->sandbar[1]->getSize() / 2.f);
    sandbar[2]->setOrigin(this->sandbar[2]->getSize() / 2.f);
    sandbar[3]->setOrigin(this->sandbar[3]->getSize() / 2.f);

    sandbar1Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar1.png");
    sandbar2Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar2.png");
    sandbar3Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar3.png");
    sandbar4Texture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/sandbar4.png");

    sandbar[0]->setTexture(&sandbar1Texture);
    sandbar[1]->setTexture(&sandbar2Texture);
    sandbar[2]->setTexture(&sandbar3Texture);
    sandbar[3]->setTexture(&sandbar4Texture);
  
    sandbar[0]->setPosition(  420.f,500.f );
    sandbar[1]->setPosition( - 420.f, 1200.f);
    sandbar[2]->setPosition(   1900.f,1500.f);
    sandbar[3]->setPosition( - 1080.f,1099.f);


    /// set port (อาจจะไม่ใช้)
    port[0] = new sf::RectangleShape(sf::Vector2f(192.f, 128.f));

    this->portTexture[0].loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/port1.png");

    port[0]->setTexture(&portTexture[0]);

    port[0]->setPosition(999.f,2500.f); 
   


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


    speed[0] = new sf::RectangleShape(sf::Vector2f(24.f, 24.f));
    speed[1] = new sf::RectangleShape(sf::Vector2f(24.f, 24.f));
    speed[2] = new sf::RectangleShape(sf::Vector2f(24.f, 24.f));

    speed[0]->setTexture(&interfaceTexture);
    speed[1]->setTexture(&interfaceTexture);
    speed[2]->setTexture(&interfaceTexture);

    speed[0]->setTextureRect(sf::IntRect(0, 24, 24, 24));
    speed[1]->setTextureRect(sf::IntRect(0, 24, 24, 24));
    speed[2]->setTextureRect(sf::IntRect(0, 24, 24, 24));

    speed[0]->setScale(1.5f, 1.5f);
    speed[0]->setPosition(1010.f, 40.f);
    speed[1]->setScale(1.5f, 1.5f);
    speed[1]->setPosition(1045.f, 40.f);
    speed[2]->setScale(1.5f, 1.5f);
    speed[2]->setPosition(1080.f, 40.f);


    Platforms.push_back(Platform(&rippleTexture, sf::Vector2f(96.f, 96.f), sf::Vector2f(this->Object->ob[0].getPosition().x, this->Object->ob[0].getPosition().y + 5), sf::Vector2u(1, 3), 1.f, this->deltaTime));

    


}


void game::titleItem()
{   
    this->speedTexture.loadFromFile("C:/source/repos/Game_Dev/SFML_Game/img/interact.png");
    
    item = new Item(&speedTexture, sf::Vector2u(8, 4), 0.5f);
    
    this->item->itemspeed.setPosition(500.f, 1500.f);
    this->item->itemheart.setPosition(800.f, 1000.f);
   
   
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
   

    Select.setFillColor(sf::Color::Black);
    Select.setRadius(10.f);
    Select.setPosition(660.f, 300.f);


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
    this->endGameText.setPosition(660.f, 150.f);
    this->endGameText.setString("SURF AGAIN!!");

    this->StartText.setFont(this->font);
    this->StartText.setFillColor(sf::Color::White);
    this->StartText.setCharacterSize(32);
    this->StartText.setPosition(800.f, 300.f);
    this->StartText.setString("Play");

    this->ScoremenuText.setFont(this->font);
    this->ScoremenuText.setFillColor(sf::Color::White);
    this->ScoremenuText.setCharacterSize(32);
    this->ScoremenuText.setPosition(800.f, 400.f);
    this->ScoremenuText.setString("Score");

    this->howtoPlay.setFont(this->font);
    this->howtoPlay.setFillColor(sf::Color::White);
    this->howtoPlay.setCharacterSize(32);
    this->howtoPlay.setPosition(800.f, 500.f);
    this->howtoPlay.setString("How to play");

    this->QuitText.setFont(this->font);
    this->QuitText.setFillColor(sf::Color::White);
    this->QuitText.setCharacterSize(32);
    this->QuitText.setPosition(800.f, 600.f);
    this->QuitText.setString("Quit");

    this->highscoreTitle.setFont(this->font);
    this->highscoreTitle.setCharacterSize(52);
    this->highscoreTitle.setString("HIGHSCORE");
    this->highscoreTitle.setOrigin(highscoreTitle.getGlobalBounds().width, highscoreTitle.getGlobalBounds().height);
    this->highscoreTitle.setFillColor(sf::Color::White);
    this->highscoreTitle.setPosition(800 , 300);


    playerNametext.setFont(font);
    playerNametext.setCharacterSize(40);
    playerNametext.setFillColor(sf::Color::Black);
    playerNametext.setPosition(480, 425);

    this->scoreText.setFont(this->font);
    this->scoreText.setFillColor(sf::Color::White);
    this->scoreText.setCharacterSize(32);
    this->scoreText.setPosition(950.f, 800.f);
    
   

    this->YourScoreText.setFont(this->font);
    this->YourScoreText.setFillColor(sf::Color::White);
    this->YourScoreText.setCharacterSize(32);
    this->YourScoreText.setPosition(650.f, 800.f);
    this->YourScoreText.setString("Your Score :");
    
    
    this->EnterYourNameText.setFont(this->font);
    this->EnterYourNameText.setFillColor(sf::Color::White);
    this->EnterYourNameText.setCharacterSize(32);
    this->EnterYourNameText.setPosition(300.f, 350.f);
    this->EnterYourNameText.setString("ENTER YOUR NAME");

   
    this->toMove.setFont(this->font);
    this->toMove.setFillColor(sf::Color::White);
    this->toMove.setCharacterSize(40);
    this->toMove.setPosition(400.f, 250.f);
    this->toMove.setString("Move :   \"A\"   &   \"D\" \n\n Use Item :   \"Space bar\"");

    this->touseItem.setFont(this->font);
    this->touseItem.setFillColor(sf::Color::White);
    this->touseItem.setCharacterSize(40);
    this->touseItem.setPosition(400.f, 600.f);
    this->touseItem.setString("Item --->\n\n                  increse speed             Hp +1    ");


}




void game::menu()
{   
    this->player->body.setPosition(this->player->body.getOrigin().x , this->player->body.getOrigin().y + 390);
    
        if (mode == 1)
        {
            Select.setPosition(760, 300);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300 )
            { 
                delay = millis;
                this->playState = true;
                this->menuState = false;
                selectSound.play();
                
            }
        }
        ///////////////////////////////////////////////////////////
        if (mode == 2)
        {
            Select.setPosition(760, 400);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300)
            {
                selectSound.play();
                this->scoreState = true;
                this->menuState = false;
                delay = millis;
         
            }
        }
        //////////////////////////////////////////////////////////
        if (mode == 3)
        {
          
            Select.setPosition(760, 500);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300)
            {
                selectSound.play();
                this->howtoplayState = true;
                this->menuState = false;
                delay = millis;
            }
        }
        if (mode == 4)
        {
            Select.setPosition(760, 600);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Joystick::isButtonPressed(0, 0)) && millis - delay >= 300)
            {
                selectSound.play();
                delay = millis;
                window->close();
            }
        }




        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 30) && millis - delay >= 300)
        {
            mode += 1;
            delay = millis;
            selectSound.play();
            if (mode > 4)
            {
                mode = 1;
            }
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -30) && millis - delay >= 300)
        {
            mode -= 1;
            delay = millis;
            selectSound.play();
            if (mode < 1)
            {
                mode = 4;
            }
        }


        this->window->clear(sf::Color(49, 193, 217));
       
       
        this->Object->DrawObject(*this->window);
        this->window->draw(*this->sandbar[0]);
        this->window->draw(*this->sandbar[1]);
        this->window->draw(*this->sandbar[2]);
        this->window->draw(*this->sandbar[3]);
        this->window->draw(*this->port[0]);
        this->window->draw(*this->bgMenu);
        this->window->draw(this->StartText);
        this->window->draw(this->ScoremenuText);
        this->window->draw(this->howtoPlay);
        this->window->draw(this->QuitText);
        this->window->draw(this->Select);

        this->window->display();
    
}

void game::titlehowtoplay()
{

  
   howtoplayPic[0].setSize(sf::Vector2f(128.f, 128.f));
   howtoplayPic[1].setSize(sf::Vector2f(128.f, 128.f));
    howtoplayPic[0].setTexture(&bodyTexture);
    howtoplayPic[1].setTexture(&bodyTexture);
    
    howtoplayPic[0].setTextureRect(sf::IntRect(0, 128, 128, 128));
    howtoplayPic[1].setTextureRect(sf::IntRect(0, 256, 128, 128));

    howtoplayPic[0].setScale(1.3f,1.3f);
    howtoplayPic[1].setScale(1.3f,1.3f);

    howtoplayPic[0].setPosition(1100.f, 250.f);
    howtoplayPic[1].setPosition(1300.f, 250.f);



  ////////////////////////////////////////////////////
    howtoplayPic[2].setSize(sf::Vector2f(64.f, 64.f));
    howtoplayPic[3].setSize(sf::Vector2f(64.f, 64.f));


   howtoplayPic[2].setTexture(&speedTexture);
    howtoplayPic[3].setTexture(&speedTexture);

    howtoplayPic[2].setTextureRect(sf::IntRect(128, 64, 64, 64));
    howtoplayPic[3].setTextureRect(sf::IntRect(192, 64, 64, 64));

    howtoplayPic[2].setScale(1.7f, 1.7f);
    howtoplayPic[3].setScale(1.7f, 1.7f);

    howtoplayPic[2].setPosition(800.f, 570.f);
    howtoplayPic[3].setPosition(1250.f, 570.f);


}

bool game::distance(sf::RectangleShape* other1, sf::RectangleShape* other2, sf::Vector2f dis)
{
    sf::Vector2f other1Pos = other1->getPosition();
    sf::Vector2f other1size = other1->getSize();
    sf::Vector2f other2Pos = other2->getPosition();
    sf::Vector2f other2size = other2->getSize();

    float deltaX = other1Pos.x - other2Pos.x;
    float deltaY = other1Pos.y - other2Pos.y;

    float intersectX = abs(deltaX) - ((other1size.x)/2.f + (other2size.x)/2.f);
    float intersectY = abs(deltaY) - ((other1size.y)/2.f + (other2size.y)/2.f);

    if (other1Pos.x < other2Pos.x)
    {
        if (intersectX <= (dis.x + 20.f) && intersectY <= dis.y)
        {
            return true;
        }
        else
        {
            return false;
        }
       
    }
        
    else 
    {   
        if (intersectX <= (dis.x - 10.f) && intersectY <= dis.y)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    
    
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
    this->titlehowtoplay();
  
   // this->titlePmenu();
}


///Functions 
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
    
    moveVec.x = this->player->body.getPosition().x  - this->enermy->enermy1.getPosition().x ;
    moveVec.y = this->enermy->enermy1.getPosition().y - this->player->body.getPosition().y ;
    float vecLength = sqrt(pow(moveVec.x, 2) + pow(moveVec.y, 2));
    moveVec /= vecLength;
    if (ischase == true)
    {
        if (this->enermy->enermy1.getPosition().x != this->player->body.getPosition().x && this->enermy->enermy1.getPosition().y != this->player->body.getPosition().y)
        {
            this->enermy->enermy1.move(moveVec.x * 3.7f, moveVec.y + 5.f);
        }
    } else 
        this->enermy->enermy1.move(0.f,0.f);
  //  if (this->enermy->enermy1.getPosition().x != this->player->body.getPosition().x  || this->enermy->enermy1.getPosition().y == this->player->body.getPosition().y)
  //  {
   //     this->enermy->enermy1.move(moveVec.x * 3.5f, moveVec.y * 0.f);
  //  }

}



void game::randomObject()
{   

    this->updateSpawnOb(this->sandbar[0], 2000.f, 1000.f);
    this->updateSpawnOb(this->sandbar[1], 2000.f, 2000.f);
    this->updateSpawnOb(this->sandbar[2], 2000.f, 3000.f);
    this->updateSpawnOb(this->sandbar[3], 2000.f, 4000.f); 

    /// update spawn object
    for (int i = 0; i < 5; i++)
    {
        this->updateSpawnOb(&Object->ob[i], 1000.f, rand()%1000+500);
    }
    for (int i = 5; i < 9; i++)
    {
        this->updateSpawnOb(&Object->ob[i], 1000.f, rand() % 1000 + 750);
    }
    for (int i = 9; i < 14; i++)
    {
        this->updateSpawnOb(&Object->ob[i], 1000.f, rand() % 1000 + 900);
    }

    this->updateSpawnOb(this->port[0], 2000.f, rand()%3000);


    if ((this->player->body.getPosition().y - this->item->enermyInk.getPosition().y) >= 650 )
    {

        printf("work");
        this->delayEnermy = this->millis;
        this->item->enermyInk.setPosition(this->mainView.getSize().x + rand() % 700, this->player->body.getPosition().y + 7000);
        this->spawnEnermy = true;
        this->enermy->enermy1.setPosition(this->player->body.getPosition().x, this->player->body.getPosition().y - 570);
      
    }
    if (this->spawnEnermy == true)
    {

        if (this->player->body.getPosition().y - this->enermy->enermy1.getPosition().y > 650)
        {   
            
            this->enermy->enermy1.setPosition(0.f, -1000.f);
            this->spawnEnermy = false;
        }
        else if (this->enermy->enermy1.getPosition().y - this->player->body.getPosition().y > 700)
        {

            this->enermy->enermy1.setPosition(0.f, -1000.f);
            this->spawnEnermy = false;
        }

    }

    
   
}



void game::updateSpawnOb(sf::RectangleShape* ob, float gabOb_y, float forwardOb)
{

    if ((this->player->body.getPosition().y - ob->getPosition().y) >= gabOb_y)
    {
        if (this->player->body.getPosition().x < 0)
        {
            ob->setPosition( -(this->player->body.getPosition().x + rand() % 700), this->mainView.getCenter().y + forwardOb);
        }
        else if (this->player->body.getPosition().x == 0)
        {
            ob->setPosition( - (this->player->body.getPosition().x + rand() % 700), this->mainView.getCenter().y + forwardOb);
        }
        else
        {
            ob->setPosition(this->player->body.getPosition().x + rand() % 700, this->mainView.getCenter().y + forwardOb);  // สุ่มเกิดเกาะ 1
           
        }
    }

}



void game::randomenemies()
{   
    
    

}



void game::updateCollision()
{
    printf("%.2f", this->player->body.getPosition().x);

    if (this->player->getGlobalBounds().left < -453.f)
    {
        
        this->player->body.setPosition(-453.f, this->player->getGlobalBounds().top);
    }

    if (this->player->getGlobalBounds().left >= 1382.f)
    {
        this->player->body.setPosition(1382.f, this->player->getGlobalBounds().top);
    }

    /// player -> enermy

   
    if (this->distance(&player->body, &enermy->enermy1,sf::Vector2f(-40.f,-55.f)))
    {
        this->endGame = true;
        std::cout << "collision Enermy";
    }


    /// player -> item

 

    

    if (this->player->getGlobalBounds().intersects(this->item->itemspeed.getGlobalBounds()))
    {
        selectSound.play();
        this->delayItem1 = this->millis;
        this->item->itemspeed.setPosition(this->player->body.getPosition().x , (this->player->body.getPosition().y + (rand() % 5000)) + 500);  // itemspeed ไปเกิดตรงอื่น       
        this->getItem1 = true;
        this->storeItem += 1;
    }
        if (this->getItem1 == true)
        {
           
            if (this->storeItem > 3)
            {
                this->storeItem = this->storeMax;
            }

            if (this->millis - this->delayItem1 > 500)
            {
                this->getItem1 = false;
            }

        }
        

    ///use item

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->storeItem > 0 && this->useItem == false)
    {
        
        this->delayUseitem = this->millis;
        this->useItem = true;
        this->storeItem -= 1;
    }
    if (this->useItem == true )
    {
        this->player->speedPlayer = 5.f;
        

        if (this->millis - this->delayUseitem > 5000)
        {   
            
            this->useItem = false;
           
        }
    }
    else
    {
        this->player->speedPlayer = 2.0f;

    } 

  
    /////////////////////////////////////////////////////

    if(this->distance(&player->body, &item->itemheart, sf::Vector2f(-40.f, -55.f)))

    {
        selectSound.play();
        this->delayItem2 = this->millis;
        item->itemheart.setPosition(this->player->body.getPosition().x, (this->player->body.getPosition().y + (rand() % 4000)) + 400);  // itemheart ไปเกิดตรงอื่น
        this->getItem2 = true;


        if (this->getItem2 == true)
        {
         
            this->gethp = true;
            this->hp += 1;
               
            
            if (this->hp > 3)
            {
               this->hp = this->hpMax;
            }

            if (this->millis - this->delayItem2 > 2000)
            {
                this->getItem2 = false;
                this->gethp = false;
            }


        }


    }


    /// object 

    for (int i = 0; i <= 13; i++)
    {
        if(this->distance(&player->body, &Object->ob[i], sf::Vector2f(-40.f, -55.f)) && this->getObject == false)
        {
            sound.play();
           
            this->delayObject = this->millis;
            this->getObject = true;
            this->hp -= 1;
            
        }
        this->objectCollision();
       
        /*if (this->distance(&Object->ob[i], &Object->ob[i+1], sf::Vector2f(-40.f, -55.f)))
        {
            printf("Yes");
        }*/

        if (this->Object->ob[i].getPosition().x == this->Object->ob[rand()%13].getPosition().x  && this->Object->ob[i].getPosition().y == this->Object->ob[rand() % 13].getPosition().y)
        {
        
        this->updateSpawnOb(&Object->ob[i], 1000.f, rand() % 1000 + 500);
        }

       
    }

    for (int j = 0; j <= 4; j++)
    {   
        /*  if(this->distance(&player->body, this->sandbar[j], sf::Vector2f(-56.9f, -30.f)) && this->getObject == false )
        {
              sound.play();
            //this->player->body.move(-5.f, -5.f);
            this->delayObject = this->millis;
            this->getObject = true;
            this->hp -= 1;
            
        }
        this->objectCollision();*/


        if (this->sandbar[j]->getPosition().x == this->sandbar[rand() % 4]->getPosition().x && this->sandbar[j]->getPosition().y == this->sandbar[rand() % 4]->getPosition().y)
        {
            printf("check sandbar");
            this->updateSpawnOb(sandbar[j], 1000.f, rand() % 1000 + 500);
        }



            ///////////////////////////////////////////////
        
        if (this->distance(&enermy->enermy1, this->sandbar[j], sf::Vector2f(-30.9f, -20.f)) && this->getObjectenermy == false)
        {
            
            
            this->delayObjectenermy1 = this->millis;
            this->getObjectenermy = true;
            

        }
       
        if (this->getObjectenermy == true)
        {

            this->ischase = false;



            if (this->millis - this->delayObjectenermy1 > 3500)
            {
                printf("Yes\n");
                this->ischase = true;
                this->getObjectenermy = false;
            }

        }
        
      
    }








    if (this->distance(&player->body, this->port[0], sf::Vector2f(-60.f, -60.f)) && this->getObject == false)
    {
        sound.play();
        this->delayObject = this->millis;
        this->getObject = true;
        this->hp -= 1;
        
        
    }
    this->objectCollision();
   


  
}



void game::objectCollision()
{

    if (this->getObject == true)
    {
        this->losshp = true;
        this->player->speedPlayer = 0.5f;

        if (this->millis - this->delayObject > 2000)
        {
            this->player->speedPlayer = 2.0f;
            this->player->accerlerate = 1.f;
            this->losshp = false;
        }

        if (this->millis - this->delayObject > 3500)
        {

            this->getObject = false;
        }

    }



    
}



void game::updateGUI()
{
    this->Score = this->player->getPoints();
     
    std::stringstream mm;


    mm << this->player->getPoints() << " m";


    this->pointText.setString(mm.str());
    this->scoreText.setString(mm.str());
}



void game::update()
{
    ///update movement & animations

    //printf("%.2f \n",this->player->body.getPosition().x);
    this->updateBg(this->deltaTime);
    this->mainView.setCenter(this->player->body.getPosition().x + 50, (this->player->body.getPosition().y)); //set centerview
    this->player->Updateplayer(this->deltaTime);
    this->enermy->UpdateEnermy(this->deltaTime);
    this->player->animateplayer(this->deltaTime);

    this->item->UpitemSpeed(this->deltaTime);
    this->item->Upitemheart(this->deltaTime);
    this->item->UpenermyInk(this->deltaTime);
    
    ///enermies and collision

    this->updateCollision();
    this->chasing(this->deltaTime);
    
    this->randomenemies();
    this->randomObject();

    ///GUI

    this->player->getPoints();
    
    this->updateGUI();

    if (losshp == true)
    {
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
    }
    if (this->gethp == true)
    {
        if (this->hp == 3)
        {
            heart[2]->setTextureRect(sf::IntRect(24, 1, 24, 24));
        }
        if (this->hp == 2)
        {
            heart[1]->setTextureRect(sf::IntRect(24, 1, 24, 24));
        }

    }
    if (this->hp == 0)
    {
        this->endGame = true;
    }



    if (useItem == true)
    {

        if (this->storeItem == 2)
        {
            speed[2]->setTextureRect(sf::IntRect(0, 24, 24, 24));
        }
        if (this->storeItem == 1)
        {
            speed[1]->setTextureRect(sf::IntRect(0, 24, 24, 24));
        }
        if (this->storeItem == 0)
        {
            speed[0]->setTextureRect(sf::IntRect(0, 24, 24, 24));
        }
    }

    if (this->getItem1 == true)
    {
        if (this->storeItem == 3)
        {
            speed[2]->setTextureRect(sf::IntRect(24, 24, 24, 24));
        }
        if (this->storeItem == 2)
        {
            speed[1]->setTextureRect(sf::IntRect(24, 24, 24, 24));
        }
        if (this->storeItem == 1)
        {
            speed[0]->setTextureRect(sf::IntRect(24, 24, 24, 24));
        }

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
        //this->platform->updateplat(this->deltaTime);
      
       
        this->enermy->Drawenermy(*this->window);
        
        this->Object->DrawObject(*this->window);
        this->window->draw(*this->sandbar[0]);
        this->window->draw(*this->sandbar[1]);
        this->window->draw(*this->sandbar[2]);
        this->window->draw(*this->sandbar[3]);
        this->window->draw(*this->port[0]);

        this->player->Drawplayer(*this->window);

        this->item->Drawitem(*this->window);


        


        /// draw object ด้วย vector
        /* for (int i = 0; i < Objects.size(); i++)
        {
            Objects[i].DrawObject(*this->window);
        }*/

       

           

        //ทำให้ GUI อยู่ในขอบ View ด้วย
        this->window->setView(window->getDefaultView());
        this->renderGUI(this->window);
        this->window->draw(*this->heart[0]);
        this->window->draw(*this->heart[1]);
        this->window->draw(*this->heart[2]);
     
        this->window->draw(*this->speed[0]);
        this->window->draw(*this->speed[1]);
        this->window->draw(*this->speed[2]);
    

       
       

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->paused = true;
        this->playState = false;
    }
   
}

void game::unpauseState()
{
    this->paused = false;
}










 