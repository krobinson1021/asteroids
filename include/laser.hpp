
#ifndef classlaser_hpp
#define classlaser_hpp

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace std;

class Laser {

private:

	double speed; // How fast the laser beam moves

	bool isInsideWindow; // True if laser beam is still visible

public:

	Laser (sf::RenderWindow &window);

	Laser (sf::RenderWindow &window, double x, double y); // Creates laser beam at tip of ship

	sf::CircleShape shape {4, 20}; // Shape representing the ship

	void UpdatePosition(double x, double y); // Sets new x and y coordinates

};

#endif /* classasteroid_hpp */
