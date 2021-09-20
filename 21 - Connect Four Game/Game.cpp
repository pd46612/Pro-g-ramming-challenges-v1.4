#include "Game.h"
#include "MainMenu.h"


Game::Game() : m_context(std::make_shared<Context>())
{
	m_context->m_window->create(sf::VideoMode(800,800), "Connect 4 Game", sf::Style::Close);
	m_context->m_states->add(std::make_unique<MainMenu>(m_context));
}

Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastFrame = sf::Time::Zero;

	while (m_context->m_window->isOpen())
	{
		timeSinceLastFrame += clock.restart();
		while (timeSinceLastFrame > TIME_PER_FRAME)
		{
			timeSinceLastFrame -= TIME_PER_FRAME;

			m_context->m_states->procesStateChange();
			m_context->m_states->getCurrent()->processInput();
			m_context->m_states->getCurrent()->update(TIME_PER_FRAME);
			m_context->m_states->getCurrent()->draw();
		}
	}
}
