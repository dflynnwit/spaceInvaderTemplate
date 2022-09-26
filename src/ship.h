//ship.h

#ifndef CMAKESFMLPROJECT_SHIP_H
#define CMAKESFMLPROJECT_SHIP_H

#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
protected:
    sf::IntRect _sprite;
    //Default constructor is hidden
    Ship();
public:
    //Constructor that takes a sprite
    explicit Ship(sf::IntRect ir);
    //Pure virtual deconstructor -- makes this an abstract class
    virtual ~Ship() = 0;
    //Update, virtual so can be overrided, but not pure virtual
    virtual void Update(const float &dt);
};

//ship.h
class Invader : public Ship {
public:
    static bool direction;
    //[[maybe_unused]]
    static float speed;

    Invader(sf::IntRect ir, sf::Vector2f pos);
    Invader();
    void Update(const float &dt) override;


};


class Player : public Ship {
public:
    Player();
    void Update(const float &dt) override;
};



#endif //CMAKESFMLPROJECT_SHIP_H
