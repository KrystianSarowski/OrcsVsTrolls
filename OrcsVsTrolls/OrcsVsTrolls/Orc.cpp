#include "Orc.h"

Orc::Orc() 
{
	m_charName = "Orc";

	m_melee1Name = "Poke";
	m_melee2Name = "Kick";
	m_melee3Name = "Bash";

	m_defence1Name = "Guard Up";
	m_defence2Name = "Orc Poop Position";
	setStats();
}

int Orc::melee1()
{
	m_defence = 5;
	std::cout << "I am gone take your eye out troll! " << std::endl;

	return ((rand () % 30) + m_strength);
}

int Orc::melee2()
{
	m_defence = 5;
	std::cout << "Hope you have insurance on your royal jewels troll! " << std::endl;

	return ((rand() % 60));
}

int Orc::melee3()
{
	m_defence = 5;
	std::cout << "Mi smort Mi SMORCK!!" << std::endl;

	return ((rand() % 10) + m_strength * 2);
}

void Orc::defence1()
{
	std::cout << "No one can break my guard! " << std::endl;

	m_defence = (rand() % 20) + 5;

	std::cout << m_charName << "'s defence went up to " << m_defence << " until his next turn." << std::endl;
}

void Orc::defence2()
{
	std::cout << "Hard as rock! Smell as poop!" << std::endl;

	m_defence = (rand() % 40);

	std::cout << m_charName << "'s defence went up to " << m_defence << " until his next turn." << std::endl;
}

void Orc::setStats()
{
	m_health = 100;
	m_speed = 15;
	m_strength = 15;
	m_defence = 5;
}
