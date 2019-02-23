
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

extern const double WIN_WIDTH;
extern const double WIN_HEIGHT;

using namespace std;

Asteroid::Asteroid(int x, int y) {
	angle = rand() % 360 + 1;
	int radius = rand() % 70 + 6;

	shape.setRadius(radius);
	coordinates.x = x;
	coordinates.y = y;
	coordinates.dx = 0;
	coordinates.dy = 0;
	speed = rand() % 15 + 1;

	shape.setFillColor(sf::Color(224, 224, 224));
	shape.setOutlineThickness(4);
	shape.setOutlineColor(sf::Color(255, 255, 255));
	shape.setScale(sf::Vector2f(1.f, 1.f));
	shape.setPosition(coordinates.x, coordinates.y); /// this constructor allows you to change where ship is created
	shape.setRotation(angle);
}

void Asteroid::update() {
	struct Position pos = getPosition();

	pos.dx = speed * cos(degreesToRadians(angle));
    pos.dy = speed * sin(degreesToRadians(angle));

	pos.x += pos.dx;
	pos.y += pos.dy;

	if (pos.x > WIN_WIDTH) { // -4 is so that the ship moves in from the side gradually
		pos.x = 0;
	}
	if (pos.x < 0) {
		pos.x = WIN_WIDTH;
	}
	if (pos.y > WIN_HEIGHT) {
		pos.y = 0;
	}
	if (pos.y < 0) {
		pos.y = WIN_HEIGHT;
	}
	setPosition(pos);
}

void Asteroid::draw(sf::RenderWindow &window) {
	struct Position pos = getPosition();
	sf::Vector2f v1(pos.x, pos.y);
	shape.setPosition(v1);
	window.draw(shape);
}

struct Position Asteroid::getPosition() {
	return coordinates;
}

void Asteroid::setPosition(const struct Position &pos) {
	coordinates.x = pos.x;
    coordinates.y = pos.y;
    coordinates.dx = pos.dx;
    coordinates.dy = pos.dy;
}