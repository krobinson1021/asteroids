
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

using namespace std;

const double WIN_WIDTH = 1400;
const double WIN_HEIGHT = 1400;
const int NUM_ASTEROIDS = 10;

int main() {

/// Creating game window and setting framerate limit

    sf::ContextSettings settings; /// antialiasing to smooth shapes
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "ASTEROIDS!", sf::Style::Default, settings);

    window.setFramerateLimit(60);

/// Loading background texture

    sf::Texture stars;

    if (!stars.loadFromFile("../graphics/stars.png")) {
        cout << "Error loading background." << endl;
        return 0;
    }

    sf::Sprite background(stars);

/// Creating player ship and the vectors of Asteroids and Bullets

    Ship player = Ship();

    vector<Asteroid> allAsteroids;
    for (int i = 0; i < (NUM_ASTEROIDS / 4); i++) {
        int width = (int) WIN_WIDTH;
        int height = (int) WIN_HEIGHT;
        int x = rand() % width;
        int y = rand() % height;
        Asteroid asteroid1 = Asteroid(x, 0);
        Asteroid asteroid2 = Asteroid(x, WIN_HEIGHT);
        Asteroid asteroid3 = Asteroid(0, y);
        Asteroid asteroid4 = Asteroid(WIN_WIDTH, y);
        allAsteroids.push_back(asteroid1);
        allAsteroids.push_back(asteroid2);
        allAsteroids.push_back(asteroid3);
        allAsteroids.push_back(asteroid4);
    }

    vector<Laser> allLasers;

/// Beginning main game loop and showing Start Menu

    sf::Event event;

    while (window.waitEvent(event)) {

        displayStartScreen(window);

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
            break;
        }
    }

    while (window.isOpen()) {
        window.clear();
        window.draw(background);

        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }

/// User input (keypress events)

        /// Rotate counterclockwise with left arrow key

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.rotate(-5);
        }

        /// Increase thrust with up arrow key

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.accelerate(2);
        } else {
            player.accelerate(-.1);
        }

        /// Rotate clockwise with right arrow key

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.rotate(5);
        }

        /// Decrease thrust with down arrow key

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.accelerate(-2);
        }

        /// Fire bullets with space key and push them back into vector

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Laser l = Laser(player);
            allLasers.push_back(l);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            window.close();
        }

        player.update();
        player.draw(window);

        for (int i = 0; i < allAsteroids.size(); i++) {
            allAsteroids[i].update();
            allAsteroids[i].draw(window);
        }

        for (int i = 0; i < allLasers.size(); i++) {
            allLasers[i].update();
            allLasers[i].draw(window);
        }


// If ship hits asteroid, display game over screen

        bool collision = false;
        for (Asteroid a : allAsteroids) {
            if (collisionOccurred(a, player)) {
                collision = true;
            }
        }
        if (collision) {
            displayGameOverScreen(window);
            player.reset();
            shuffle(allAsteroids);
            while (window.waitEvent(event)) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    window.close();
                }
            }
        }

/// Updating positions and redrawing asteroids

        window.display();
    }
    return 0;
}
