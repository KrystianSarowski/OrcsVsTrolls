#pragma once
#include "Character.h"
// @Author: Krystian Satowski

/// <summary>
/// Sub class of character called troll.
/// </summary>
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
