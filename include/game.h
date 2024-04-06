#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "logic.h"
#define BLUE sf::Color::Blue
#define BLACK sf::Color::Black
#define RADIUS 80
#define RECT_SIZE sf::Vector2f(3,180)
#define RED sf::Color::Red
#define WHITE sf::Color::White
class tic;
class Game{
public:
    void run();
    ~Game();
private:
    tic Tic;

    void render();
    void renderPlays();

    void draw();

    void update();
    void updateEvent();
    void updateMousePos();
    void updateBoard(sf::Vector2i pos, char p);
    void createPlay(char player, sf::Vector2i pos);
    
    void printWinner(char player);
    void printPlay(char player);
    void printTest();
    void printEndScreen();

    bool endGame();

    void init();
    void initShapes();

    bool gameRunning;
    bool atEndScreen;

    std::unique_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Event> event;
    std::array<std::unique_ptr<sf::RectangleShape>, 4> lines;

    std::vector<sf::RectangleShape> *player1Moves;
    std::vector<sf::CircleShape> *player2Moves;

    sf::RectangleShape *endLine;

    const sf::Vector2f getMousePos();
    const sf::Vector2i getGridePos(sf::Vector2f pos);
    const sf::Vector2i gridePosToPixels(sf::Vector2i gridePos);

    char player;
    int control = 0;

    bool crtl;


};