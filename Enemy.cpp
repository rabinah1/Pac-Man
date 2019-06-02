#include <Enemy.hpp>

Enemy::Enemy(int st, sf::Sprite enemySp, sf::Texture eTexture, int stP, int Dir, double sDel)
{
  state = st;
  enemySprite = enemySp;
  enemyTexture = eTexture;
  startPos = stP;
  direction = Dir;
  initRand = 0;
  checker = 0;
  startDelay = sDel;
  crossCount = 0;
  dirCounter = 0;
  visible_flag = 0;
  last_player_coord_x = 0.0;
  last_player_coord_y = 0.0;
  //line_right.setSize(sf::Vector2f(2000, 5));
  //line_right.rotate(0);
  //line_down.setSize(sf::Vector2f(2000, 5));
  //line_down.rotate(90);
  //line_left.setSize(sf::Vector2f(2000, 5));
  //line_left.rotate(180);
  //line_up.setSize(sf::Vector2f(2000, 5));
  //line_up.rotate(270);
}

void Enemy::setLastPlayerCoord_y(float y_coord)
{
  last_player_coord_y = y_coord;
}

float Enemy::getLastPlayerCoord_y()
{
  return last_player_coord_y;
}

void Enemy::setLastPlayerCoord_x(float x_coord)
{
  last_player_coord_x = x_coord;
}

float Enemy::getLastPlayerCoord_x()
{
  return last_player_coord_x;
}

int Enemy::getVisibleFlag()
{
  return visible_flag;
}

void Enemy::setVisibleFlag(int vf)
{
  visible_flag = vf;
}

void Enemy::resetDirCounter()
{
  dirCounter = 0;
}

int Enemy::getDirCounter()
{
  return dirCounter;
}

void Enemy::incDirCounter()
{
  dirCounter = dirCounter + 1;
}

int Enemy::getCrossCount()
{
  return crossCount;
}

void Enemy::incCrossCount()
{
  crossCount = crossCount + 1;
}

double Enemy::getStartDelay()
{
  return startDelay;
}

int Enemy::getChecker()
{
  return checker;
}

void Enemy::setChecker(int c)
{
  checker = c;
}

void Enemy::setInitRand(int val)
{
  initRand = val;
}

int Enemy::getInitRand()
{
  return initRand;
}

int Enemy::getState()
{
  return state;
}

int Enemy::getStartPos()
{
  return startPos;
}

void Enemy::setStartPos(int num)
{
  startPos = num;
}

sf::Sprite Enemy::getSprite()
{
  return enemySprite;
}

void Enemy::setPos(sf::Vector2f v1)
{
  enemySprite.setPosition(v1);
}

sf::Vector2f Enemy::getPos()
{
  return enemySprite.getPosition();
}

void Enemy::setDir(int dir)
{
  direction = dir;
}

void Enemy::setNextDir(int nextDir)
{
  nextDirection = nextDir;
}

int Enemy::getDir()
{
  return direction;
}

int Enemy::getNextDir()
{
  return nextDirection;
}

void Enemy::initLines()
{
  line_right.setSize(sf::Vector2f(2000, 1));
  line_right.rotate(0);
  line_right.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
  line_down.setSize(sf::Vector2f(2000, 1));
  line_down.rotate(90);
  line_down.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
  line_left.setSize(sf::Vector2f(2000, 1));
  line_left.rotate(180);
  line_left.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
  line_up.setSize(sf::Vector2f(2000, 1));
  line_up.rotate(270);
  line_up.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
}

void Enemy::updateLines()
{
  line_right.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
  line_down.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
  line_left.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
  line_up.setPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
}

//std::vector<sf::RectangleShape> Enemy::getLines()
std::vector<std::tuple<int, sf::RectangleShape>> Enemy::getLines()
{
  std::vector<std::tuple<int, sf::RectangleShape>> lines;
  std::tuple<int, sf::RectangleShape> lineTuple1;
  std::tuple<int, sf::RectangleShape> lineTuple2;
  std::tuple<int, sf::RectangleShape> lineTuple3;
  std::tuple<int, sf::RectangleShape> lineTuple4;

  lineTuple1 = std::make_tuple(1, line_left);
  lineTuple2 = std::make_tuple(2, line_up);
  lineTuple3 = std::make_tuple(3, line_right);
  lineTuple4 = std::make_tuple(4, line_down);

  lines.push_back(lineTuple1);
  lines.push_back(lineTuple2);
  lines.push_back(lineTuple3);
  lines.push_back(lineTuple4);
  //lines.push_back(line_right);
  //lines.push_back(line_down);
  //lines.push_back(line_left);
  //lines.push_back(line_up);
  return lines;
}
