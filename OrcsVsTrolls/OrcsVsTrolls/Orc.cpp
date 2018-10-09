#include "Orc.h"

Orc::Orc() 
{
	m_melee1Name = "Poke";
	m_melee2Name = "Kick";
	m_melee3Name = "Bash";

	m_defence1Name = "Guard Up";
	m_defence2Name = "Orc Poop Position";
	setStats();
}

int Orc::melee1()
{
	return 0;
}

int Orc::melee2()
{
	return 0;
}

int Orc::melee3()
{
	return 0;
}

void Orc::defence1()
{
}

void Orc::defence2()
{
}

void Orc::setStats()
{
	m_health = 100;
	m_speed = 15;
	m_strength = 5;
	m_defence = 5;
}
