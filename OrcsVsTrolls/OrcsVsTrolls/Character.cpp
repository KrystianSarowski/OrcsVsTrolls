#include "Character.h"

Character::Character() : 
	m_defence{ 0 },
	m_health{ 0 },
	m_speed{ 0 },
	m_strength{ 0 },
	m_alive{ false }
{
}

void Character::resetStats()
{
	setStats();
}

void Character::printHealth()
{
	std::cout << m_health << std::endl;;
}

void Character::printMelee1()
{
	std::cout << m_melee1Name << std::endl;
}

void Character::printMelee2()
{
	std::cout << m_melee2Name << std::endl;
}

void Character::printMelee3()
{
	std::cout << m_melee3Name << std::endl;
}

void Character::printDefence1()
{
	std::cout << m_defence1Name << std::endl;
}

void Character::printDefence2()
{
	std::cout << m_defence2Name << std::endl;
}

void Character::setAlive(bool t_aliveState)
{
	m_alive = t_aliveState;
}

bool Character::getAlive() const
{
	return m_alive;
}

int Character::rollForTurn() const
{
	return ((rand() % 30) + m_speed);
}

