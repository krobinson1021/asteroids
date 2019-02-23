
#ifndef asteroid_hpp
#define asteroid_hpp

#include <SFML/Graphics.hpp>

#include "position.hpp"

using namespace std;

class Asteroid {

private:

	sf::CircleShape shape {80, 8};

	double speed;

	struct Position coordinates;

	int angle;

public:

	Asteroid(int x, int y); // constructs ship at given coordinates

	void update();

	void draw(sf::RenderWindow &window);

	struct Position getPosition();

	void setPosition(const struct Position &pos);

	sf::CircleShape getShape();

};

#endif /* asteroid_hpp */
