#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy
{
public:
  Enemy(int state, sf::Sprite enemySprite);
  int getState();
  sf::Sprite getSprite();
private:
  int state;
  sf::Sprite enemySprite;
};

#endif
