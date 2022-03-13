#include "Tic Tac toe.h"

void Tic_Tac_Toe::setup(sf::RenderWindow &window)
{

	

	int posX = 0, posY = 0;
	sf::Vector2f size;
	
		size.x = window.getSize().x / 3;
		size.y = window.getSize().y / 3;

		X.setSize(sf::Vector2f(sf::Vector2f(size.x, size.y)));
		O.setSize(sf::Vector2f(sf::Vector2f(size.x, size.y)));

		winnersLine.setFillColor(sf::Color::Blue);
		winnersLine.setOutlineColor(sf::Color::Black);
		winnersLine.setOutlineThickness(5);


		for (int i = 0; i < 3; i++)
		{
			posX = 0;
			for (int j = 0; j < 3; j++)
			{

				Tiles[i][j].setSize(sf::Vector2f(size.x, size.y));
				Tiles[i][j].setFillColor(sf::Color::Black);
				Tiles[i][j].setOutlineThickness(5);
				Tiles[i][j].setOutlineColor(sf::Color::Red);
				Tiles[i][j].setPosition(posX, posY);

				posX += size.x;
			}
			posY += size.y;
		}
	
	




	
}

void Tic_Tac_Toe::handleEvents(const sf::Event& event, sf::RenderWindow& window)
{
	sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{

		if (!gameDone) {
			if (!mousePressed)
			{
				update(mouse,window);
				mousePressed = true;
			}
		}
	}
	else {
		mousePressed = false;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		
			x.clear();
			o.clear();
			gameDone = false;
			numOfClicks = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					occupiedTile[i][j] = false;
					matrix[i][j] = 0;
				}
			}
			for (int n = 0; n < 4; n++)
			{
				winningPossibilitiesForO[n] = true;
				winningPossibilitiesForX[n] = true;
			}
		
	}
}
void Tic_Tac_Toe::update(sf::Vector2f &mouse,sf::RenderWindow &window)
{
	

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{

				if (mouse.x < Tiles[i][j + 1].getPosition().x &&
					mouse.x > Tiles[i][j].getPosition().x &&
					mouse.y > Tiles[i][j].getPosition().y &&
					mouse.y < Tiles[i + 1][j].getPosition().y)
				{
					if (!occupiedTile[i][j])
					{
						numOfClicks++;
						occupiedTile[i][j] = true;

						if (numOfClicks % 2 != 0) {

							X.setPosition(sf::Vector2f(Tiles[i][j].getPosition().x - 10 ,Tiles[i][j].getPosition().y));
							matrix[i][j] = 1;
							x.push_back(sf::RectangleShape(X));
						}
						else
						{

							O.setPosition(sf::Vector2f(Tiles[i][j].getPosition()));
							matrix[i][j] = 2;
							o.push_back(sf::RectangleShape(O));

						}
					}
				}

				if (i == 2)
				{
					if (mouse.x < Tiles[i][j + 1].getPosition().x &&
						mouse.x > Tiles[i][j].getPosition().x &&
						mouse.y > Tiles[i][j].getPosition().y &&
						mouse.y < window.getSize().y)
					{
						if (!occupiedTile[i][j])
						{
							numOfClicks++;
							occupiedTile[i][j] = true;

							if (numOfClicks % 2 != 0) {


								X.setPosition(sf::Vector2f(Tiles[i][j].getPosition()));
								matrix[i][j] = 1;
								x.push_back(sf::RectangleShape(X));

							}
							else
							{

								O.setPosition(sf::Vector2f(Tiles[i][j].getPosition()));
								matrix[i][j] = 2;
								o.push_back(sf::RectangleShape(O));

							}
						}
					}

				}
				if (j == 2)
				{
					if (mouse.x < window.getSize().x &&
						mouse.x > Tiles[i][j].getPosition().x &&
						mouse.y > Tiles[i][j].getPosition().y &&
						mouse.y < Tiles[i + 1][j].getPosition().y)
					{
						if (!occupiedTile[i][j])
						{
							numOfClicks++;
							occupiedTile[i][j] = true;

							if (numOfClicks % 2 != 0) {


								X.setPosition(sf::Vector2f(Tiles[i][j].getPosition()));
								matrix[i][j] = 1;
								x.push_back(sf::RectangleShape(X));

							}
							else
							{

								O.setPosition(sf::Vector2f(Tiles[i][j].getPosition()));
								matrix[i][j] = 2;
								o.push_back(sf::RectangleShape(O));

							}
						}
					}
				}
				if (i == 2 && j == 2)
				{
					if (mouse.x < window.getSize().x &&
						mouse.x > Tiles[i][j].getPosition().x &&
						mouse.y > Tiles[i][j].getPosition().y &&
						mouse.y < window.getSize().y)
					{
						if (!occupiedTile[i][j])
						{
							numOfClicks++;
							occupiedTile[i][j] = true;

							if (numOfClicks % 2 != 0) {


								X.setPosition(sf::Vector2f(Tiles[i][j].getPosition()));
								matrix[i][j] = 1;
								x.push_back(sf::RectangleShape(X));

							}
							else
							{

								O.setPosition(sf::Vector2f(Tiles[i][j].getPosition()));
								matrix[i][j] = 2;
								o.push_back(sf::RectangleShape(O));

							}
						}

					}
				}

			}
		}

//Find the WINNER
	int numFor0 = 2;
	int numForX = 2;

		for (int i = 0; i < 3; i++)
		{
			numFor0 = 2;
			numForX = 2;
			for (int n = 0; n < 4; n++)
			{
				winningPossibilitiesForO[n] = true;
				winningPossibilitiesForX[n] = true;
			}
			for (int j = 0; j < 3; j++)
			{

				if (matrix[i][j] != 2)
				{
					winningPossibilitiesForO[0] = false;
				}
				if (matrix[j][i] != 2)
				{
					winningPossibilitiesForO[1] = false;
				}
				if (matrix[j][j] != 2)
				{
					winningPossibilitiesForO[2] = false;
				}
				if (matrix[j][numFor0--] != 2)
				{
					winningPossibilitiesForO[3] = false;
				}

				//////////////////////////////////////////////////////////////////////////////////////////////////////
				if (matrix[i][j] != 1)
				{
					winningPossibilitiesForX[0] = false;
				}
				if (matrix[j][i] != 1)
				{
					winningPossibilitiesForX[1] = false;
				}

				if (matrix[j][j] != 1)
				{
					winningPossibilitiesForX[2] = false;
				}
				if (matrix[j][numForX--] != 1)
				{
					winningPossibilitiesForX[3] = false;

				}
			}
			for (int n = 0; n < 4; n++)
			{
				if (winningPossibilitiesForO[n] || winningPossibilitiesForX[n])
				{
					gameDone = true;

					if (n == 0)
					{
						winnersLine.setSize(sf::Vector2f(950, 25));
						winnersLine.setRotation(0);
						winnersLine.setPosition(sf::Vector2f(Tiles[i][0].getPosition().x / 2 + Tiles[i][0].getSize().x / 2 - winnersLine.getSize().y, Tiles[i][0].getPosition().y + Tiles[i][0].getSize().y / 2 - winnersLine.getSize().y/2));
					}
					if (n == 1)
					{
						winnersLine.setSize(sf::Vector2f(500, 25));
						winnersLine.setRotation(90);
						winnersLine.setPosition(sf::Vector2f(Tiles[0][i].getPosition().x + Tiles[0][i].getSize().x / 2, Tiles[0][i].getPosition().y + Tiles[0][i].getSize().y / 2));
					}
					if (n == 2)
					{
						winnersLine.setSize(sf::Vector2f(1100, 25));
						winnersLine.setRotation(29);

						winnersLine.setPosition(sf::Vector2f(Tiles[0][0].getPosition().x + Tiles[0][0].getSize().x / 2, Tiles[0][0].getPosition().y + Tiles[0][0].getSize().y / 2));
					}
					if (n == 3)
					{

						winnersLine.setSize(sf::Vector2f(1100, 25));
						winnersLine.setRotation(151);
						winnersLine.setPosition(sf::Vector2f(Tiles[0][2].getPosition().x + Tiles[0][2].getSize().x / 2, Tiles[0][0].getPosition().y + Tiles[0][0].getSize().y / 2));

					}
				}
			}
		}
}	
void Tic_Tac_Toe::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				target.draw(Tiles[i][j]);


			}
		}
		for (size_t i = 0; i < x.size(); i++)
		{
			target.draw(x[i]);
		}
		for (size_t i = 0; i < o.size(); i++)
		{
			target.draw(o[i]);
		}

		if (gameDone) 
		{
			target.draw(winnersLine);

		}
}

	
	




