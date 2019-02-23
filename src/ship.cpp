
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

extern const double WIN_WIDTH;
extern const double WIN_HEIGHT;

using namespace std;

Ship::Ship() {
    coordinates.x = WIN_WIDTH / 2;
    coordinates.y = WIN_HEIGHT / 2;
    coordinates.dy = 0;
    coordinates.dx = 0;
    maxSpeed = 15;
    minSpeed = 0;
    angle = 0;

    shape.setFillColor(sf::Color(102, 51, 255));
    shape.setOutlineThickness(4);
    shape.setOutlineColor(sf::Color(255, 51, 153));
    shape.setScale(sf::Vector2f(0.5f, 1.f));
    shape.setPosition(coordinates.x, coordinates.y); /// this constructor allows you to change where ship is created
    shape.setRotation(angle + 90);
}

void Ship::update() {
    struct Position pos = getPosition();

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

void Ship::accelerate(double delta) {
    struct Position pos = getPosition();
    double speed = sqrt(pos.dx * pos.dx + pos.dy * pos.dy);
    speed += delta;
    if (speed > maxSpeed) {
        speed = maxSpeed;
    }
    if (speed < minSpeed) {
        speed = minSpeed;
    }
    pos.dx = speed * cos(degreesToRadians(angle));
    pos.dy = speed * sin(degreesToRadians(angle));
    setPosition(pos);
}

void Ship::rotate(double delta) {
    angle += delta;
    shape.setRotation(angle + 90);
}

void Ship::draw(sf::RenderWindow &window) {
    struct Position pos = getPosition();
    sf::Vector2f v1(pos.x, pos.y);
    shape.setPosition(v1);
    window.draw(shape);
}

struct Position Ship::getPosition() {
    return coordinates;
}

void Ship::setPosition(const struct Position &pos) {
    coordinates.x = pos.x;
    coordinates.y = pos.y;
    coordinates.dx = pos.dx;
    coordinates.dy = pos.dy;
}

void Ship::reset() {
    coordinates.x = WIN_WIDTH / 2;
    coordinates.y = WIN_HEIGHT / 2;
    coordinates.dy = 0;
    coordinates.dx = 0;
    maxSpeed = 65;
    minSpeed = 0;
    angle = 0;
    shape.setPosition(coordinates.x, coordinates.y); /// this constructor allows you to change where ship is created
    shape.setRotation(angle + 90);
}

double Ship::getAngle() {
    return angle;
}

struct Position Ship::getCenter() {
    struct Position center;
    sf::FloatRect rect = shape.getGlobalBounds();
    center.x = rect.left + (rect.width / 2);
    center.y = rect.top + (rect.height / 2);
    return center;
}




