#pragma once

#include "funcs.h"

class gui{
public:
    ~gui();

    void init();
    void initFonts();
    void initText();
    void initVariables();

    void renderEndScreen(sf::RenderTarget &window, char player);
    void render(sf::RenderTarget &window);
    void renderText(sf::RenderTarget &window);
    void renderEndText(sf::RenderTarget &window, char player);

    void createText(sf::Vector2f pos, sf::Color color, size_t size, std::string text);
    void createEndText(char player);

    void update(sf::RenderTarget& target);

    void testMouse(sf::RenderTarget& target);
    void testMouse2(sf::RenderTarget& target);


    std::vector <sf::Text> *texts;
    std::vector <sf::Text> *endTexts;


    sf::Font font;
    sf::Text text;
    

    bool goTo2Players;
    bool goTo1Player;


};