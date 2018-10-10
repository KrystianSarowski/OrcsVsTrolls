#include "Troll.h"

Troll::Troll()
{
	m_charName = "Troll";

	m_melee1Name = "Crush";
	m_melee2Name = "Stomp";
	m_melee3Name = "Body Slam";

	m_defence1Name = "Protect Croch";
	m_defence2Name = "Defend Pretty Face";
	setStats();
}

int Troll::melee1()
{
	m_defence = 15;
	std::cout << "Me crush punny orc! " << std::endl;

	return ((rand() % 25) + m_strength);
}

int Troll::melee2()
{
	m_defence = 15;
	std::cout << "Me stomp the ground and orc fly like a bird! " << std::endl;

	return (rand() % 50);
}

int Troll::melee3()
{
	m_defence = 15;
	std::cout << "Me show orc why orc so small! " << std::endl;

	return ((rand() % 10) + m_strength * 2);
}

void Troll::defence1()
{
	std::cout << "Me protect my breakfast meal!" << std::endl;

	m_defence = (rand() % 30);

	std::cout << m_charName << "'s defence went up to " << m_defence << " until his next turn." << std::endl;
}

void Troll::defence2()
{
	std::cout << "Orc will not make me ugly as orc!" << std::endl;

	m_defence = (rand() % 40);

	std::cout << m_charName << "'s defence went up to " << m_defence << " until his next turn." << std::endl;
}

void Troll::setStats()
{
	m_health = 150;
	m_speed = 7;
	m_strength = 40;
	m_defence = 15;
}
