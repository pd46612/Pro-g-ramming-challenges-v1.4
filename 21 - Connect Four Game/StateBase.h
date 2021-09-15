#pragma once

#include <SFML/Graphics.hpp>

class Game;

class StateBase
{
protected:
	Game* m_pGame;

public:
	StateBase(Game& game) : m_pGame(&game) {}
	virtual ~StateBase() {}

	virtual void handleEvent(sf::Event) {}
	virtual void handleInput() = 0;
	virtual void update(sf::Time) {}
	virtual void fixedUpdate(sf::Time) {}
	virtual void render(sf::RenderTarget& renderer) = 0;
};

