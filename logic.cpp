#include "include/logic.h"
#include <iostream>

void tic::init()
{
  winner = 'c';
    for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
              {
                board[i][j] = ' ';
              }
        }
}

void tic::render()
{
      for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
              {
                std::cout << board[i][j];
                std::cout << " ";
              }
                std::cout << "\n";
        }
}

void tic::update(sf::Vector2i pos, char p)
{
    if (board[pos.x][pos.y] == ' ')
        board[pos.x][pos.y] = p;

}
const int tic::line(int l)
{
  return (int) board[l][0] + (int) board[l][1] + (int) board[l][2];

}
const int tic::columm(int c)
{
  return (int) board[0][c] + (int) board[1][c] + (int) board[2][c];
}

const int tic::diag1()
{
  return (int) board[0][0] + (int) board[1][1] + (int) board[2][2];
}
const int tic::diag2()
{
  return (int) board[0][2] + (int) board[1][1] + (int) board[2][0];
}

char tic::testWinner() {
    for (size_t i = 0; i < 3; i++) {
        if (line(i) == 360) {
            whereWasWon.type = LINE;
            whereWasWon.index = i;
            return PLAYER1;
        } else if (line(i) == 333) {
            whereWasWon.type = LINE;
            whereWasWon.index = i;
            return PLAYER2;
        }

        if (columm(i) == 360) {
            whereWasWon.type = COLUMM;
            whereWasWon.index = i;
            return PLAYER1;
        } else if (columm(i) == 333) {
            whereWasWon.type = COLUMM;
            whereWasWon.index = i;
            return PLAYER2;
        }
    }

    if (diag1() == 360) {
        whereWasWon.type = DIAGONAL;
        whereWasWon.index = 0;
        return PLAYER1;
    } else if (diag1() == 333) {
        whereWasWon.type = DIAGONAL;
        whereWasWon.index = 0;
        return PLAYER2;
    }

    if (diag2() == 360) {
        whereWasWon.type = DIAGONAL;
        whereWasWon.index = 1;
        return PLAYER1;
    } else if (diag2() == 333) {
        whereWasWon.type = DIAGONAL;
        whereWasWon.index = 1;
        return PLAYER2;
    }

    return GAME_RUNNING;
}


bool tic::testEndGame()
  {
    if (testWinner() != GAME_RUNNING)
      {
        testWinner() == PLAYER1 ? winner = PLAYER1 : winner = PLAYER2;
        return GAME_FINESHED;
      }
      return GAME_NOT_FINESHED;
  }

bool tic::tie()
{
   bool allPlayes = true;

  for (size_t i = 0; i < 3; i ++)
    {
      for (size_t j = 0; j < 3; j++)
        {
          if (board[i][j] == ' ')
            allPlayes = false;
        }
    }

    return allPlayes;
}