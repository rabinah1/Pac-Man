#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
#include <string>
#include <cstdio>
#include <new>

std::vector<sf::ConvexShape> initMap(sf::RenderWindow &window);
//std::vector<sf::CircleShape> turningPoints(sf::RenderWindow &window);
std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string>> turningPoints(sf::RenderWindow &window);
int ** createAdjacency();

#endif
