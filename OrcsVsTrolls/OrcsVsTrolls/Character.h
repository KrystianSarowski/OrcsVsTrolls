#pragma once
#include <iostream>
#include <string>

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

	int m_health;
	int m_defence;
	int m_strength;
	int m_speed;

	bool m_alive;

	std::string m_charName;
	std::string m_melee1Name;
	std::string m_melee2Name;
	std::string m_melee3Name;
	std::string m_defence1Name;
	std::string m_defence2Name;

};

