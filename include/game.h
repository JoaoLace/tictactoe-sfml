#pragma once
#include "funcs.h"

class Game{
public:
    void run();
    ~Game();
private:
    tic Tic;
    gui Gui;

    void render();
    void renderPlays();
    void renderInicialScreen();

    void draw();

    void update();
    void updateEvent();
    void updateMousePos();
    void updateBoard(sf::Vector2i pos, char p);
    void createPlay(char player, sf::Vector2i pos);
    void updateGui();
    void update1player();
    
    void botPlays();
    bool valid_play(sf::Vector2i play);
    sf::Vector2i get_Botplay();
    
    void printWinner(char player);
    void printPlay(char player);
    void printTest();
    void printEndScreen();

    bool endGame();

    void init();
    void initShapes();

    bool gameRunning;
    bool atEndScreen;
    bool showGuiEnd;
    bool single_player;

    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Event> event;
    std::array<std::unique_ptr<sf::RectangleShape>, 4> lines;

    std::vector<sf::RectangleShape> *player1Moves;
    std::vector<sf::CircleShape> *player2Moves;

    sf::RectangleShape *endLine;

    const sf::Vector2i getGridePos(sf::Vector2f pos);
    const sf::Vector2i gridePosToPixels(sf::Vector2i gridePos);

    char player;
    int control = 0;

    bool crtl;
    bool atGui;



};