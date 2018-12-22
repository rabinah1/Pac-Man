#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <vector>

std::vector<sf::ConvexShape> initMap(sf::RenderWindow &window);
std::vector<sf::CircleShape> turningPoints(sf::RenderWindow &window);

#endif
