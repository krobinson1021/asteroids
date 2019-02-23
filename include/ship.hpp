
#ifndef ship_hpp
#define ship_hpp

#include <SFML/Graphics.hpp>

#include "position.hpp"

extern const double WIN_WIDTH;
extern const double WIN_HEIGHT;

class Ship {

private:

    double maxSpeed;

    double minSpeed;

    double angle;

    bool isAlive; /// False if ship hits asteroid

    struct Position coordinates;  /// Struct of position information and coordinates

public:

    struct Position getPosition();

    void setPosition(struct Position &dxy);

    Ship(); /// Constructor for ship at given coordinates

    sf::CircleShape shape {50, 3}; /// Shape of object

    void accelerate(double);

    void update();

    void draw(sf::RenderWindow &window);

    void rotate(double angle);

    void Reset(); /// Reset to center of screen and original angle

};

#endif /* ship_hpp */
