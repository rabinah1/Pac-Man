#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <Main.hpp>
#include <unistd.h>
#include <Player.hpp>
#include <Enemy.hpp>
#include <Functions.hpp>
#include <cstdlib>
#include <time.h>
#include <chrono>

int main()
{
  int retValue = 0;
  sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pac-Man", sf::Style::Fullscreen);
  sf::Event event;
  sf::Font font;
  font.loadFromFile("Ubuntu-B.ttf");
  sf::Text StartButton("Start Game", font, 100);
  sf::Text ExitButton("Exit", font, 100);
  sf::Text TitleText("Pac-Man", font, 200);
  StartButton.setFillColor(sf::Color::Black);
  ExitButton.setFillColor(sf::Color::Black);
  TitleText.setFillColor(sf::Color::Red);
  StartButton.setPosition(window.getSize().x/2-StartButton.getLocalBounds().width/2, window.getSize().y-StartButton.getLocalBounds().height*5);
  ExitButton.setPosition(window.getSize().x/2-ExitButton.getLocalBounds().width/2, window.getSize().y-ExitButton.getLocalBounds().height*2);
  TitleText.setPosition(window.getSize().x/2-TitleText.getLocalBounds().width/2, window.getSize().y-TitleText.getLocalBounds().height*7);
  
  window.setFramerateLimit(60);

  while(window.isOpen())
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
      if (StartButton.getGlobalBounds().contains(mousePosF))
	{
	  StartButton.setFillColor(sf::Color::Blue);
	}
      else if (ExitButton.getGlobalBounds().contains(mousePosF))
	{
	  ExitButton.setFillColor(sf::Color::Blue);
	}
      else
	{
	  ExitButton.setFillColor(sf::Color::Black);
	  StartButton.setFillColor(sf::Color::Black);
	}
 
      while(window.pollEvent(event))
	{
	  switch(event.type)
	    {
	    case sf::Event::MouseButtonPressed:
	      if (StartButton.getGlobalBounds().contains(mousePosF))
		{
		  retValue = Game(window, font);
		  if(retValue == 1)
		    {
		      window.close();
		      break;
		    }
		}
	      else if (ExitButton.getGlobalBounds().contains(mousePosF))
		{
		  window.close();
		  break;
		}
	    }
	}
      window.clear(sf::Color::White);
      window.draw(StartButton);
      window.draw(ExitButton);
      window.draw(TitleText);
      window.display();
    }
  return 0;
}


int Game(sf::RenderWindow &window, sf::Font font)
{
  int control = 1;
  std::string setControl = "Right";
  int speed = 4;
  int enemySpeed = 4;
  int counter = 0;
  int index = 0;
  int pause = 0;
  int currentCont = 0;
  int temp = 0;
  int sizeX = window.getSize().x;
  int sizeY = window.getSize().y;
  int randDir = 0;
  int checker = 0;
  int loop_check = 0;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int> currPoint;
  sf::Event event;
  sf::Texture pac1;
  sf::Texture pac2;
  sf::Texture pac3;
  sf::Texture pac4;
  sf::Texture pac5;
  sf::Texture E1;
  sf::Texture E2;
  sf::Texture E3;
  sf::Texture E4;
  sf::Text readyText("Get ready!", font, 80);
  sf::Text menuButton("Menu", font, 80);
  sf::Text exitButton("Exit", font, 80);
  
  readyText.setFillColor(sf::Color::White);
  menuButton.setFillColor(sf::Color::White);
  exitButton.setFillColor(sf::Color::White);
  readyText.setPosition(window.getSize().x/2-readyText.getLocalBounds().width/2, window.getSize().y-readyText.getLocalBounds().height*10);
  menuButton.setPosition(window.getSize().x/2-menuButton.getLocalBounds().width/2, window.getSize().y-menuButton.getLocalBounds().height*6);
  exitButton.setPosition(window.getSize().x/2-exitButton.getLocalBounds().width/2, window.getSize().y-exitButton.getLocalBounds().height*3);
  pac1.loadFromFile("Pac1.png");
  pac2.loadFromFile("Pac2.png");
  pac3.loadFromFile("Pac3.png");
  pac4.loadFromFile("Pac4.png");
  pac5.loadFromFile("Pac5.png");
  E1.loadFromFile("Enemy1.png");
  E2.loadFromFile("Enemy2.png");
  E3.loadFromFile("Enemy3.png");
  E4.loadFromFile("Enemy4.png");
  E1.setSmooth(true);
  E2.setSmooth(true);
  E3.setSmooth(true);
  E4.setSmooth(true);
  pac1.setSmooth(true);
  pac2.setSmooth(true);
  pac3.setSmooth(true);
  pac4.setSmooth(true);
  pac5.setSmooth(true);
  std::vector<sf::Texture> textureVector;
  textureVector.push_back(pac1);
  textureVector.push_back(pac2);
  textureVector.push_back(pac3);
  textureVector.push_back(pac4);
  textureVector.push_back(pac5);
  textureVector.push_back(pac4);
  textureVector.push_back(pac3);
  textureVector.push_back(pac2);
  textureVector.push_back(pac1);
  int len = textureVector.size();

  sf::Sprite mySprite;
  sf::Sprite Enemy1;
  sf::Sprite Enemy2;
  sf::Sprite Enemy3;
  sf::Sprite Enemy4;
  
  Enemy1.setTexture(E1);
  Enemy1.setOrigin(Enemy1.getOrigin().x+Enemy1.getLocalBounds().width/2, Enemy1.getOrigin().y+Enemy1.getLocalBounds().height/2);
  Enemy1.setRotation(0);
  Enemy1.setPosition(window.getSize().x/2*0.86, window.getSize().y/2*0.95);

  Enemy2.setTexture(E2);
  Enemy2.setOrigin(Enemy2.getOrigin().x+Enemy2.getLocalBounds().width/2, Enemy2.getOrigin().y+Enemy2.getLocalBounds().height/2);
  Enemy2.setRotation(0);
  Enemy2.setPosition(window.getSize().x/2*0.95, window.getSize().y/2*0.95);

  Enemy3.setTexture(E3);
  Enemy3.setOrigin(Enemy3.getOrigin().x+Enemy3.getLocalBounds().width/2, Enemy3.getOrigin().y+Enemy3.getLocalBounds().height/2);
  Enemy3.setRotation(0);
  Enemy3.setPosition(window.getSize().x/2*1.04, window.getSize().y/2*0.95);

  Enemy4.setTexture(E4);
  Enemy4.setOrigin(Enemy4.getOrigin().x+Enemy4.getLocalBounds().width/2, Enemy4.getOrigin().y+Enemy4.getLocalBounds().height/2);
  Enemy4.setRotation(0);
  Enemy4.setPosition(window.getSize().x/2*1.13, window.getSize().y/2*0.95);
  
  mySprite.setTexture(pac5);
  mySprite.setTexture(pac1);
  mySprite.setOrigin(mySprite.getOrigin().x+mySprite.getLocalBounds().width/2, mySprite.getOrigin().y+mySprite.getLocalBounds().height/2);
  mySprite.setRotation(0);
  mySprite.setPosition(window.getSize().x/2, window.getSize().y/2*1.5);
  
  Player player1(0, 3, 0, len, textureVector, mySprite, 2);
  Enemy enemy1(1, Enemy1, E1, 0, 0, 0);
  Enemy enemy2(1, Enemy2, E2, 0, 0, 2);
  Enemy enemy3(1, Enemy3, E3, 0, 0, 4);
  Enemy enemy4(1, Enemy4, E4, 0, 0, 6);
  std::vector<sf::ConvexShape> mapShapes = initMap(window);
  std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string, int>> turnPoints = turningPoints(window);
  std::vector<Enemy> enemyList;
  enemyList.push_back(enemy1);
  enemyList.push_back(enemy2);
  enemyList.push_back(enemy3);
  enemyList.push_back(enemy4);
  int **AdjMat = createAdjacency();
  //dijkstra(AdjMat, 0);
  
  window.setFramerateLimit(60);
  window.clear(sf::Color::Black);
  for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
    {
      window.draw(*it);
    }
  for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
    {
      window.draw(std::get<0>(*it));
    }
  window.draw(enemy1.getSprite());
  window.draw(enemy2.getSprite());
  window.draw(enemy3.getSprite());
  window.draw(enemy4.getSprite());
  window.draw(player1.getSprite());
  window.draw(readyText);
  window.display();
  sleep(3);
  std::chrono::steady_clock sc;
  auto start = sc.now();
  auto current = sc.now();
      
  while(window.isOpen())
    {
      current = sc.now();
      sf::Vector2f spritePos = player1.getPos();
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

      loop_check = 0;

      for (auto it = enemyList.begin(); it != enemyList.end(); it++)
	{
	  if (it->getDirCounter() <= 4)
	    {
	      it->incDirCounter();
	    }
	}
      
      for (auto it = enemyList.begin(); it != enemyList.end(); it++)
	{
	  if (static_cast<std::chrono::duration<double>>(current-start).count() < it->getStartDelay())
	    {
	      continue;
	    }
	  if (loop_check <= 1) // The first two enemies
	    {
	      if (it->getPos().x <= sizeX*0.5 && it->getStartPos() == 0)
		{
		  it->setPos(sf::Vector2f((*it).getPos().x+enemySpeed, it->getPos().y));
		}
	      else if (it->getStartPos() == 0)
		{
		  if (it->getPos().y >= sizeY/2*0.77)
		    {
		      it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y-enemySpeed));
		    }
		  else
		    {
		      it->setStartPos(1);
		      it->setInitRand(rand() % 2);
		    }
		}
	    }
	  else // The last two enemies
	    {
	      if(it->getPos().x >= sizeX*0.5 && it->getStartPos() == 0)
		{
		  it->setPos(sf::Vector2f((*it).getPos().x-enemySpeed, it->getPos().y));
		}
	      else if (it->getStartPos() == 0)
		{
		  if (it->getPos().y >= sizeY/2*0.77)
		    {
		      it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y-enemySpeed));
		    }
		  else
		    {
		      it->setStartPos(1);
		      it->setInitRand(rand() % 2);
		    }
		}
	    }
	  loop_check++;
	}

      for (auto it = enemyList.begin(); it != enemyList.end(); it++)
	{
	  if (it->getStartPos() == 1 && it->getChecker() == 0)
	    {
	      it->setChecker(1);
	      if (it->getInitRand() == 0)
		{
		  it->setDir(1);
		}
	      else
		{
		  it->setDir(2);
		}
	    }
	}

      for (auto it = enemyList.begin(); it != enemyList.end(); it++)
	{
	  if (it->getDir() == 1) // left
	    {
	      it->setPos(sf::Vector2f(it->getPos().x - enemySpeed, it->getPos().y));
	    }
	  else if ((*it).getDir() == 2) // right
	    {
	      it->setPos(sf::Vector2f(it->getPos().x + enemySpeed, it->getPos().y));
	    }
	  else if (it->getDir() == 3) // up
	    {
	      it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y - enemySpeed));
	    }
	  else if ((*it).getDir() == 4) // down
	    {
	      it->setPos(sf::Vector2f(it->getPos().x, it->getPos().y + enemySpeed));
	    }
	}
      
      if (counter == 2)
	{
	  counter = 0;
	  if (temp == 0)
	    {
	      player1.changeTexture();
	    }
	}
      counter = counter + 1;
      for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
	{
	  if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 && abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && ((std::get<1>(*it) != "Left" && control == 2) || (std::get<2>(*it) != "Right" && control == 1) || (std::get<3>(*it) != "Up" && control == 3) || (std::get<4>(*it) != "Down" && control == 4)))
	    {
	      temp = 1;
	      speed = 0;
	      currPoint = *it;
	      break;
	    }
	}

      for (auto enemy_it = enemyList.begin(); enemy_it != enemyList.end(); enemy_it++)
	{
	  for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
	    {
	      if (abs(std::get<0>(*it).getPosition().x - enemy_it->getPos().x) <= 4 && abs(std::get<0>(*it).getPosition().y - enemy_it->getPos().y) <= 4 && enemy_it->getDirCounter() > 3)
		{
		  enemy_it->resetDirCounter();
		  enemy_it->incCrossCount();
		  std::vector<int> dirVector;
		  if (std::get<1>(*it) == "Left")
		    {
		      dirVector.push_back(1);
		    }
		  if (std::get<2>(*it) == "Right")
		    {
		      dirVector.push_back(2);
		    }
		  if (std::get<3>(*it) == "Up")
		    {
		      dirVector.push_back(3);
		    }
		  if (std::get<4>(*it) == "Down")
		    {
		      dirVector.push_back(4);
		    }
		  int vSize = dirVector.size();
		  srand(time(0) + enemy_it->getCrossCount());
		  randDir = rand() % vSize;
		  enemy_it->setDir(dirVector.at(randDir));
		}
	    }
	}
      if (setControl == "Right")
	{
	  if (control == 2)
	    {
	      control = 1;
	    }
	  else
	    {
	      for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
		{
		  if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 && abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<2>(*it) == "Right")
		    {
		      control = 1;
		      break;
		    }
		}
	    }
	}
      else if (setControl == "Left")
	{
	  if (control == 1)
	    {
	      control = 2;
	    }
	  else
	    {
	      for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
		{
		  if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 && abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<1>(*it) == "Left")
		    {
		      control = 2;
		      break;
		    }
		}
	    }
	}
      else if (setControl == "Up")
	{
	  if (control == 4)
	    {
	      control = 3;
	    }
	  else
	    {
	      for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
		{
		  if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 && abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<3>(*it) == "Up")
		    {
		      control = 3;
		      break;
		    }
		}
	    }
	}
      else if (setControl == "Down")
	{
	  if (control == 3)
	    {
	      control = 4;
	    }
	  else
	    {
	      for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
		{
		  if (abs(std::get<0>(*it).getPosition().x - player1.getPos().x) <= 2 && abs(std::get<0>(*it).getPosition().y - player1.getPos().y) <= 2 && std::get<4>(*it) == "Down")
		    {
		      control = 4;
		      break;
		    }
		}
	    }
	}
      if(control == 1) // Right
	{
	  if (temp == 0)
	    {
	      speed = 4;
	    }
	  else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") || (std::get<2>(currPoint) == "Right" && setControl == "Right") || (std::get<3>(currPoint) == "Up" && setControl == "Up") || (std::get<4>(currPoint) == "Down" && setControl == "Down"))
	    {
	      temp = 0;
	      speed = 4;
	    }
	  player1.setDir(1);
	  player1.setRot(0);
	  player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x+speed, player1.getSprite().getPosition().y));
	}
      else if(control == 2) // Left
	{
	  if (temp == 0)
	    {
	      speed = 4;
	    }
	  else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") || (std::get<2>(currPoint) == "Right" && setControl == "Right") || (std::get<3>(currPoint) == "Up" && setControl == "Up") || (std::get<4>(currPoint) == "Down" && setControl == "Down"))
	    {
	      temp = 0;
	      speed = 4;
	    }
	  player1.setDir(2);
	  player1.setRot(180);
	  player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x-speed, player1.getSprite().getPosition().y));
	}
      else if(control == 3) // Up
	{
	  if (temp == 0)
	    {
	      speed = 4;
	    }
	  else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") || (std::get<2>(currPoint) == "Right" && setControl == "Right") || (std::get<3>(currPoint) == "Up" && setControl == "Up") || (std::get<4>(currPoint) == "Down" && setControl == "Down"))
	    {
	      temp = 0;
	      speed = 4;
	    }
	  player1.setDir(3);
	  player1.setRot(270);
	  player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y-speed));
	}
      else if(control == 4) // Down
	{
	  if (temp == 0)
	    {
	      speed = 4;
	    }
	  else if ((std::get<1>(currPoint) == "Left" && setControl == "Left") || (std::get<2>(currPoint) == "Right" && setControl == "Right") || (std::get<3>(currPoint) == "Up" && setControl == "Up") || (std::get<4>(currPoint) == "Down" && setControl == "Down"))
	    {
	      temp = 0;
	      speed = 4;
	    }
	  player1.setDir(4);
	  player1.setRot(90);
	  player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y+speed));
	}
      while(window.pollEvent(event))
	{
	  switch(event.type)
	    {
	    case sf::Event::KeyPressed:
	      if(event.key.code == sf::Keyboard::Escape)
		{
		  while(1)
		    {
		      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		      if(menuButton.getGlobalBounds().contains(mousePosF))
			{
			  menuButton.setFillColor(sf::Color::Blue);
			}
		      else if(exitButton.getGlobalBounds().contains(mousePosF))
			{
			  exitButton.setFillColor(sf::Color::Blue);
			}
		      else
			{
			  menuButton.setFillColor(sf::Color::White);
			  exitButton.setFillColor(sf::Color::White);
			}
		      while(window.pollEvent(event))
			{
			  switch(event.type)
			    {
			    case sf::Event::KeyPressed:
			      if(event.key.code == sf::Keyboard::Escape)
				{
				  pause = 1;
				  break;
				}
			    case sf::Event::MouseButtonPressed:
			      if(menuButton.getGlobalBounds().contains(mousePosF))
				{
				  for (int h = 0; h < 72; h++)
				    {
				      delete [] AdjMat[h];
				    }
				  delete [] AdjMat;
				  AdjMat = 0;
				  return 0;
				}
			      else if(exitButton.getGlobalBounds().contains(mousePosF))
				{
				  for (int h = 0; h < 72; h++)
				    {
				      delete [] AdjMat[h];
				    }
				  delete [] AdjMat;
				  AdjMat = 0;
				  return 1;
				}
			    }
			}
		      window.clear(sf::Color::Black);
		      for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
			{
			  window.draw(*it);
			}
		      for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
			{
			  window.draw(std::get<0>(*it));
			}
		      for (auto it = enemyList.begin(); it != enemyList.end(); it++)
			{
			  window.draw(it->getSprite());
			}
		      window.draw(player1.getSprite());
		      window.draw(menuButton);
		      window.draw(exitButton);
		      window.display();
		      if (pause == 1)
			{
			  pause = 0;
			  break;
			}
		    }
		}
	      else if(event.key.code == sf::Keyboard::Up)
		{
		  setControl = "Up";
		}
	      else if(event.key.code == sf::Keyboard::Down)
		{
		  setControl = "Down";
		}
	      else if(event.key.code == sf::Keyboard::Left)
		{
		  setControl = "Left";
		}
	      else if(event.key.code == sf::Keyboard::Right)
		{
		  setControl = "Right";
		}
	    }
	}
      window.clear(sf::Color::Black);
      for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
	{
	  window.draw(*it);
	}
      for (auto it = turnPoints.begin(); it != turnPoints.end(); it++)
	{
	  window.draw(std::get<0>(*it));
	}
      for (auto it = enemyList.begin(); it != enemyList.end(); it++)
	{
	  window.draw(it->getSprite());
	}
      window.draw(player1.getSprite());
      window.display();
    }
  return 0;
}
