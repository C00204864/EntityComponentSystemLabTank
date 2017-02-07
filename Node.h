#pragma once

#include "entityx/Entity.h"

struct Node : public entityx::Component<Node>
{
	Node(float radius);
	float m_radius;
};
