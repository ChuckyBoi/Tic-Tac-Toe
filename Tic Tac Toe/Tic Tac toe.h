#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Tic_Tac_Toe : public sf::Drawable 
{
private:
	

	 sf::RectangleShape Tiles[3][3];
	
	 sf::RectangleShape X;
	 sf::RectangleShape O;
	 std::vector<sf::RectangleShape>x;
	 std::vector<sf::RectangleShape>o;

	 sf::Vector2f mouse;
	 sf::RectangleShape winnersLine;
	 
	 
	 
	 int numOfClicks = 0;
	 bool mousePressed = false;
	 bool occupiedTile[3][3] = { false };
	 int matrix[3][3];
	 bool gameDone = false;
	

	 bool winningPossibilitiesForO[4];
	 bool winningPossibilitiesForX[4];
	 sf::Texture x_T;
	 sf::Texture o_T;

	
	 

public:

	Tic_Tac_Toe()
	{
		
		x_T.loadFromFile("Images/X.png");
		X.setTexture(&x_T);
		o_T.loadFromFile("Images/O.png");
		O.setTexture(&o_T);
	}

	virtual void setup(sf::RenderWindow &window);
	virtual void handleEvents(const sf::Event& event, sf::RenderWindow& window);
	virtual void update(sf::Vector2f& mouse, sf::RenderWindow & window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const ;





};