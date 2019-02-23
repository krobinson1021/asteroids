
#include <cmath>
#include <SFML/Graphics.hpp>
#include <vector>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

using namespace std;

Laser::Laser(Ship player) {
	coordinates.x = player.getPosition().x;
	coordinates.y = player.getPosition().y;
	coordinates.dx = player.getPosition().dx;
	coordinates.dy = player.getPosition().dy;
	angle = player.getAngle();
	speed = 8;
	shape.setFillColor(sf::Color(255, 255, 255));
}

void Laser::update() {
	struct Position pos = getPosition();

	pos.dx = speed * cos(degreesToRadians(angle));
	pos.dy = speed * sin(degreesToRadians(angle));

	pos.x += pos.dx;
	pos.y += pos.dy;

	setPosition(pos);
}

void Laser::draw(sf::RenderWindow &window) {
	struct Position pos = getPosition();
	sf::Vector2f v1(pos.x, pos.y);
	shape.setPosition(v1);
	window.draw(shape);
}

struct Position Laser::getPosition() {
	return coordinates;
}

void Laser::setPosition(const struct Position &pos) {
	coordinates.x = pos.x;
	coordinates.y = pos.y;
	coordinates.dx = pos.dx;
	coordinates.dy = pos.dy;
}

sf::CircleShape Laser::getShape() {
	return shape;
}
