#include <Player.hpp>

Player::Player(int p, int l, int idx, int ln, std::vector<sf::Texture> texVec, sf::Sprite playerSp, int direction)
{
  points = p;
  lives = l;
  index = idx;
  len = ln;
  textureVec = texVec;
  playerSprite = playerSp;
  dir = direction;
}

int Player::getPoints()
{
  return points;
}

int Player::getLives()
{
  return lives;
}

void Player::decLives()
{
  lives = lives - 1;
}

void Player::incLives()
{
  lives = lives + 1;
}

void Player::incPoints()
{
  points = points + 1;
}

void Player::changeTexture()
{
  if (index == len)
    {
      index = 0;
    }
  playerSprite.setTexture(textureVec[index]);
  index += 1;
}

sf::Sprite Player::getSprite()
{
  return playerSprite;
}

void Player::setRot(int num)
{
  playerSprite.setRotation(num);
}

void Player::setPos(sf::Vector2f v1)
{
  playerSprite.setPosition(v1);
}

sf::Vector2f Player::getPos()
{
  return playerSprite.getPosition();
}

void Player::setDir(int d)
{
  dir = d;
}

int Player::getDir()
{
  return dir;
}
