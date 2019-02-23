
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
const int NUM_ASTEROIDS = 8;

int main() {

// Creating game window and setting framerate limit

    sf::ContextSettings settings; /// antialiasing to smooth shapes
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "ASTEROIDS!", sf::Style::Default, settings);
    window.setFramerateLimit(60);

// Loading background texture

    sf::Texture stars;
    if (!stars.loadFromFile("../graphics/stars.png")) {
        cout << "Error loading background." << endl;
        return 0;
    }
    sf::Sprite background(stars);

// Creating player ship and the vectors of Asteroids and Bullets

    Ship player = Ship();
    vector<Asteroid> allAsteroids = createAsteroids(NUM_ASTEROIDS);
    vector<Laser> allLasers;

/// Beginning main game loop and showing Start Menu

    sf::Event event;

    while (window.waitEvent(event)) { // if player presses 's' begin game
        displayStartScreen(window);
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
            break;
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
            window.close();
        }
    }
    while (window.isOpen()) {
        window.clear();
        window.draw(background);

// Player movement listeners

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.rotate(-5);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.accelerate(2);
        } else {
            player.accelerate(-.1);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.rotate(5);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.accelerate(-2);
        }

// Listen for spacebar firing command

        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyReleased:
                if (event.key.code == sf::Keyboard::Space) {
                    Laser l = Laser(player);
                    allLasers.push_back(l);
                }
                break;
            default:
                break;
            }
        }

// Allow user to exit game with 'q'

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            window.close();
        }

// Updating object positions

        for (int i = 0; i < allLasers.size(); i++) {
            allLasers[i].update();
            allLasers[i].draw(window);
        }

        player.update();
        player.draw(window);

        for (int i = 0; i < allAsteroids.size(); i++) {
            allAsteroids[i].update();
            allAsteroids[i].draw(window);
        }

// Checking for hits and collisions

        for (int i = 0; i < allAsteroids.size(); i++) {
            for (int j = 0; j < allLasers.size(); j++) {
                if (checkHit(allAsteroids[i], allLasers[j])) {
                    allLasers.erase(allLasers.begin() + j);
                    allAsteroids[i].explode(allAsteroids);
                    allAsteroids.erase(allAsteroids.begin() + i);
                }
            }
        }
        bool collision = false;
        for (Asteroid a : allAsteroids) {
            if (checkCollision(a, player)) {
                collision = true;
            }
        }
        if (collision) {
            displayGameOverScreen(window);
            while (window.waitEvent(event)) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    player.reset();
                    allAsteroids = createAsteroids(NUM_ASTEROIDS); // create new asteroids
                    removeLasers(allLasers);
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    window.close();
                }
            }
        }

// Checking for win (asteroids cleared)

        if (allAsteroids.size() == 0) {
            displayGameWinScreen(window);
            while (window.waitEvent(event)) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    player.reset();
                    allAsteroids = createAsteroids(NUM_ASTEROIDS); // create new asteroids
                    removeLasers(allLasers);
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                    window.close();
                }
            }
        }

        window.display(); // Updating screen
    }
    return 0;
}
