
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

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
    if (!font.loadFromFile("8bit.ttf")) {
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
    return(degrees * (M_PI / 180));
}

double radiansToDegrees(double radians) {
    return(radians *  (180 / M_PI));
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

