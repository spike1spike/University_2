#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode({ 500, 500 }), "Grid 10x10");

	const int cellSize = 50;
	const int gridSize = 10;

	sf::RectangleShape cells[gridSize][gridSize];

	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			cells[i][j].setSize(sf::Vector2f(cellSize - 2, cellSize - 2));
			cells[i][j].setPosition(i * cellSize, j * cellSize);

			if (i + j < gridSize - 1)
			{
				cells[i][j].setFillColor(sf::Color::Green);
			}
			else
			{
				cells[i][j].setFillColor(sf::Color::White);
			}

			cells[i][j].setOutlineColor(sf::Color::Black);
			cells[i][j].setOutlineThickness(1);
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		for (int i = 0; i < gridSize; ++i)
		{
			for (int j = 0; j < gridSize; ++j)
			{
				window.draw(cells[i][j]);
			}
		}
		window.display();
	}

	return 0;
}