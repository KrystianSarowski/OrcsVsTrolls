#pragma once


class Character
{
public:

	Character();

	virtual void setStats();
	void resetStats();
	void setAlive(bool t_aliveState);

	bool getAlive() const;

protected:

	int m_health;
	int m_defence;
	int m_strength;
	int m_speed;

	bool m_alive;
};

