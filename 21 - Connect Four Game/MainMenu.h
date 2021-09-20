#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class MainMenu : public Engine::State
{
private:
	std::shared_ptr<Context> m_context;
	sf::Text m_gameTitle;

public:
	MainMenu(std::shared_ptr<Context>& context);
	~MainMenu();

	void initialize() override;
	void processInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;
};

