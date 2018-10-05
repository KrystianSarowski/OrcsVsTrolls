#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"

Orc bob;

enum class Faction
{
	ORC,
	TROLL
};

struct Player
{
	int gold;
	int armySize;
	int campSize;
	int swords; 
	int sheild;
	int spells;

	Faction ourFaction;
};

Player player;