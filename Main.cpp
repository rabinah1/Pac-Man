#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <Main.hpp>
#include <unistd.h>
#include <Player.hpp>
#include <Functions.hpp>
#include <cstdlib>

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
  int counter = 0;
  int index = 0;
  int pause = 0;
  int currentCont = 0;
  int temp = 0;
  std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string> currPoint;
  sf::Event event;
  sf::Texture pac1;
  sf::Texture pac2;
  sf::Texture pac3;
  sf::Texture pac4;
  sf::Texture pac5;
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
  mySprite.setTexture(pac5);
  mySprite.setTexture(pac1);
  mySprite.setOrigin(mySprite.getOrigin().x+mySprite.getLocalBounds().width/2, mySprite.getOrigin().y+mySprite.getLocalBounds().height/2);
  mySprite.setRotation(0);
  mySprite.setPosition(window.getSize().x/2, window.getSize().y/2*1.5);
  Player player1(0, 3, 0, len, textureVector, mySprite, 2);
  std::vector<sf::ConvexShape> mapShapes = initMap(window);
  std::vector<std::tuple<sf::CircleShape, std::string, std::string, std::string, std::string>> turnPoints = turningPoints(window);
  
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
  window.draw(player1.getSprite());
  window.draw(readyText);
  window.display();
  sleep(3);
      
  while(window.isOpen())
    {
      sf::Vector2f spritePos = player1.getPos();
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
      
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
				  return 0;
				}
			      else if(exitButton.getGlobalBounds().contains(mousePosF))
				{
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
      window.draw(player1.getSprite());
      window.display();
    }
  return 0;
}
