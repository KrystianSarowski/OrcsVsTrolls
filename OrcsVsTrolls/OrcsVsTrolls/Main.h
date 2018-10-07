#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
#include <string>

Orc * orcWarriors[100];
Troll * trollWarriors[100];

enum class Faction
{
	ORC,
	TROLL
};

struct PlayerType
{
	int gold{ 200 };
	int armySize{ 0 };
	int campSize{ 0 };
	int swords{ 5 };
	int sheild{ 5 };
	int spells{ 0 };

	Faction ourFaction;
};

PlayerType player;
PlayerType computer;


void game();
void welcomeMessage();
void rules();
void setFactionStartNumbers();
void assignTrolls(PlayerType &t_playerType);
void assignOrcs(PlayerType &t_playerType);
void setWarriorPointers();
void campLoop();
void barracksLoop();
void enlistLoop();
void blacksmithLoop();
void forgeSwords();
void forgeShields();
void preBattle();