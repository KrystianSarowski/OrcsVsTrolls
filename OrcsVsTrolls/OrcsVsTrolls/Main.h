#pragma once
#include <iostream>
#include "Orc.h"
#include "Troll.h"
#include <string>
#include <cstdlib>
#include <time.h>
// @Author: Krystian Satowski

//A pointer array of type character that stores all of our possible orc warriors.
Character * orcWarriors[100];

//A pointer array of type character that stores pointer to orc warrios that we have brought to battle.
Character * orcRaidParty[100];	

//A pointer array of type character that stores all of our possible troll warriors.
Character * trollWarriors[100];

//A pointer array of type character that stores pointer to troll warrios that we have brought to battle.
Character * trollRaidParty[100];

//Enum class that determines which race that playerType controlls.
enum class Faction
{
	ORC,
	TROLL
};

//Struct used to store all the information that the player and the AI needs.
struct PlayerType
{
	int gold{ 200 };			//Variable for the ammount of gold possesed.
	int armySize{ 0 };			//Variable for the amount of warriors in the camp.
	int campSize{ 0 };			//Variable for the amount of villigares in the camp.
	int raidPartySize{ 0 };		//Variable for the amount of warriors controlled during the battle.
	int swords{ 5 };			//Variable for the amount of swords possesed.
	int sheilds{ 5 };			//Variable for the amount of sheilds possesed.

	bool shieldActive{ false };	//Checks if we have an active shield up.
	bool campAttacked{ false };	//Checks if the camp cotrolled is being attacked by the enemy.

	Faction ourFaction;			//The race controlled.
};

PlayerType player;				//Person playing the game.
PlayerType computer;			//An AI that I call Bob de random bot.

bool victory;					//Checks if the player has won the game.
bool defeat;					//Checks if the player has been defeated.

void game();
void gameLoop();
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
void computerBattleOptions();
void printWarriorInfo(Character * t_ourPartyArray[], Character * t_enemyPartyArray[]);
void attackEnemy(Character * t_ourPartyArray[], Character * t_enemyPartyArray[],
	PlayerType &t_enemyType, int t_actionNum, int t_ourPartySize);
void defendYourself(Character * t_ourPartyArray[], int t_actionNum, int t_ourPartySize);
void battleConclusion();
void resetRaidPartyArray(Character * t_partyArray[]);
void resetWarriorArray();
void resetPlayerType(PlayerType &t_playerType);