
#ifndef classasteroid_hpp
#define classasteroid_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

class Asteroid {

private:

	bool isAlive; // True until asteroid hits ship

public:

	Asteroid (sf::RenderWindow &window); // Default constructor

	Asteroid (double x, double y, sf::RenderWindow &window, double sizeMultiplier); // Constructor of asteroid at given coordinates

	sf::CircleShape shape {120, 7};

	void UpdatePosition(double x, double y); // Sets new x and y for asteroid

	void VelocityAdjustment(sf::RenderWindow &window, double angle, double &dx, double &dy, double modifier);

};

#endif /* classasteroid_hpp */
