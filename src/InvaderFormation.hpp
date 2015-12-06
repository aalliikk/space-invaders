#ifndef INVADERFORMATION_H
#define INVADERFORMATION_H

#include <SFML/Graphics.hpp>
#include "SoundFx.hpp"
#include "Invader.hpp"
#include "PlayerLaser.hpp"

typedef std::vector<Invader*> InvaderRow;
typedef std::vector<InvaderRow> InvaderVector2D;

class InvaderFormation
{
private:
    // Size of formation
    static const unsigned COLUMNS = 5;
    static const unsigned ROWS = 11;

    // Where the formation starts on screen
    static const unsigned STARTX = 120;
    static const unsigned STARTY = 100;

    // The space between each invader in the formation
    static const unsigned XGAP = 55;
    static const unsigned YGAP = 50;

    // Gameplay
    static const unsigned MOVE_TICK_MAX_START = 45;
    static const unsigned MOVE_TICK_CHANGE_START = 5;

    sf::RenderWindow &window;
    sf::Image &spritesheet;
    InvaderVector2D invaders;

    SoundFx &death_snd;
    unsigned screenw;
    
    // When move_tick hits move_tick_max, the formation moves
    // move_tick_max is lowered every time formation hits edge of screen
    unsigned move_tick;
    unsigned move_tick_max;
    unsigned move_tick_change;

public:
    InvaderFormation(sf::RenderWindow &window, sf::Image &spritesheet, SoundFx &death_snd, unsigned screenw);
    ~InvaderFormation();

    // This is bool so main game can keep track when Invader actually moved
    bool move();

    // Increase speed, drop down, and reverse direction!
    void shift();

    void checkHit(PlayerLaser &laser);

    void draw();

};

#endif
