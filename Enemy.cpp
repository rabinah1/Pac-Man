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

int Enemy::getDir()
{
  return direction;
}
