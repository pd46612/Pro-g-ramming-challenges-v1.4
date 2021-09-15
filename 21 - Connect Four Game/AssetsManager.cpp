#include "AssetsManager.h"

Engine::AssetsManager::AssetsManager()
{
}

Engine::AssetsManager::~AssetsManager()
{
}

void Engine::AssetsManager::addTexture(int id, const std::string& filePath, bool isRepeated)
{
	auto texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(filePath))
	{
		texture->setRepeated(isRepeated);
		m_textures[id] = std::move(texture);
	}
}

void Engine::AssetsManager::addFont(int id, const std::string& filePath)
{
	auto font = std::make_unique<sf::Font>();
	if (!font->loadFromFile(filePath))
	{
		m_fonts[id] = std::move(font);
	}
}

const sf::Texture& Engine::AssetsManager::getTexture(int id) const
{
	return *(m_textures.at(id).get());
}

const sf::Font& Engine::AssetsManager::getFont(int id) const
{
	return *(m_fonts.at(id).get());
}
