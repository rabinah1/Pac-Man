#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Enemy
{
public:
  Enemy(int state, sf::Sprite enemySprite, sf::Texture enemyTexture, int startPos, int direction, double startDelay);
  int getState();
  int getStartPos();
  void setStartPos(int num);
  sf::Sprite getSprite();
  void setPos(sf::Vector2f v1);
  sf::Vector2f getPos();
  void setDir(int dir);
  void setNextDir(int nextDir);
  int getDir();
  int getNextDir();
  void setInitRand(int val);
  int getInitRand();
  int getChecker();
  void setChecker(int c);
  double getStartDelay();
  int getCrossCount();
  void incCrossCount();
  int getDirCounter();
  void incDirCounter();
  void resetDirCounter();
  void initLines();
  std::vector<std::tuple<int, sf::RectangleShape>> getLines();
  void updateLines();
  int getVisibleFlag();
  void setVisibleFlag(int vf);
  float getLastPlayerCoord_x();
  void setLastPlayerCoord_x(float x_coord);
  float getLastPlayerCoord_y();
  void setLastPlayerCoord_y(float y_coord);
private:
  int state;
  sf::Sprite enemySprite;
  sf::Texture enemyTexture;
  int startPos;
  int direction;
  int nextDirection;
  int initRand;
  int checker;
  double startDelay;
  int crossCount;
  int dirCounter;
  int visible_flag;
  float last_player_coord_x;
  float last_player_coord_y;
  sf::RectangleShape line_up;
  sf::RectangleShape line_right;
  sf::RectangleShape line_down;
  sf::RectangleShape line_left;
};

#endif
