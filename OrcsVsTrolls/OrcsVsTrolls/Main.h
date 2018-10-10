#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
#include <string>
#include <cstdlib>
#include <time.h>

Character * orcWarriors[100];
Character * orcRaidParty[100];
Character * trollWarriors[100];
Character * trollRaidParty[100];

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
	int raidPartySize{ 0 };
	int swords{ 5 };
	int sheild{ 5 };
	int spells{ 0 };

	bool shieldActive{ false };

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
void addWarriors(Character * t_charWarriorArray[], int t_warriorsToAdd);
void addWarriorsToRaidParty(Character * t_charArray[], Character * t_charPartyArray[],PlayerType &t_playerType);
void campAI();
void combatLoop();
void playerBattleOptions();
void printWarriorInfo(Character * t_ourPartyArray[], Character * t_enemyPartyArray[]);