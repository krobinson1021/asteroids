
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "ship.hpp"

using namespace std;

Laser::Laser (sf::RenderWindow &window, double x, double y) {
	shape.setFillColor(sf::Color(255, 20, 147));
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color(145, 55, 238));
	shape.setScale(sf::Vector2f(1.f, 1.f));
	shape.setPosition(x, y);
	speed = 40;
	isInsideWindow = true;
	window.draw(shape);
}
