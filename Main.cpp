#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Main.hpp>
#include <unistd.h>
#include <Player.hpp>
#include <Functions.hpp>

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
  int speed = 4;
  int counter = 0;
  int index = 0;
  int pause = 0;
  int currentCont = 0;
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
  
  window.setFramerateLimit(60);
  window.clear(sf::Color::Black);
  window.draw(readyText);
  for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
    {
      window.draw(*it);
    }
  window.draw(player1.getSprite());
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
	  player1.changeTexture();
	}
      counter = counter + 1;
      if(control == 1)
	{
	  player1.setDir(1);
	  player1.setRot(0);
	  player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x+speed, player1.getSprite().getPosition().y));
	}
      else if(control == 2)
	{
	  player1.setDir(2);
	  player1.setRot(180);
	  player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x-speed, player1.getSprite().getPosition().y));
	}
      else if(control == 3)
	{
	  player1.setDir(3);
	  player1.setRot(270);
	  player1.setPos(sf::Vector2f(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y-speed));
	}
      else if(control == 4)
	{
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
		  control = 3;
		}
	      else if(event.key.code == sf::Keyboard::Down)
		{
		  control = 4;
		}
	      else if(event.key.code == sf::Keyboard::Left)
		{
		  control = 2;
		}
	      else if(event.key.code == sf::Keyboard::Right)
		{
		  control = 1;
		}
	    }
	}
      window.clear(sf::Color::Black);
      for (auto it = mapShapes.begin(); it != mapShapes.end(); it++)
	{
	  window.draw(*it);
	}
      window.draw(player1.getSprite());
      window.display();
    }
  return 0;
}
