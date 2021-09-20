#include "MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<Context>& context) : m_context(context)
{

}

MainMenu::~MainMenu()
{
}

void MainMenu::initialize()
{
	m_context->m_assets->addFont(MAIN_FONT, "C:\\Users\\hydra\\source\\repos\\Programming Challenges v1.4\\21 - Connect Four Game\\textures\\fonts\\pixel_04.TTF");
	m_gameTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_gameTitle.setString("Connect 4 Game by pelson");
	m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
					      m_gameTitle.getLocalBounds().height / 2);
	m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
							m_context->m_window->getSize().y / 2);
}
void MainMenu::processInput()
{
	sf::Event event;
	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_context->m_window->close();
		}
	}
}
void MainMenu::update(sf::Time deltaTime)
{

}
void MainMenu::draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(m_gameTitle);
	m_context->m_window->display();
}