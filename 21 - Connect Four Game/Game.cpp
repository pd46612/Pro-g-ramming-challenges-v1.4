#include "Game.h"


Game::Game() : m_context(std::make_shared<Context>())
{
	m_context->m_window->create(sf::VideoMode(200,200), "XD", sf::Style::Close);
	//add first state to m_states
}

Game::~Game()
{
}

void Game::run()
{
	while (m_context->m_window->isOpen())
	{
		sf::Event event;
		while (m_context->m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_context->m_window->close();
			}

			m_context->m_window->clear();
			//draw

			//draw
			m_context->m_window->display();
		}
	}
}
