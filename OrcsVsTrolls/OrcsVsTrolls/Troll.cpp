#include "Troll.h"

Troll::Troll()
{
	m_melee1Name = "Crush";
	m_melee2Name = "Stomp";
	m_melee3Name = "Body Slam";

	m_defence1Name = "Protect Croch";
	m_defence2Name = "Defend Pretty Face";
	setStats();
}

int Troll::melee1()
{
	return 0;
}

int Troll::melee2()
{
	return 0;
}

int Troll::melee3()
{
	return 0;
}

void Troll::defence1()
{
}

void Troll::defence2()
{
}

void Troll::setStats()
{
	m_health = 150;
	m_speed = 5;
	m_strength = 15;
	m_defence = 15;
}
