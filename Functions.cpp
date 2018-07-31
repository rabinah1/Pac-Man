#include <Functions.hpp>

std::vector<sf::ConvexShape> initMap(sf::RenderWindow &window)
{
  std::vector<sf::ConvexShape> mapShapes;
  int sizeX = window.getSize().x;
  int sizeY = window.getSize().y;
  
  sf::ConvexShape conv1;
  sf::ConvexShape conv2;
  
  conv1.setPointCount(8);
  conv1.setPoint(0, sf::Vector2f(0, 0));
  conv1.setPoint(1, sf::Vector2f(0+20, 0));
  conv1.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv1.setPoint(3, sf::Vector2f(0+120, 0-100));
  conv1.setPoint(4, sf::Vector2f(0+120, 0-120));
  conv1.setPoint(5, sf::Vector2f(0-100, 0-120));
  conv1.setPoint(6, sf::Vector2f(0-100, 0-100));
  conv1.setPoint(7, sf::Vector2f(0, 0-100));
  conv1.setOutlineColor(sf::Color::Blue);
  conv1.setFillColor(sf::Color::Black);
  conv1.setOutlineThickness(4);
  conv1.setPosition(sizeX*0.495, sizeY*0.90);

  conv2.setPointCount(8);
  conv2.setPoint(0, sf::Vector2f(0, 0));
  conv2.setPoint(1, sf::Vector2f(0+20, 0));
  conv2.setPoint(2, sf::Vector2f(0+20, 0-100));
  conv2.setPoint(3, sf::Vector2f(0+120, 0-100));
  conv2.setPoint(4, sf::Vector2f(0+120, 0-120));
  conv2.setPoint(5, sf::Vector2f(0-100, 0-120));
  conv2.setPoint(6, sf::Vector2f(0-100, 0-100));
  conv2.setPoint(7, sf::Vector2f(0, 0-100));
  conv2.setOutlineColor(sf::Color::Blue);
  conv2.setFillColor(sf::Color::Black);
  conv2.setOutlineThickness(4);
  conv2.setPosition(sizeX*0.495, sizeY*0.71);
  
  mapShapes.push_back(conv1);
  mapShapes.push_back(conv2);
  return mapShapes;
}
