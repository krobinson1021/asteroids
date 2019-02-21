
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "ship.hpp"

void Ship::UpdatePosition(double xVelocity, double yVelocity) {

    double xCor = shape.getPosition().x;
    double yCor = shape.getPosition().y;
    shape.setPosition(xCor + xVelocity, yCor + yVelocity);
}

Ship::Ship(sf::RenderWindow &window) {

    shape.setFillColor(sf::Color(102, 51, 255));
    shape.setOutlineThickness(4);
    shape.setOutlineColor(sf::Color(153, 255, 0));
    shape.setScale(sf::Vector2f(0.5f, 1.f));
    shape.setPosition(690, 690); // default constructor is to start in center of screen

    speed = 0;
    maximumSpeed = 75;
    isAlive = true;

    window.draw(shape);
}

Ship::Ship(double x, double y, sf::RenderWindow &window) {
    shape.setFillColor(sf::Color(102, 51, 255));
    shape.setOutlineThickness(4);
    shape.setOutlineColor(sf::Color(153, 255, 0));
    shape.setScale(sf::Vector2f(0.5f, 1.f));
    shape.setPosition(x, y); // this constructor allows you to change where ship is created

    speed = 0;
    maximumSpeed = 100;
    isAlive = true;

    window.draw(shape);
}

void Ship::VelocityAdjustment(sf::RenderWindow &window, bool alive, double &dx, double &dy, double &x, double &y, double &angle) {

    double windowWidth = 1400;
    double windowHeight = 1400;

    if (alive == true) {
        dx += cos(degreesToRadians(angle));
        dy += sin(degreesToRadians(angle));
    } else {
        dx *= 0.99; // slows x velocity gradually when up key not pressed
        dy *= 0.99; // slows y velocity gradually when up key not pressed
    }

    double speed = sqrt((dx * dx) + (dy * dy)); // pythagorean theorem
    if (speed > maximumSpeed) {
        dx *= maximumSpeed / speed;
        dy *= maximumSpeed / speed;
    }

    x += dx; // x position += x velocity
    y += dy; // y position += y velocity


    if (x > windowWidth) { // right edge cases
        x = 0;
    }

    if (x < 0) { // left edge cases
        x = windowWidth;
    }

    if (y > windowHeight - 1) { // bottom edge cases
        y = 0;
    }

    if (y < 0) { // top edge cases
        y = windowHeight - 1;
    }

    shape.setPosition(x, y); // updates coordinates of ship object
    shape.setRotation(angle + 90);
}
