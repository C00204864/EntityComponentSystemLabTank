#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"

class HUDSystem
	: public entityx::System<HUDSystem>
	, public entityx::Receiver<HUDSystem>
{
public:
	HUDSystem(sf::RenderWindow & windowIn);
	void configure(entityx::EventManager& events);
	void receive(const EvReportNodeNumber& e);
	void update(entityx::EntityManager& entities,
		entityx::EventManager& events,
		double dt);
private:
	sf::RenderWindow & window;
	sf::Font m_font;
	sf::Text m_nodeText;
	sf::Text m_currentLapText;
	sf::Text m_lastLapText;
};