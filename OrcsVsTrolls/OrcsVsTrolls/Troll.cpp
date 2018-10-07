#include "Troll.h"

Troll::Troll()
{
	setStats();
}

void Troll::setStats()
{
	m_health = 150;
	m_speed = 5;
	m_strength = 15;
	m_defence = 15;
}
