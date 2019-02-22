
#include <cmath>
#include <iostream>
#include <vector>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

extern const double WIN_WIDTH;
extern const double WIN_HEIGHT;

using namespace std;

void Ship::UpdatePosition() {
    struct Position curPos = getPosition();
    curPos.x += curPos.dx;
    curPos.y += curPos.dy;

    if (curPos.x > WIN_WIDTH - 3) {
        curPos.x = -3;
    }
    if (curPos.x < -3) {
        curPos.x = WIN_WIDTH + 3;
    }
    if (curPos.y > WIN_HEIGHT - 3) {
        curPos.y = -3;
    }
    if (curPos.y < -3) {
        curPos.y = WIN_HEIGHT + 3;
    }
    setPosition(curPos);
}

Ship::Ship() {
    coordinates.x = WIN_WIDTH / 2;
    coordinates.y = WIN_HEIGHT / 2;
    coordinates.dy = 1;
    coordinates.dx = 1;
    maximumSpeed = 75;
    minSpeed = 1;

    shape.setFillColor(sf::Color(102, 51, 255));
    shape.setOutlineThickness(4);
    shape.setOutlineColor(sf::Color(153, 255, 0));
    shape.setScale(sf::Vector2f(0.5f, 1.f));
    shape.setPosition(coordinates.x, coordinates.y); /// this constructor allows you to change where ship is created

    double currentAngle = atan2 (coordinates.dy, coordinates.dx);
    currentAngle = radiansToDegrees(currentAngle);
    currentAngle += 90;

    shape.setRotation(currentAngle);

    isAlive = true;
}

void Ship::reset() {

    coordinates.x = WIN_HEIGHT / 2;
    coordinates.y = WIN_WIDTH / 2;
    coordinates.dy = 1;
    coordinates.dx = 1;
    maximumSpeed = 75;
    minSpeed = 1;

    double currentAngle = atan2 (coordinates.dy, coordinates.dx);
    currentAngle = radiansToDegrees(currentAngle);
    currentAngle += 90;
    shape.setRotation(currentAngle);

    isAlive = true;

}

void Ship::changeSpeed(double speedInc) {
    struct Position curPos = getPosition();
    double speed = sqrt(curPos.dx * curPos.dx + curPos.dy * curPos.dy);

    // to increase or decrease speed
    if (speedInc > 0) {
        speed += speedInc;
    } else {
        speed *= .99;
    }

    // enforce min and max speeds
    if (speed < minSpeed) {
        speed = minSpeed;
    } else if (speed > maximumSpeed) {
        speed = maximumSpeed;
    }

    double currentAngle = atan2 (curPos.dy, curPos.dx);
    curPos.dx = speed * cos(currentAngle);
    curPos.dy = speed * sin(currentAngle);
    setPosition(curPos);

}

void Ship::RotateIncrement(double newAngle) {
    double radian = degreesToRadians(newAngle);
    shape.rotate(newAngle);

    // get current position
    struct Position curPos = getPosition();

    // update
    double currentAngle = atan2 (curPos.dy, curPos.dx);
    radian += currentAngle;

    double hyp = sqrt(curPos.dx * curPos.dx + curPos.dy * curPos.dy);
    curPos.dx = hyp * cos(radian);
    curPos.dy = hyp * sin(radian);

    // set new position
    setPosition(curPos);
}

struct Position Ship::getPosition() {
    return coordinates;
}

void Ship::setPosition(struct Position &dxy) {
    coordinates.x = dxy.x;
    coordinates.y = dxy.y;
    coordinates.dx = dxy.dx;
    coordinates.dy = dxy.dy;

    return;
}

void Ship::setPositionIncrement(struct Position &dxy) {
    coordinates.x += dxy.x;
    coordinates.y += dxy.y;
    return;
}

void Ship::draw(sf::RenderWindow &window) {
    struct Position curPos = getPosition();
    sf::Vector2f v1(curPos.x, curPos.y);
    shape.setPosition(v1);

    window.draw(shape);

    return;
}








