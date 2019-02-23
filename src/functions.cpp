
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <vector>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

using namespace std;

void displayGameOverScreen(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);

    sf::Texture starsWithFlames;
    if (!starsWithFlames.loadFromFile("../graphics/starswithflames.png")) {
        cout << "Failed to load background image.\n";
    }
    sf::Sprite background(starsWithFlames);
    window.draw(background);

    sf::Font font;
    if (!font.loadFromFile("../graphics/8bit.ttf")) {
        cout << "Failed to load font.\n";
    }
    sf::Text text;
    text.setFont(font);
    text.setString("YOU DIED");
    text.setCharacterSize(140);
    text.setFillColor(sf::Color::Red);
    text.setPosition(230, 200);
    window.draw(text);

    window.display();
}

double degreesToRadians(double degrees) {
    return (degrees * (M_PI / 180));
}

double radiansToDegrees(double radians) {
    return (radians *  (180 / M_PI));
}

void displayStartScreen(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);

    sf::Texture startScreen;
    if (!startScreen.loadFromFile("../graphics/startscreen.png")) {
        cout << "Failed to load start screen.\n";
    }
    sf::Sprite background(startScreen);
    window.draw(background);

    window.display();
}

bool collisionOccurred(Asteroid asteroid, Ship ship) {
    int asteroidRadius = asteroid.getShape().getRadius();
    int asteroidX = asteroid.getShape().getPosition().x;
    int asteroidY = asteroid.getShape().getPosition().y;
    int shipX = ship.getPosition().x;
    int shipY = ship.getPosition().y;
    return ((getDistance(asteroidX, asteroidY, shipX, shipY) - asteroidRadius) < 0);
}

double getDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void shuffle(vector<Asteroid> &asteroids) {
    int width = (int) WIN_WIDTH;
    int height = (int) WIN_HEIGHT;
    for (int i = 0; i < asteroids.size(); i++) {
        int x = rand() % width;
        int y = rand() % height;
        struct Position pos = Position();
        pos.dx = 0;
        pos.dy = 0;
        if (i % 4 == 0) {
            pos.x = x;
            pos.y = 0;
            asteroids[i].setPosition(pos);
        } else if (i % 3 == 0) {
            pos.x = x;
            pos.y = height;
            asteroids[i].setPosition(pos);
        } else if (i % 2 == 0) {
            pos.x = 0;
            pos.y = y;
            asteroids[i].setPosition(pos);
        } else {
            pos.x = width;
            pos.y = y;
            asteroids[i].setPosition(pos);
        }
    }
}

