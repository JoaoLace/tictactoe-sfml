#include "include/funcs.h"

const sf::Vector2f getMousePos(sf::RenderTarget& renderTarget)
{
    const sf::RenderWindow* window = dynamic_cast<const sf::RenderWindow*>(&renderTarget);

    if (window)
    {
        return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
    }
    else
    {
        return sf::Vector2f(-1, -1); 
    }
}

bool pointInRect(sf::Vector2f point, sf::FloatRect rect) {
    return rect.contains(point);
}