#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1800, 1000), "Pac-Man", sf::Style::Default);
  sf::Event event;
  window.setFramerateLimit(60);

  while(window.isOpen())
    {
      while(window.pollEvent(event))
	{
	  switch(event.type)
	    {
	    case sf::Event::Closed:
	      window.close();
	      break;
	    }
	}
      window.clear(sf::Color::White);
      window.display();
    }
  return 0;
}
