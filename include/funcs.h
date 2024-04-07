#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include "logic.h"
#include "gui.h"

#define font_path "/home/joao/Dev/cpp/TICTACTOE/fonts/JetBrainsMono-Bold-Italic.ttf"
#define font_size 24
#define font_color sf::Color::Red
#define BLUE sf::Color::Blue
#define BLACK sf::Color::Black
#define RADIUS 80
#define RECT_SIZE sf::Vector2f(3,180)
#define RED sf::Color::Red
#define WHITE sf::Color::White
#define LEFT_BUTTON sf::Mouse::Left
#define PLAYER1 'x'
#define PLAYER2 'o'
#define GAME_FINESHED true
#define GAME_NOT_FINESHED false
#define GAME_RUNNING 'n'
#define LINE 'l'
#define DIAGONAL 'd'
#define COLUMM 'c'



const sf::Vector2f getMousePos(sf::RenderTarget& renderTarget);

bool pointInRect(sf::Vector2f point, sf::FloatRect rect);

