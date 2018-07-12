#include <Enemy.hpp>

Enemy::Enemy(int st, sf::Sprite enemySp)
{
  state = st;
  enemySprite = enemySp;
}

int Enemy::getState()
{
  return state;
}

sf::Sprite Enemy::getSprite()
{
  return enemySprite;
}
