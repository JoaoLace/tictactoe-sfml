#include "include/gui.h"

void gui::init() {
    initFonts();
    initText();
    initVariables();
}

void gui::initFonts() {
    if (!font.loadFromFile(font_path)) {
        std::cout << "ERROR: FAILED TO LOAD FONT FROM: " << font_path;
    }
}

void gui::initVariables(){
    goTo2Players = false;
}

void gui::initText() {
    texts = new std::vector<sf::Text>;
    endTexts = new std::vector<sf::Text>;
    createText({0,0}, font_color, font_size, "Reaaaalllyy simple Tic-Tac-Toe Game using SFML"); 
    createText({0,60}, font_color, font_size, "Source at: https://github.com/JoaoLace/tictactoe-sfml");
    createText({150,120},font_color, font_size, "*Play (1 Player)*");
    createText({150,180},font_color, font_size, "*Play (2 Players)*");
}

void gui::render(sf::RenderTarget &window) {
    renderText(window);
}

void gui::renderText(sf::RenderTarget &window) {
    if (texts) { 
        for (auto& x : *texts) {
            window.draw(x);
        }
    }
}

void gui::createText(sf::Vector2f pos, sf::Color color, size_t size, std::string text) {
    sf::Text temp;
    temp.setFont(font);
    temp.setPosition(pos);
    temp.setFillColor(color);
    temp.setCharacterSize(size);
    temp.setString(text);

    if (texts) {
        texts->push_back(temp);
    }
}

gui::~gui() {
    if (texts) { 
        delete texts; 
        texts = nullptr; 
    }
    if (endTexts){
        delete endTexts;
        endTexts = nullptr;
    }
}

void gui::update(sf::RenderTarget& target){
    testMouse(target);
    testMouse2(target);
}

void gui::testMouse(sf::RenderTarget& target) {
    sf::Vector2f mousePos = getMousePos(target);
    sf::FloatRect playButtonRect = texts->at(3).getGlobalBounds(); 

    if (pointInRect(mousePos, playButtonRect)) {
        texts->at(3).setFillColor(sf::Color::White);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            std::cout << "\n\"*Play (2 Players)*\" text is being pressed\n";
            goTo2Players = true;
            sf::sleep(sf::seconds(0.5));
        }
    } else {
        texts->at(3).setFillColor(sf::Color::Red);
    }
}


void gui::testMouse2(sf::RenderTarget& target)
{
    sf::Vector2f mousePos = getMousePos(target);
    sf::FloatRect playButtonRect = texts->at(2).getGlobalBounds(); 
        if (pointInRect(mousePos, playButtonRect)) {
            texts->at(2).setFillColor(WHITE);
        if (sf::Mouse::isButtonPressed(LEFT_BUTTON)) {
     
            std::cout << "\n\"*Play (1 Players)*\" text is being pressed\n";
            goTo1Player = true;
            sf::sleep(sf::seconds(0.5));
        }
        }else {
             texts->at(2).setFillColor(RED);

        }
}

void gui::renderEndScreen(sf::RenderTarget &window, char player){
    window.clear();
    renderEndText(window, player);
}

void gui::renderEndText(sf::RenderTarget &window, char player){
    createEndText(player);
     if (endTexts) { 
        for (auto& x : *endTexts) {
            window.draw(x);
        }
    }
}

void gui::createEndText(char player){
    sf::Text temp;
            temp.setCharacterSize(font_size);
            temp.setFont(font);
            temp.setFillColor(font_color);
            temp.setPosition(180,0);
    if (player == PLAYER1)
        {
            temp.setString ("Player 1 has won the game!!!\nClosing application in 2 seconds");
        }
    else if (player == PLAYER2)
        {
            temp.setString ("Player 2 has won the game!!!\nClosing application in 2 seconds");
        }
    endTexts->push_back(temp);
}


