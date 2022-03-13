#include <SFML/Graphics.hpp>
#include "Tic Tac toe.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 766), "Tic Tac Toe");
	
	Tic_Tac_Toe game;
	game.setup(window);

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			
		}
		game.handleEvents(event, window);
		

		window.clear();
		
		window.draw(game);
		window.display();
	}

	return 0;
}