#pragma once
#include <iostream>
#include <string>
// @Author: Krystian Satowski

class Character
{
public:

	Character();

	virtual void setStats() = 0;
	void resetStats();
	void printHealth();
	void printMelee1();
	void printMelee2();
	void printMelee3();
	void printDefence1();
	void printDefence2();
	void setAlive(bool t_aliveState);

	bool getAlive() const;
	bool takeDamage(int t_incomingDamage);

	int rollForTurn() const;

	virtual int melee1() = 0;
	virtual int melee2() = 0;
	virtual int melee3() = 0;

	virtual void defence1() = 0;
	virtual void defence2() = 0;

	void kill();

protected:

	int m_health;					//The health the character has if it hits 0 its dead.
	int m_defence;					//The number the incoming damage needs to get through before it affects the health.
	int m_strength;					//The base damage modifier on some attacks.
	int m_speed;					//Base damage modifier that increases the chance of this character having a trun.

	bool m_alive;					//Determines if the character is alive or not.

	std::string m_charName;			//The name of the character object.
	std::string m_melee1Name;		//Name of the meele1.
	std::string m_melee2Name;		//Name of the meele2.
	std::string m_melee3Name;		//Name of the meele3.
	std::string m_defence1Name;		//Name of the defence1.
	std::string m_defence2Name;		//Name of the defence2.

};

