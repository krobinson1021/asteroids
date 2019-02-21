
#ifndef functions_hpp
#define functions_hpp

#include <SFML/Graphics.hpp>

/**
    Changes screen to end screen.

    @param the window on which end game screen should be displayed.
*/
void GameEndsLose(sf::RenderWindow &);

/**
    Adjusts object's coordinates after it goes off screen (wraps).

    @param x-coordinate
    @param y-coordinate
*/
void WrapAround(double xCor, double yCor);

/**
    Converts degrees to radians.

    @param angle in degrees
    @return angle in radians
*/
double degreesToRadians(double degrees);

#endif /* functions_hpp */
