
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "ship.hpp"

using namespace std;

const double WIN_WIDTH = 1400;
const double WIN_HEIGHT = 1400;

int main() {

    // Rocket starts at middle of screen with no velocity
    double x = WIN_WIDTH / 2;
    double y = WIN_HEIGHT / 2;
    double dx = 0;
    double dy = 0;

    double dxShape = 0;
    double dyShape = 0;
    double xLaser = 0;
    double yLaser = 0;
    double angle = 0;
    bool rocketBoost = false; // true if up arrow is pressed
    bool isShooting = false; // true if laser is being fired
    double angle1 = 250;
    double angle2 = 30;
    double angle3 = -180;

    sf::ContextSettings settings; // Antialiasing to smooth shapes
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "ASTEROIDS!", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::Texture stars;
    if (!stars.loadFromFile("../graphics/stars.png")) {
        cout << "Error loading background." << endl;
        exit(EXIT_FAILURE);
    }
    sf::Sprite background(stars);

    Ship player(window); // Create a ship on the screen
    Laser beam(window, -1, -1);

    while (window.isOpen()) { // Run the program as long as the window is open

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { // Close gracefully upon request
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { // Rotate counterclockwise
            angle -= 5;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { // Move forward
            rocketBoost = true;
        } else {
            rocketBoost = false;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // Rotate clockwise
            angle += 5;
        }

        player.VelocityAdjustment(window, rocketBoost, dx, dy, x, y, angle); // Ship physics

        Asteroid asteroid1 = Asteroid (20, 300, window, 5);
        Asteroid asteroid2 = Asteroid (697, 30, window, .8);
        Asteroid asteroid3 = Asteroid (1, 900, window, 1.1);

        asteroid1.VelocityAdjustment(window, angle1, dxShape, dyShape, -1); // Asteroid physics
        asteroid2.VelocityAdjustment(window, angle2, dxShape, dyShape, 3);
        asteroid3.VelocityAdjustment(window, angle3, dxShape, dyShape, 1);

        if (event.type == sf::Event::KeyPressed) { // Shoot laser beam
            if (event.key.code == sf::Keyboard::Space) {
                beam.shape.setPosition(x, y); // Sets position of beam to position of ship when space key pressed
            } else {
                isShooting = false;
            }
        }

        if (xLaser > 0) {
            xLaser += 10 * cos(degreesToRadians(angle));
            yLaser += 10 * sin(degreesToRadians(angle));
            beam.shape.setPosition(xLaser, yLaser);

            double xVelocityLaser = 10 * cos(degreesToRadians(angle));
            double yVelocityLaser = 10 * sin(degreesToRadians(angle));

            xLaser += xVelocityLaser;
            yLaser += yVelocityLaser;
        }

        window.clear();
        window.draw(background);

        if (xLaser > 0 || yLaser > 0) {
            window.draw(beam.shape);
        }

        window.draw(asteroid1.shape);
        window.draw(asteroid2.shape);
        window.draw(asteroid3.shape);
        window.draw(player.shape);
        window.display();
    }

    while (window.isOpen()) {
        window.display();
        GameEndsLose(window);

    }

    return 0;
}
