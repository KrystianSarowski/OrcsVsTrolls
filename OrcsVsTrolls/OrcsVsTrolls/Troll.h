#pragma once

#include "Character.h"


class Troll : public Character
{
public:

	Troll();

	int melee1();
	int melee2();
	int melee3();

	void defence1();
	void defence2();

protected:
	
	void setStats();

};
