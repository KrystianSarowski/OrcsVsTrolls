#include "Character.h"
// @Author: Krystian Satowski

Character::Character() : 
	m_defence{ 0 },
	m_health{ 0 },
	m_speed{ 0 },
	m_strength{ 0 },
	m_alive{ false }
{
}

/// <summary>
/// Calls the function to reset stats to starting stats of the character
/// </summary>
void Character::resetStats()
{
	setStats();
}

/// <summary>
/// Prints out the value of the characters health.
/// </summary>
void Character::printHealth()
{
	std::cout << m_health << std::endl;;
}

/// <summary>
/// Prints out the name of meele1.
/// </summary>
void Character::printMelee1()
{
	std::cout << m_melee1Name << std::endl;
}

/// <summary>
/// Prints out the name of meele2.
/// </summary>
void Character::printMelee2()
{
	std::cout << m_melee2Name << std::endl;
}

/// <summary>
/// Prints out the name of meele3.
/// </summary>
void Character::printMelee3()
{
	std::cout << m_melee3Name << std::endl;
}

/// <summary>
/// Prints out the name of defence1.
/// </summary>
void Character::printDefence1()
{
	std::cout << m_defence1Name << std::endl;
}

/// <summary>
/// Prints out the name of defence2.
/// </summary>
void Character::printDefence2()
{
	std::cout << m_defence2Name << std::endl;
}

/// <summary>
/// Sets the alive variable based on the passed in bool.
/// Calls the function to set the stats to base stats just incase.
/// </summary>
void Character::setAlive(bool t_aliveState)
{
	setStats();
	m_alive = t_aliveState;
}

/// <summary>
/// Returns a bool for if the character is alive or not.
/// </summary>
bool Character::getAlive() const
{
	return m_alive;
}

/// <summary>
/// Takes in a value for the damage that the character will recieve and deals with it approperatly.
/// Returns true if the character has died as a result of the incoming damage.
/// Returns false if the character has not died as a result of the incoming damage.
/// </summary>
bool Character::takeDamage(int t_incomingDamage)
{
	//We subtract the defence from the incoming damage.
	//In other words we get the damage that has pentrated the armor.
	t_incomingDamage -= m_defence;

	//If the armor has been penetrated we deal damage to the characters health.
	if (t_incomingDamage > 0)
	{
		std::cout << m_charName << " has taken: " << t_incomingDamage << " damage" << std::endl;
		m_health -= t_incomingDamage;

		//We check if as a result the chaaracters health has not dropped below 0.
		if (m_health <= 0)
		{
			kill();
			return true;
		}
	}

	return false;
}

/// <summary>
/// Rolls the number for characters turn and adds on the characters speed.
/// </summary>
int Character::rollForTurn() const
{
	return ((rand() % 30) + m_speed);
}

/// <summary>
/// Changes the alive of the character to false and outputs approperate death message.
/// </summary>
void Character::kill()
{
	std::cout << m_charName << " took a fatal blow!" << std::endl;
	m_alive = false;
}

