
#ifndef ship_hpp
#define ship_hpp

#include <SFML/Graphics.hpp>

#include "position.hpp"

extern const double WIN_WIDTH;
extern const double WIN_HEIGHT;

class Ship {

private:

    double maximumSpeed;

    double minSpeed;

    bool isAlive; /// False if ship hits asteroid

    struct Position coordinates;  /// Struct of position information and coordinates

public:

    struct Position getPosition();

    void setPosition(struct Position &dxy);

    void setPositionIncrement(struct Position &dxy);

    void reset();

    Ship(); /// Constructor for ship at given coordinates

    sf::CircleShape shape {50, 3}; /// Shape of object

    void changeSpeed(double);

    void UpdatePosition();

    void draw(sf::RenderWindow &window);

    void RotateIncrement(double angle);

    void Reset(); /// Reset to center of screen and original angle

};

#endif /* ship_hpp */
