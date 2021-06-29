#include "N_queens.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

N_queens::N_queens(short size)
{
	axeSize = size;
	placedQueens = 0;
	if (isSizeTooBig()) return;
	initialize();
	short col = 0;
	if (solve(col) == false)
	{
		std::cout << "Solution doesn't exist!\n";
		return;
	}
	else display();
}

N_queens::~N_queens()
{
	delete[] board;
}

void N_queens::display()
{
	sf::Texture queen;
	if (!queen.loadFromFile("src/queen.png"))
	{
		std::cout << "Error while loading texture!\n";
		return;
	}
	std::vector<sf::Sprite> sprites;

	sf::Texture boardTexture;
	switch (axeSize)
	{
	case 1:
	{
		if (!boardTexture.loadFromFile("src/1x1.png"))
		{
			std::cout << "Error while loading texture!\n";
			return;
		}
		break;
	}
	case 4:
	{
		if (!boardTexture.loadFromFile("src/4x4.png"))
		{
			std::cout << "Error while loading texture!\n";
			return;
		}
		break;
	}
	case 5:
	{
		if (!boardTexture.loadFromFile("src/5x5.png"))
		{
			std::cout << "Error while loading texture!\n";
			return;
		}
		break;
	}
	case 6:
	{
		if (!boardTexture.loadFromFile("src/6x6.png"))
		{
			std::cout << "Error while loading texture!\n";
			return;
		}
		break;
	}
	case 7:
	{
		if (!boardTexture.loadFromFile("src/7x7.png"))
		{
			std::cout << "Error while loading texture!\n";
			return;
		}
		break;
	}
	case 8:
	{
		if (!boardTexture.loadFromFile("src/8x8.png"))
		{
			std::cout << "Error while loading texture!\n";
			return;
		}
		break;
	}
	}
	sf::Sprite chessBoard(boardTexture);

	for (size_t i = 0; i < axeSize; i++)
	{
		for (size_t j = 0; j < axeSize; j++)
		{
			if (board[i * axeSize + j] == 1)
			{
				sprites.push_back(sf::Sprite(queen));
				sprites.back().setPosition(i * 115.f, j * 115.f);
			}
		}
	}

	sf::RenderWindow window(sf::VideoMode(115 * axeSize, 115 * axeSize), "N Queens Problem");
	window.setFramerateLimit(120);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
			}
		}
		window.clear(sf::Color::White);
		window.draw(chessBoard);
		for (auto& s : sprites)
		{
			window.draw(s);
		}
		window.display();
	}
}

void N_queens::initialize()
{
	board = new short[axeSize * axeSize];
	for (size_t i = 0; i < axeSize * axeSize; i++)
	{
		board[i] = 0;
	}
}

bool N_queens::isSizeTooBig()
{
	if (axeSize > 8) return true;
	else			 return false;
}

bool N_queens::solve(short col)
{
	if (col >= axeSize)
		return true;
	for (size_t i = 0; i < axeSize; i++)
	{
		if (isSafeToPlace(i, col))
		{
			board[i * axeSize + col] = 1;
			if (solve(col + 1) == true) return true;
			board[i * axeSize + col] = 0;
		}
	}
	return false;
}

bool N_queens::isSafeToPlace(size_t row, size_t col)
{
	short i;
	short j;
	for (i = 0; i < col; i++)
	{
		if (board[row * axeSize + i] == 1) return false;
	}

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i * axeSize + j] == 1) return false;
	}

	for (i = row, j = col; i < axeSize && j >= 0; i++, j--)
	{
		if (board[i * axeSize + j] == 1) return false;
	}

	return true;
}
