#include "HUDSystem.h"

HUDSystem::HUDSystem(sf::RenderWindow & windowIn) : window(windowIn), currentNodeNumber(-1)
{
	m_font.loadFromFile("resources\\fonts\\akashi.ttf");
	m_nodeText.setPosition(sf::Vector2f(15, 15));
	m_currentLapText.setPosition(sf::Vector2f(15, 55));
	m_lastLapText.setPosition(sf::Vector2f(15, 95));
	setGenericTextProperties(m_nodeText);
	setGenericTextProperties(m_currentLapText);
	setGenericTextProperties(m_lastLapText);
}

void HUDSystem::configure(entityx::EventManager & events)
{
	events.subscribe<EvReportNodeNumber>(*this);
}

void HUDSystem::receive(const EvReportNodeNumber& e)
{
	m_nodeText.setString(std::to_string(e.nodeNumber));
	m_currentLapText.setString(std::to_string(e.currentTime));
	m_lastLapText.setString(std::to_string(e.lastTime));
}

void HUDSystem::update(entityx::EntityManager& entities,
	entityx::EventManager& events,
	double dt)
{
	window.draw(m_nodeText);
	window.draw(m_currentLapText);
	window.draw(m_lastLapText);
}

void HUDSystem::setGenericTextProperties(sf::Text & textIn)
{
	textIn.setFont(m_font);
	textIn.setColor(sf::Color::White);
	textIn.setCharacterSize(28.f);
}