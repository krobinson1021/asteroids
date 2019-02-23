
#ifndef ship_hpp
#define ship_hpp

#include <SFML/Graphics.hpp>

#include "position.hpp"

extern const double WIN_WIDTH;
extern const double WIN_HEIGHT;

class Ship {

private:

    sf::CircleShape shape {50, 3};

    double maxSpeed;

    double minSpeed;

    double angle;

    struct Position coordinates;

public:

    Ship(); // constructs ship at center of screen

    void accelerate(double);

    void update();

    void draw(sf::RenderWindow &window);

    void rotate(double angle);

    struct Position getPosition();

    void setPosition(const struct Position &pos);

    void reset();

    double getAngle();

    struct Position getCenter();

};

#endif /* ship_hpp */
