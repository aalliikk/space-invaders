#ifndef SCOREDISPLAY_H
#define SCOREDISPLAY_H

#include <SFML/Graphics.hpp>

class ScoreDisplay
{
private:
    static constexpr unsigned X = 0;
    static constexpr unsigned Y = 0;

    // Reference to the game score, which is a variable declared in main().
    unsigned &game_score;

public:
    ScoreDisplay(unsigned &score);

    void draw(sf::RenderWindow &window);
    void reset() { this->game_score = 0; }

};

#endif
