#pragma once
#include <SFML/Graphics.hpp>
#define PLAYER1 'x'
#define PLAYER2 'o'
#define GAME_FINESHED true
#define GAME_NOT_FINESHED false
#define GAME_RUNNING 'n'
#define LINE 'l'
#define DIAGONAL 'd'
#define COLUMM 'c'
typedef struct{
    int index;
    char type;
}where;
class tic{
public:
    char board[3][3];

    void update(sf::Vector2i pos, char p);
    bool running();
    void init();
    void render();
    char testWinner();
    bool testEndGame();
    bool tie();
    const int line(int l);
    const int columm(int c);
    const int diag1();
    const int diag2();
    char winner;
    where whereWasWon;

};