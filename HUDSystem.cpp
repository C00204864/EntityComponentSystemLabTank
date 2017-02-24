#include "HUDSystem.h"

HUDSystem::HUDSystem(sf::RenderWindow & windowIn) : window(windowIn)
{
	m_font.loadFromFile("resources\\fonts\\akashi.ttf");
	m_nodeText.setFont(m_font);
	m_nodeText.setPosition(sf::Vector2f(15, 15));
	m_nodeText.setColor(sf::Color::White);
	m_nodeText.setCharacterSize(28.f);
}

void HUDSystem::configure(entityx::EventManager & events)
{
	events.subscribe<EvReportNodeNumber>(*this);
}

void HUDSystem::receive(const EvReportNodeNumber& e)
{
	m_nodeText.setString(std::to_string(e.nodeNumber));
}

void HUDSystem::update(entityx::EntityManager& entities,
	entityx::EventManager& events,
	double dt)
{
	window.draw(m_nodeText);
}