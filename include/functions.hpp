
#ifndef functions_hpp
#define functions_hpp

#include <SFML/Graphics.hpp>

#include "asteroid.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

using namespace std;

void displayGameWinScreen(sf::RenderWindow &window);

void displayGameOverScreen(sf::RenderWindow &);

double degreesToRadians(double degrees);

double radiansToDegrees(double radians);

void displayStartScreen(sf::RenderWindow &window);

bool checkCollision(Asteroid asteroid, Ship player);

bool checkHit(Asteroid asteroid, Laser laser);

double getDistance(int x1, int y1, int x2, int y2);

vector<Asteroid> createAsteroids(int numberOfAsteroids);

void removeLasers(vector<Laser> &lasers);

#endif /* functions_hpp */
