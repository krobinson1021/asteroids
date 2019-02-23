
#ifndef laser_hpp
#define laser_hpp

#include <SFML/Graphics.hpp>
#include <vector>

#include "position.hpp"
#include "ship.hpp"

using namespace std;

class Laser {

private:

	sf::CircleShape shape {2, 30};

	double speed;

	struct Position coordinates;

	int angle;

public:

	Laser(Ship player);

	void update();

	void draw(sf::RenderWindow &window);

	struct Position getPosition();

	void setPosition(const struct Position &pos);

	sf::CircleShape getShape();

};

#endif /* laser_hpp */
