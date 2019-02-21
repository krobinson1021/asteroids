
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

#include "asteroid.hpp"
#include "functions.hpp"
#include "laser.hpp"
#include "ship.hpp"

using namespace std;

void GameEndsLose(sf::RenderWindow &window) {

    window.clear(sf::Color::Black);

    sf::Texture starsWithFlames;
    if (!starsWithFlames.loadFromFile("../graphics/starswithflames.png")) {
        cout << "Error loading image." << endl;
        exit(EXIT_FAILURE);
    }

    sf::Sprite background(starsWithFlames);
    window.draw(background);

    sf::Font font;
    if (!font.loadFromFile("../graphics/8bit.ttf")) {
        cout << "Error loading font." << endl;
        exit(EXIT_FAILURE);
    }

    sf::Text text;
    text.setFont(font); // font is a sf::Font
    text.setString("YOU DIED");
    text.setCharacterSize(140); // in pixels, not points!
    text.setFillColor(sf::Color::Red);
    text.setPosition(240, 200);

    window.draw(text);
}

double degreesToRadians(double degrees) {
    double radians = degrees * (M_PI / 180);
    return radians;
}
