#pragma once
#include "Character.h"


class Orc : public Character
{
public:

	Orc();

	int melee1();
	int melee2();
	int melee3();

	void defence1();
	void defence2();

protected:

	void setStats();

};

