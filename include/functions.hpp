
#ifndef functions_hpp
#define functions_hpp

#include <SFML/Graphics.hpp>

#include "position.hpp"
#include "ship.hpp"

using namespace std;

void displayGameOverScreen(sf::RenderWindow &);

double degreesToRadians(double degrees);

double radiansToDegrees(double radians);

void displayStartScreen(sf::RenderWindow &window);

bool collisionOccurred(Asteroid asteroid, Ship player);

double getDistance(int x1, int y1, int x2, int y2);

void shuffle(vector<Asteroid> &asteroids);

#endif /* functions_hpp */
