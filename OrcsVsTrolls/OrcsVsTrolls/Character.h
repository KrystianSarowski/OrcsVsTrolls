#pragma once


class Character
{
public:

	virtual void setStats();

protected:

	int m_health;
	int m_defence;
	int m_strength;
	int m_speed;
};

