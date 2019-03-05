#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy
{
public:
  Enemy(int state, sf::Sprite enemySprite, sf::Texture enemyTexture, int startPos, int direction);
  int getState();
  int getStartPos();
  void setStartPos(int num);
  sf::Sprite getSprite();
  void setPos(sf::Vector2f v1);
  sf::Vector2f getPos();
  void setDir(int dir);
  int getDir();
  void setInitRand(int val);
  int getInitRand();
  int getChecker();
  void setChecker(int c);
private:
  int state;
  sf::Sprite enemySprite;
  sf::Texture enemyTexture;
  int startPos;
  int direction;
  int initRand;
  int checker;
};

#endif
