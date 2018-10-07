#include "Character.h"

Character::Character() : 
	m_defence{ 0 },
	m_health{ 0 },
	m_speed{ 0 },
	m_strength{ 0 },
	m_alive{ false }
{
}

void Character::setStats()
{
	
}

void Character::resetStats()
{
	setStats();
}

void Character::setAlive(bool t_aliveState)
{
	m_alive = t_aliveState;
}

bool Character::getAlive() const
{
	return m_alive;
}
