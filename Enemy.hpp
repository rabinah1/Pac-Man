#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy
{
public:
  Enemy(int state, sf::Sprite enemySprite, sf::Texture enemyTexture);
  int getState();
  sf::Sprite getSprite();
  void setPos(sf::Vector2f v1);
  sf::Vector2f getPos();
private:
  int state;
  sf::Sprite enemySprite;
  sf::Texture enemyTexture;
};

#endif
