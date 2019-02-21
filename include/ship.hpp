
#ifndef class_hpp
#define class_hpp

#include <SFML/Graphics.hpp>

class Ship {

private:

	double speed; // How fast ship is currently moving

	bool isAlive; // True if ship has not hit an asteroid

public:

	double maximumSpeed; // Speed will no longer increase while boosting after this threshold

	Ship (sf::RenderWindow &window); // Default constructor (starts in middle of screen with angle 0)

	Ship (double x, double y, sf::RenderWindow &window); // Constructor of ship at given coordinates

	sf::CircleShape shape {50, 3};

	void UpdatePosition(double x, double y); // Sets new ship coordinates

	bool WasHit(double x, double y); // Returns true if x and y are within both asteroid and ship

	void VelocityAdjustment(sf::RenderWindow &window, bool alive, double &dx, double &dy, double &x, double &y, double &angle);

};

#endif /* class_hpp */
