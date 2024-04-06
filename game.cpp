#include "include/game.h"
#include <chrono>
#include <thread>
void Game::render()
{
    if (!atEndScreen)
    {
        window->clear();

        draw();
        Tic.render();
        renderPlays();

        window->display();
    }
   
   else 
   {
    window->draw(*endLine);
    window->display();
   }
}

void Game::run()
{
    init();
    while (gameRunning or atEndScreen)
        {
            if (!crtl)
            {
                break;
            }
            if (!atEndScreen)
            {
                update();
            }
            if (atEndScreen)
            {
                    updateEvent();
            }
            render();
        }
    
}

 bool Game::endGame()
 {
    if (Tic.testEndGame() == GAME_FINESHED)
    {
        return GAME_FINESHED;
    }

    return GAME_NOT_FINESHED;
 }


void Game::init()
{
    gameRunning = true;
    atEndScreen = false;
    crtl = true;

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML window");
    window->setPosition(sf::Vector2i(600,300));

    event = std::make_unique<sf::Event>();

    player1Moves = new std::vector<sf::RectangleShape>();
    player2Moves = new std::vector<sf::CircleShape>();

    endLine = new sf::RectangleShape(sf::Vector2f(6,1500));
    endLine->setFillColor (WHITE);

    player = PLAYER1;

    initShapes();

    Tic.init();
}

void Game::initShapes()
{
    lines[0] = std::make_unique<sf::RectangleShape>(sf::Vector2f(3,800));
    lines[0]->setPosition (sf::Vector2f(266,0));
    lines[0]->setFillColor(sf::Color::Red);

    lines[1] = std::make_unique<sf::RectangleShape>(sf::Vector2f(3,800));
    lines[1]-> setPosition(sf::Vector2f(266*2,0));
    lines[1]->setFillColor(sf::Color::Red);

    lines[2] = std::make_unique<sf::RectangleShape>(sf::Vector2f(3,1000));
    lines[2]-> setPosition(sf::Vector2f(800,200));
    lines[2]-> setFillColor(sf::Color::Red);
    lines[2]-> rotate(90);

    lines[3] = std::make_unique<sf::RectangleShape>(sf::Vector2f(3,1000));
    lines[3]-> setPosition(sf::Vector2f(800,400));
    lines[3]-> setFillColor(sf::Color::Red);
    lines[3]-> rotate(90);

}

Game::~Game() {
    delete player1Moves;
    delete player2Moves;
}

void Game::updateEvent()
{
 sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                {
                     window->close();
                     gameRunning = false;;
                     crtl = false;
                }
               
        }
}

void Game::printWinner(char player)
{
    std::cout << "\n" <<  player << " is the winner!!\n";
}

void Game::update()
{
    updateEvent();


    if (endGame())
    {
        printWinner(Tic.winner);
        printEndScreen();
        gameRunning = false;
    }

    if (Tic.tie())
    {
        std::cout << "\nIts a tie!!\n";
        gameRunning = false;
    }

    updateMousePos();
}

void Game::draw()
{
     for (const auto& line : lines)
    {
        window->draw(*line);
    }
}

const sf::Vector2f Game::getMousePos()
{
   return (sf::Vector2f) sf::Mouse::getPosition(*window);
}

void Game::updateMousePos()
{

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            updateBoard(getGridePos(getMousePos()), player);
        }
    
}

const sf::Vector2i Game::getGridePos(sf::Vector2f pos)
{
    if (pos.y >= 0 and pos.y <= 200)
        {
            if (pos.x >= 0 and pos.x <= 266)
                return {0,0};

            else if (pos.x >= 266 and pos.x <= 530)
                return {0,1};
            
            else if (pos.x >= 530 and pos.x <= 800)
                return {0,2};
        }

    else if (pos.y >= 200 and pos.y <=400)
        {
              if (pos.x >= 0 and pos.x <= 266)
                return {1,0};

            else if (pos.x >= 266 and pos.x <= 530)
                return {1,1};
            
            else if (pos.x >= 530 and pos.x <= 800)
                return {1,2};
        }

      else if (pos.y >= 400 and pos.y <= 600)
        {
              if (pos.x >= 0 and pos.x <= 266)
                return {2,0};

            else if (pos.x >= 266 and pos.x <= 530)
                return {2,1};
            
            else if (pos.x >= 530 and pos.x <= 800)
                return {2,2};
        }

    return {0,0};
}

void Game::updateBoard(sf::Vector2i pos, char p)
{

    if (Tic.board[pos.x][pos.y] == ' ')
    {
        Tic.board[pos.x][pos.y] = p;
        createPlay(player, getGridePos(getMousePos()));

         if (player == PLAYER1)
                player = PLAYER2;

            else if (player == PLAYER2)
                player = PLAYER1;

    }

}

void Game::printEndScreen() {
    if (Tic.whereWasWon.type == LINE) {
        switch (Tic.whereWasWon.index) {
            case 0: // First row
                endLine->setPosition(sf::Vector2f(30, 110));
                endLine->setSize(sf::Vector2f(730, 6));
                break;
            case 1: // Second row
                endLine->setPosition(sf::Vector2f(30, 310));
                endLine->setSize(sf::Vector2f(730, 6));
                break;
            case 2: // Third row
                endLine->setPosition(sf::Vector2f(30, 510));
                endLine->setSize(sf::Vector2f(730, 6));
                break;
        }
    
    }
    else if (Tic.whereWasWon.type == COLUMM)
    {
         switch (Tic.whereWasWon.index) 
         {
            case 0: // First column
                endLine->setPosition(sf::Vector2f(130, 20));
                endLine->setSize(sf::Vector2f(6, 560));
                break;
            case 1: // Second column
                endLine->setPosition(sf::Vector2f(396, 20));
                endLine->setSize(sf::Vector2f(6, 560));
                break;
            case 2: // Third column
                endLine->setPosition(sf::Vector2f(662, 20));
                endLine->setSize(sf::Vector2f(6, 560));
                break;
        }
    }
   else if (Tic.whereWasWon.type == DIAGONAL) {
    switch (Tic.whereWasWon.index) {
        case 0: 
            endLine->setPosition(sf::Vector2f(10, -25)); 
            endLine->setSize(sf::Vector2f(1000, 6));
            endLine->rotate(38); 
            break;
        case 1: 
            endLine->setPosition(sf::Vector2f(10, -25)); 
            endLine->setSize(sf::Vector2f(1000, 6)); 
            endLine->rotate(-38); 
            break;
    }
}
    atEndScreen = true;
}


void Game::renderPlays()
{
    for (auto &x : *player1Moves)
    {
        window->draw(x);
    }

    for (auto &x : *player2Moves)
    {
        window->draw(x);
    }
}

const sf::Vector2i Game::gridePosToPixels(sf::Vector2i gridePos)
{
    int x,y;

    if (gridePos.y == 0)
        {
            x = 58;
        }

    else 
        {
            x = 58 + (266 * gridePos.y);
        }

    if (gridePos.x == 0)
        {
            y = 18;
        }

    else 
        {
            y = 18 + (200 * gridePos.x);
        }
    

    return {x,y};
}


void Game::createPlay(char player, sf::Vector2i pos) 
{
    if (player == PLAYER1) {
        sf::RectangleShape temp(RECT_SIZE);
        temp.setPosition( (float) gridePosToPixels(pos).x + 135, (float) gridePosToPixels(pos).y + 30);
        temp.setFillColor(BLUE);
        temp.rotate(45);

        player1Moves->push_back(temp);

        sf::RectangleShape temp2(RECT_SIZE);
        temp2.setPosition((float) gridePosToPixels(pos).x, (float) gridePosToPixels(pos).y + 30);
        temp2.setFillColor(BLUE);
        temp2.rotate(-45);
        player1Moves->push_back(temp2);
    }
    
    else if (player == PLAYER2) {
        sf::CircleShape temp(RADIUS);
        temp.setPosition( (sf::Vector2f) gridePosToPixels(pos));
        temp.setOutlineThickness(3);
        temp.setOutlineColor(BLUE);
        temp.setFillColor(BLACK);

        player2Moves->push_back(temp);
    }
}
