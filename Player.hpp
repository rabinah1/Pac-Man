#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
 public:
  Player(int points, int lives, int index, int len, std::vector<sf::Texture> textureVec, sf::Sprite playerSprite, int dir);
  int getPoints();
  int getLives();
  sf::Sprite getSprite();
  void decLives();
  void incLives();
  void incPoints();
  void changeTexture();
  void setRot(int num);
  void setPos(sf::Vector2f v1);
  sf::Vector2f getPos();
  void setDir(int d);
  int getDir();
 private:
  int points;
  int lives;
  int index;
  int len;
  std::vector<sf::Texture> textureVec;
  sf::Sprite playerSprite;
  int dir;
};

#endif
