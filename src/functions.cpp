
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <vector>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "position.hpp"
#include "ship.hpp"

extern const double WIN_WIDTH;
extern const double WIN_HEIGHT;

using namespace std;

void displayGameWinScreen(sf::RenderWindow &window) {
    window.clear(sf::Color::Black);

    sf::Texture stars;
    if (!stars.loadFromFile("../graphics/stars.png")) {
        cout << "Error loading background." << endl;
    }
    sf::Sprite background(stars);
    window.draw(background);

    sf::Font font;
    if (!font.loadFromFile("../graphics/8bit.ttf")) {
        cout << "Failed to load font.\n";
    }
    sf::Text text;
    text.setFont(font);
    text.setString("YOU WON");
    text.setCharacterSize(140);
    text.setFillColor(sf::Color::Green);
    text.setPosition(225, 600);
    window.draw(text);

    window.display();
}

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
    text.setPosition(225, 200);
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

bool checkCollision(Asteroid asteroid, Ship ship) {
    int asteroidRadius = asteroid.getShape().getRadius();
    int asteroidX = asteroid.getCenter().x;
    int asteroidY = asteroid.getCenter().y;
    int shipX = ship.getCenter().x;
    int shipY = ship.getCenter().y;
    return ((getDistance(asteroidX, asteroidY, shipX, shipY) - asteroidRadius) < 15); // 15 estimates center radius of ship
}

bool checkHit(Asteroid asteroid, Laser laser) {
    int asteroidRadius = asteroid.getShape().getRadius();
    int asteroidX = asteroid.getCenter().x;
    int asteroidY = asteroid.getCenter().y;
    int laserX = laser.getPosition().x;
    int laserY = laser.getPosition().y;
    return ((getDistance(asteroidX, asteroidY, laserX, laserY) - asteroidRadius) < 3); // 3 is radius of laser
}

double getDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

vector<Asteroid> createAsteroids(int x) {
    vector<Asteroid> allAsteroids;
    for (int i = 0; i < (x / 4); i++) {
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
    return allAsteroids;
}

void removeLasers(vector<Laser> &lasers) {
    lasers.clear();
}

