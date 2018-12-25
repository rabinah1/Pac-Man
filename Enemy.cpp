#include <Enemy.hpp>

Enemy::Enemy(int st, sf::Sprite enemySp, sf::Texture eTexture)
{
  state = st;
  enemySprite = enemySp;
  enemyTexture = eTexture;
}

int Enemy::getState()
{
  return state;
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
