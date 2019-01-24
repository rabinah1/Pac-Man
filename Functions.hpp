#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <tuple>
#include <string>
#include <cstdio>
#include <new>
#include <stdio.h>
#include <limits.h>

std::vector<sf::ConvexShape> initMap(sf::RenderWindow &window);
std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>> turningPoints(sf::RenderWindow &window);
int ** createAdjacency();
int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[], int n);
void dijkstra(int **graph, int src);

#endif
