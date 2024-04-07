#include "include/game.h"
 
int main()
{
    unsigned int seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);
    Game game;
    game.run();
    return 0;
}