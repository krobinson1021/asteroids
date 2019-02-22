
#ifndef functions_hpp
#define functions_hpp

#include <SFML/Graphics.hpp>

#include "position.hpp"

using namespace std;

void displayGameOverScreen(sf::RenderWindow &);

double degreesToRadians(double degrees);

double radiansToDegrees(double radians);

void displayStartScreen(sf::RenderWindow &window);

#endif /* functions_hpp */
