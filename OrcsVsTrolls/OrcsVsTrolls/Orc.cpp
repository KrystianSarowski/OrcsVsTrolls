#include "Orc.h"

Orc::Orc()
{
	setStats();
}

void Orc::setStats()
{
	m_health = 100;
	m_speed = 15;
	m_strength = 5;
	m_defence = 5;
}
