
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "asteroid.hpp"
#include "functions.hpp"
#include "ship.hpp"
#include "laser.hpp"

/**
    Updates the position of an asteroid given new coordinates.

    @param New x-coordinate
    @param New y-coordinate
*/
void Asteroid::UpdatePosition(double xVelocity, double yVelocity) {

    double xCor = shape.getPosition().x;
    double yCor = shape.getPosition().y;
    shape.setPosition(xCor + xVelocity, yCor + yVelocity);
}

/**
    Constructs an asteroid in the middle of the screen.

    @param Game window
    @return New asteroid
*/
Asteroid::Asteroid(sf::RenderWindow &window) {

    shape.setFillColor(sf::Color(102, 51, 255));
    shape.setOutlineThickness(4);
    shape.setOutlineColor(sf::Color(153, 255, 0));
    shape.setScale(sf::Vector2f(0.5f, 1.f));
    shape.setPosition(690, 690);

    isAlive = true;

    window.draw(shape);
}

/**
    Constructs an asteroid of the requested size at the requested coordinates.

    @param x-coordinate asteroid should spawn at
    @param y-coordinate asteroid should spawn at
    @oaram Game window
    @param Size multiplier
    @return New asteroid
*/
Asteroid::Asteroid(double x, double y, sf::RenderWindow &window, double sizeMultiplier) {
    shape.setFillColor(sf::Color(205, 193, 197));
    shape.setOutlineThickness(4);
    shape.setOutlineColor(sf::Color(248, 248, 255));
    shape.setScale(sf::Vector2f(1.f / sizeMultiplier, 1.f / sizeMultiplier));
    shape.setPosition(x, y);

    isAlive = true;

    window.draw(shape);
}

/**
    Updates the velocity of the asteroid.

    @param Game window
    @param Angle at which asteroid is moving
    @param x-velocity
    @param y-velocity
    @param Velocity multiplier
*/
void Asteroid::VelocityAdjustment(sf::RenderWindow &window, double angle, double &dx, double &dy, double modifier) {

    double windowWidth = 1400;
    double windowHeight = 1400;

    double x = shape.getPosition().x;
    double y = shape.getPosition().y;

    dx += cos(degreesToRadians(angle)) * 8;
    dy += sin(degreesToRadians(angle)) * 8;

    x += dx; // x position += x velocity
    y += dy; // y position += y velocity


    if (x > windowWidth) { // Right edge cases
        x = 0;
    }

    if (x < 0) { // Left edge cases
        x = windowWidth;
    }

    if (y > windowHeight) { // Bottom edge cases
        y = 0;
    }

    if (y < 0) { // Top edge cases
        y = windowHeight;
    }

    shape.setPosition(x, y); // Updates coordinates of asteroid
    shape.setRotation(angle);

}

