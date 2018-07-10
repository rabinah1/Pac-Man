#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <Main.hpp>

int main()
{
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
		  Game(window, font);
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
  sf::Event event;
  sf::Texture pac1;
  sf::Texture pac2;
  sf::Texture pac3;
  sf::Texture pac4;
  sf::Texture pac5;
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
  mySprite.setOrigin(mySprite.getOrigin().x+mySprite.getLocalBounds().width/2, mySprite.getOrigin().y+mySprite.getLocalBounds().height/2);
  mySprite.setRotation(180);
  window.setFramerateLimit(60);

  while(window.isOpen())
    {
      if (counter == 2)
	{
	  counter = 0;
	  if (index == len)
	    {
	      index = 0;
	    }
	  mySprite.setTexture(textureVector[index]);
	  index += 1;
	}
      counter = counter + 1;
      if(control == 1)
	{
	  mySprite.setRotation(0);
	  mySprite.setPosition(sf::Vector2f(mySprite.getPosition().x+speed, mySprite.getPosition().y));
	}
      else if(control == 2)
	{
	  mySprite.setRotation(180);
	  mySprite.setPosition(sf::Vector2f(mySprite.getPosition().x-speed, mySprite.getPosition().y));
	}
      else if(control == 3)
	{
	  mySprite.setRotation(270);
	  mySprite.setPosition(sf::Vector2f(mySprite.getPosition().x, mySprite.getPosition().y-speed));
	}
      else if(control == 4)
	{
	  mySprite.setRotation(90);
	  mySprite.setPosition(sf::Vector2f(mySprite.getPosition().x, mySprite.getPosition().y+speed));
	}
      while(window.pollEvent(event))
	{
	  switch(event.type)
	    {
	    case sf::Event::KeyPressed:
	      if(event.key.code == sf::Keyboard::Escape)
		{
		  window.close();
		  break;
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
      window.draw(mySprite);
      window.display();
    }
  return 0;
}
