#include <Player.hpp>

Player::Player(int p, int l, int idx, int ln, std::vector<sf::Texture> texVec, sf::Sprite playerSp, sf::IntRect rect2, int direction)
{
  points = p;
  lives = l;
  index = idx;
  len = ln;
  textureVec = texVec;
  playerSprite = playerSp;
  r2 = rect2;
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

void Player::updateRect()
{
  r2.left = playerSprite.getPosition().x-playerSprite.getGlobalBounds().width/2;
  r2.top = playerSprite.getPosition().y-playerSprite.getGlobalBounds().height/2;
}

sf::IntRect Player::getRect()
{
  return r2;
}

void Player::setDir(int d)
{
  dir = d;
}

int Player::getDir()
{
  return dir;
}
