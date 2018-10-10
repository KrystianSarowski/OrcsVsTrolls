#include "Main.h"


int main()
{
	std::string keepPlaying = "Yes";
	welcomeMessage();
	setWarriorPointers();

	while ("Yes" == keepPlaying)
	{
		game();
		std::cout << "Do you wish to play again? \nType Yes to keep playing anything else to quite. " << std::endl;
		std::cin >> keepPlaying;
	}
	
	system("PAUSE");
	return 0;
}

void game()
{
	std::srand(static_cast<unsigned>(time(NULL)));

	victory = false;
	defeat = false;

	resetPlayerType(player);
	resetPlayerType(computer);

	for (int i = 0; i < 100; i++)
	{
		orcWarriors[i]->setAlive(false);
	}

	for (int i = 0; i < 100; i++)
	{
		trollWarriors[i]->setAlive(false);
	}

	for (int i = 0; i < 10; i++)
	{
		orcWarriors[i]->setAlive(true);
	}

	for (int i = 0; i < 5; i++)
	{
		trollWarriors[i]->setAlive(true);
	}

	std::string factionChoice;
	std::cout << "Select what faction you want to play by typing orcs or trolls: ";
	std::cin >> factionChoice;

	while (true)
	{
		if ("orcs" == factionChoice)
		{
			player.ourFaction = Faction::ORC;
			computer.ourFaction = Faction::TROLL;
			break;
		}

		else if ("trolls" == factionChoice)
		{
			player.ourFaction = Faction::TROLL;
			computer.ourFaction = Faction::ORC;
			break;
		}

		else
		{
			std::cout << "Incorrect input! \nChoose either orcs or trolls: ";
			std::cin >> factionChoice;
		}
	}

	setFactionStartNumbers();
	gameLoop();

	if (true == victory)
	{
		std::cout << "*****************************************************************************\n";
		std::cout << "You have succesful taken over the ";
		if (Faction::ORC == player.ourFaction)
		{
			std::cout << "troll's ";
		}
		else
		{
			std::cout << "orc's ";
		}
		std::cout << "camp and brought peace to this land!" << std::endl;
	}
	else
	{
		std::cout << "*****************************************************************************\n";
		std::cout << "Your camp has been taken over by ";
		if (Faction::ORC == player.ourFaction)
		{
			std::cout << "trolls";
		}
		else
		{
			std::cout << "orcs";
		}
		std::cout << ". Dark times are ahead of this land." << std::endl;
	}
}

void gameLoop()
{
	while (false == defeat && false == victory)
	{
		campLoop();
		campAI();
		combatLoop();
		battleConclusion();

		if (true == player.campAttacked)
		{
			player.raidPartySize = player.armySize;
			player.armySize = 0;
			if (Faction::ORC == player.ourFaction)
			{
				addWarriorsToRaidParty(orcWarriors, orcRaidParty, player);
			}
			else
			{
				addWarriorsToRaidParty(trollWarriors, trollRaidParty, player);
			}
			std::cout << "Enemy has begun siege over your camp!" << std::endl;
			std::cout << "You have: " << player.raidPartySize << " warriors left" << std::endl;
			std::cout << "Enemy has: " << computer.raidPartySize << " warriors left" << std::endl;
			system("PAUSE");
			combatLoop();

			if (0 == player.raidPartySize)
			{
				defeat = true;
				continue;
			}

		}
		else if (true == computer.campAttacked)
		{
			computer.raidPartySize = computer.armySize;
			computer.armySize = 0;
			if (Faction::ORC == computer.ourFaction)
			{
				addWarriorsToRaidParty(orcWarriors, orcRaidParty, computer);
			}
			else
			{
				addWarriorsToRaidParty(trollWarriors, trollRaidParty, computer);
			}
			std::cout << "*****************************************************************************\n";
			std::cout << "You have begun the siege of enemy camp!" << std::endl;
			std::cout << "You have: " << player.raidPartySize << " warriors left" << std::endl;
			std::cout << "Enemy has: " << computer.raidPartySize << " warriors left" << std::endl;
			system("PAUSE");
			combatLoop();

			if (0 == computer.raidPartySize)
			{
				victory = true;
				continue;
			}
		}

		player.armySize += player.raidPartySize;
		computer.armySize += computer.raidPartySize;
		player.campSize = player.campSize * 2;
		computer.campSize = computer.campSize * 2;
		resetWarriorArray();
	}
}

void welcomeMessage()
{
	std::cout << "*****************************************************************************\n";
	std::cout << "Welcome to Orcs versus Trolls!" << std::endl;
	std::cout << "Your favorite turn based combat game since Phil told us to make this game!" << std::endl;
	std::cout << "*****************************************************************************\n";
	system("PAUSE");
	rules();
}

void rules()
{
	std::cout << "*****************************************************************************\n";
	std::cout << "THE RULES!!!" << std::endl;
	std::cout << "You choose to either be orc or trolls. The other faction is controled by AI." << std::endl;
	std::cout << "Orcs are quick so they attack more often and have bigger numbers." << std::endl;
	std::cout << "Trolls are very healthy and they hit like a truck." << std::endl;
	std::cout << "*****************************************************************************\n";
	std::cout << "Phase 1: In this phase you are in the camp where you manage your resources." << std::endl;
	std::cout << "You can select the number of villagers to enlist a warriors." << std::endl;
	std::cout << "Note that population doubles when you come back to the camp after battle." << std::endl;
	std::cout << "In the camp you can alos buy swords and shields that can be used in combat." << std::endl;
	std::cout << "*****************************************************************************\n";
	std::cout << "Phase 2: You need to choose how many warriors you want to send to fight." << std::endl;
	std::cout << "Rest of them stay to defend the camp in case you lost." << std::endl;
	std::cout << "Who attacks is choosen randomly though orcs attack twice as often." << std::endl;
	std::cout << "A shield can be used to negate any incoming damage unless a sword is used." << std::endl;
	std::cout << "A sword will kill the orc that is attacked unless a shield is used." << std::endl;
	std::cout << "The combat ends when the last warrior of the other faction is dead." << std::endl;
	std::cout << "*****************************************************************************\n";
	std::cout << "Phase 3: The winner of the battle will recive gold for victory and option" << std::endl;
	std::cout << "to attack the enemy camp or go back to their camp." << std::endl;
	std::cout << "If the warriors in the enemy camp are all killed the attacking faction wins." << std::endl;
	std::cout << "*****************************************************************************\n";
	system("PAUSE");
}

void setFactionStartNumbers()
{
	if (Faction::ORC == player.ourFaction)
	{
		assignOrcs(player);
		assignTrolls(computer);
	}

	else
	{
		assignTrolls(player);
		assignOrcs(computer);
	}
}

void assignTrolls(PlayerType &t_playerType)
{
	t_playerType.armySize = 5;
	t_playerType.campSize = 10;
}

void assignOrcs(PlayerType &t_playerType)
{
	t_playerType.armySize = 10;
	t_playerType.campSize = 15;
}

void setWarriorPointers()
{
	for (int i = 0; i < 100; i++)
	{
		orcWarriors[i] = new Orc;
		trollWarriors[i] = new Troll;
	}
}

void campLoop()
{
	bool battleTime = false;

	while (false == battleTime)
	{

		std::cout << "*****************************************************************************\n";
		std::cout << "Welcome to the ";
		if (Faction::ORC == player.ourFaction)
		{
			std::cout << "orc's ";
		}
		else
		{
			std::cout << "troll's ";
		}
		std::cout << "camp commander! " << std::endl;
		std::cout << "The population of the camp is: " << player.campSize << std::endl;
		std::cout << "Your vault contains: " << player.gold << " gold" << std::endl;
		std::cout << "*****************************************************************************\n";
		std::cout << "To enlist soldiers type in (barracks).\nTo buy swords or shields type in (blacksmith).";
		std::cout << "\nTo challenge the pesky ";
		if (Faction::ORC == player.ourFaction)
		{
			std::cout << "trolls ";
		}
		else
		{
			std::cout << "orcs ";
		}
		std::cout << "type out (battle): ";

		std::string orders;
		std::cin >> orders;

		while (true)
		{
			if ("barracks" == orders)
			{
				barracksLoop();
				break;
			}

			else if ("blacksmith" == orders)
			{
				blacksmithLoop();
				break;
			}

			else if ("battle" == orders)
			{
				preBattle();
				battleTime = true;
				break;
			}

			else
			{
				std::cout << "Incorrect input! \nTry again: ";
				std::cin >> orders;
			}
		}
	}

}

void barracksLoop()
{
	bool backToCamp = false;

	while (false == backToCamp)
	{
		std::cout << "*****************************************************************************\n";
		std::cout << "Welcome to the barracks!" << std::endl;
		std::cout << "The population of your camp is: " << player.campSize;
		if (Faction::ORC == player.ourFaction)
		{
			std::cout << " orcs";
		}
		else
		{
			std::cout << " trolls";
		}

		std::cout << "\nYour army consists of: " << player.armySize;

		if (Faction::ORC == player.ourFaction)
		{
			std::cout << " orc warriors" << std::endl;
		}
		else
		{
			std::cout << " troll warriors" << std::endl;
		}
		std::cout << "*****************************************************************************\n";
		std::cout << "To enlist warriors from the camp type in (enlist). " << std::endl;
		std::cout << "To return to the main camp type in (return): ";

		std::string orders;
		std::cin >> orders;

		while (true)
		{
			if ("enlist" == orders)
			{
				enlistLoop();
				break;
			}

			else if ("return" == orders)
			{
				backToCamp = true;
				break;
			}

			else
			{
				std::cout << "Incorrect input! \nTry again: ";
				std::cin >> orders;
			}
		}
	}
}

void enlistLoop()
{
	std::cout << "*****************************************************************************\n";
	std::cout << "Type in the number of ";
	if (Faction::ORC == player.ourFaction)
	{
		std::cout << "orcs ";
	}
	else
	{
		std::cout << "trolls ";
	}

	std::cout << "you want to enlist: ";

	int villagersToEnlist;
	std::cin >> villagersToEnlist;

	while (true)
	{
		if (player.campSize >= villagersToEnlist &&  0 <= villagersToEnlist)
		{
			player.campSize -= villagersToEnlist;
			player.armySize += villagersToEnlist;

			if (Faction::ORC == player.ourFaction)
			{
				addWarriors(orcWarriors, villagersToEnlist);
			}

			else
			{
				addWarriors(trollWarriors, villagersToEnlist);
			}

			break;
		}

		else
		{
			std::cout << "Incorrect input! \nTry again: ";
			std::cin >> villagersToEnlist;
		}
	}
}

void blacksmithLoop()
{
	bool backToCamp = false;

	while (false == backToCamp)
	{
		std::cout << "*****************************************************************************\n";
		std::cout << "Welcome to the blacksmith!";
		std::cout << "Your vault contains: " << player.gold << " gold" << std::endl;
		std::cout << "The number of swords you have is: " << player.swords << std::endl;
		std::cout << "The number of swords you have is: " << player.sheild << std::endl;
		std::cout << "*****************************************************************************\n";
		std::cout << "To forge swords type in (swords). " << std::endl;
		std::cout << "To forge swords type in (shields). " << std::endl;
		std::cout << "To return to the main camp type in (return): ";

		std::string orders;
		std::cin >> orders;

		while (true)
		{
			if ("swords" == orders)
			{
				forgeSwords();
				break;
			}

			else if ("shields" == orders)
			{
				forgeShields();
				break;
			}

			else if ("return" == orders)
			{
				backToCamp = true;
				break;
			}

			else
			{
				std::cout << "Incorrect input! \nTry again: ";
				std::cin >> orders;
			}
		}
	}
}

void forgeSwords()
{
	std::cout << "*****************************************************************************\n";
	std::cout << "Each sword costs 30 gold to forge." << std::endl;
	std::cout << "Enter the number of swords you want to purchase: ";

	int numSwordsToForge;
	std::cin >> numSwordsToForge;

	while (true)
	{
		if (player.gold >= numSwordsToForge * 30 && 0 <= numSwordsToForge)
		{
			player.gold -= numSwordsToForge * 30;
			player.swords += numSwordsToForge;
			break;
		}

		else
		{
			std::cout << "You don't have that much gold! \nTry again: ";
			std::cin >> numSwordsToForge;
		}
	}
}

void forgeShields()
{
	std::cout << "*****************************************************************************\n";
	std::cout << "Each shield costs 20 gold to forge." << std::endl;
	std::cout << "Enter the number of shileds you want to purchase: ";

	int numshiledsToForge;
	std::cin >> numshiledsToForge;

	while (true)
	{
		if (player.gold >= numshiledsToForge * 20 && 0 <= numshiledsToForge)
		{
			player.gold -= numshiledsToForge * 20;
			player.sheild += numshiledsToForge;
			break;
		}

		else
		{
			std::cout << "You don't have that much gold! \nTry again: ";
			std::cin >> numshiledsToForge;
		}
	}
}

void preBattle()
{
	std::cout << "*****************************************************************************\n";
	std::cout << "Commander your ";
	if (Faction::ORC == player.ourFaction)
	{
		std::cout << "orc";
	}
	else
	{
		std::cout << "troll ";
	}
	std::cout << "is ready for battle!" << std::endl;
	std::cout << "Your army consists of: " << player.armySize;
	if (Faction::ORC == player.ourFaction)
	{
		std::cout << " orc warriors";
	}
	else
	{
		std::cout << " troll warriors ";
	}
	std::cout << std::endl;
	std::cout << "Enter the number of warriors you wish to send to battle: ";

	int numOfWarriors;
	std::cin >> numOfWarriors;

	while (true)
	{
		if (player.armySize >= numOfWarriors && 0 <= numOfWarriors)
		{
			player.raidPartySize = numOfWarriors;
			player.armySize -= numOfWarriors;
			if (Faction::ORC == player.ourFaction)
			{
				addWarriorsToRaidParty(orcWarriors, orcRaidParty, player);
			}

			else
			{
				addWarriorsToRaidParty(trollWarriors, trollRaidParty, player);
			}
			break;
		}

		else
		{
			std::cout << "You don't have that many warriors! \nTry again: ";
			std::cin >> numOfWarriors;
		}
	}
}

void addWarriors(Character * t_charWarriorArray[], int t_warriorsToAdd)
{
	int warrirosAdded = 0;
	int currentWarrior = 0;

	while (warrirosAdded != t_warriorsToAdd)
	{
		if (false == t_charWarriorArray[currentWarrior]->getAlive())
		{
			t_charWarriorArray[currentWarrior]->setAlive(true);
			warrirosAdded++;
		}
		currentWarrior++;
	}
}

void addWarriorsToRaidParty(Character * t_charArray[], Character * t_charPartyArray[], PlayerType &t_playerType)
{
	resetRaidPartyArray(t_charPartyArray);
	int warrirosAdded = 0;
	int currentWarrior = 99;
	int currentRaidWarrior = 0;


	while (warrirosAdded != t_playerType.raidPartySize)
	{
		if (true == t_charArray[currentWarrior]->getAlive())
		{
			t_charPartyArray[currentRaidWarrior] = t_charArray[currentWarrior];
			warrirosAdded++;
			currentRaidWarrior++;
		}
		currentWarrior--;
	}

}

void campAI()
{
	int warriorsToRecruit = (rand() % (computer.campSize / 4)) + computer.campSize / 4;
	computer.campSize -= warriorsToRecruit;
	computer.armySize += warriorsToRecruit;
	if (Faction::ORC == computer.ourFaction)
	{
		addWarriors(orcWarriors, warriorsToRecruit);
	}

	else
	{
		addWarriors(trollWarriors, warriorsToRecruit);
	}

	int swordsToForge = rand() % 2;

	if (computer.gold <= swordsToForge * 30)
	{
		computer.gold -= swordsToForge * 30;
		computer.swords += swordsToForge;
	}

	int sheildsToForge = rand() % 4;

	if (computer.gold <= sheildsToForge * 20)
	{
		computer.gold -= sheildsToForge * 20;
		computer.sheild += sheildsToForge;
	}

	computer.raidPartySize = (rand() % ((computer.armySize / 2) + 1)) + computer.armySize / 2;
	computer.armySize -= computer.raidPartySize;

	if (Faction::ORC == computer.ourFaction)
	{
		addWarriorsToRaidParty(orcWarriors, orcRaidParty, computer);
	}

	else
	{
		addWarriorsToRaidParty(trollWarriors, trollRaidParty, computer);
	}

}

void combatLoop()
{
	while (player.raidPartySize > 0 && computer.raidPartySize > 0)
	{
		bool playerTurn = false;

		if (Faction::ORC == player.ourFaction)
		{

			if (orcRaidParty[player.raidPartySize - 1]->rollForTurn() >= trollRaidParty[computer.raidPartySize - 1]->rollForTurn())
			{
				playerTurn = true;
			}
		}
		else
		{
			if (trollRaidParty[player.raidPartySize - 1]->rollForTurn() >= orcRaidParty[computer.raidPartySize - 1]->rollForTurn())
			{
				playerTurn = true;
			}
		}

		if (true == playerTurn)
		{
			std::cout << "*****************************************************************************\n";
			std::cout << "It is your turn now!" << std::endl;
			system("PAUSE");
			playerBattleOptions();
		}

		else
		{
			std::cout << "*****************************************************************************\n";
			std::cout << "It is enemy's turn now!" << std::endl;
			system("PAUSE");
			computerBattleOptions();
		}
	}
}

void playerBattleOptions()
{
	if (Faction::ORC == player.ourFaction)
	{
		printWarriorInfo(orcRaidParty, trollRaidParty);
	}
	else
	{
		printWarriorInfo(trollRaidParty, orcRaidParty);
	}

	std::cout << "Select what action you want to carry out by typing in its number. " << std::endl;
	std::cout << "Attacks deal damage to the enemy. " << std::endl;
	std::cout << "Defences increase your protection until your next turn." << std::endl;
	std::cout << "Sword instanly kills you foe unless they have a shield up." << std::endl;
	std::cout << "Shiled gives you 100 % protection until damage is taken." << std::endl;
	std::cout << "Enter Action number: ";

	int playerAction;
	std::cin >> playerAction;

	while (true)
	{
		if (1 <= playerAction && 3 >= playerAction)
		{
			if (Faction::ORC == player.ourFaction)
			{
				attackEnemy(orcRaidParty, trollRaidParty, computer, playerAction, player.raidPartySize);
			}
			else
			{
				attackEnemy(trollRaidParty, orcRaidParty, computer, playerAction, player.raidPartySize);
			}
			break;
		}

		else if (4 == playerAction || 5 == playerAction)
		{
			std::cout << "*****************************************************************************\n";
			if (Faction::ORC == player.ourFaction)
			{
				defendYourself(orcRaidParty, playerAction, player.raidPartySize);
			}
			else
			{
				defendYourself(trollRaidParty, playerAction, player.raidPartySize);
			}
			break;
		}

		else if (6 == playerAction)
		{
			if (player.swords > 0)
			{
				std::cout << "*****************************************************************************\n";
				std::cout << "You have used a sword!" << std::endl;
				if (false == computer.shieldActive)
				{
					if (Faction::ORC == player.ourFaction)
					{
						trollRaidParty[computer.raidPartySize - 1]->kill();
					}
					else
					{
						orcRaidParty[computer.raidPartySize - 1]->kill();
					}
					computer.raidPartySize--;
				}
				else
				{
					std::cout << "Enemy shield has been destroyed! " << std::endl;
					computer.shieldActive = false;
				}
				player.swords--;
				system("Pause");
				break;
			}

			else
			{
				std::cout << "You don't have that many swords choose a diffrent action: ";
				std::cin >> playerAction;
			}
		}

		else if (7 == playerAction)
		{
			if (player.sheild > 0)
			{
				player.shieldActive = true;
				player.sheild--;
				std::cout << "*****************************************************************************\n";
				std::cout << "Shield has been equipped!" << std::endl;
				system("PAUSE");
				break;
			}
			else
			{
				std::cout << "You don't have that many shields choose a diffrent action: ";
				std::cin >> playerAction;
			}
		}
		else
		{
			std::cout << "Incorrect action number try again: ";
			std::cin >> playerAction;
		}
	}
}

void computerBattleOptions()
{
	int computerAction = (rand() % 7) + 1;

	while (true)
	{
		if (1 <= computerAction && 3 >= computerAction)
		{
			if (Faction::ORC == computer.ourFaction)
			{
				attackEnemy(orcRaidParty, trollRaidParty, player, computerAction, computer.raidPartySize);
			}
			else
			{
				attackEnemy(trollRaidParty, orcRaidParty, player, computerAction, computer.raidPartySize);
			}
			break;
		}

		else if (4 == computerAction || 5 == computerAction)
		{
			std::cout << "*****************************************************************************\n";
			if (Faction::ORC == computer.ourFaction)
			{
				defendYourself(orcRaidParty, computerAction, computer.raidPartySize);
			}
			else
			{
				defendYourself(trollRaidParty, computerAction, computer.raidPartySize);
			}
			break;
		}

		else if (6 == computerAction)
		{
			if (computer.swords > 0)
			{
				std::cout << "*****************************************************************************\n";
				std::cout << "Enemy has used a sword!" << std::endl;
				if (false == player.shieldActive)
				{
					if (Faction::ORC == computer.ourFaction)
					{
						trollRaidParty[player.raidPartySize - 1]->kill();
					}
					else
					{
						orcRaidParty[player.raidPartySize - 1]->kill();
					}
					player.raidPartySize--;
				}
				else
				{
					std::cout << "Shield has been destroyed! " << std::endl;
					player.shieldActive = false;
				}
				computer.swords--;
				break;
			}

			else
			{
				computerAction = (rand() % 7) + 1;
			}
		}

		else if (7 == computerAction)
		{
			if (computer.sheild > 0)
			{
				computer.shieldActive = true;
				computer.sheild--;
				std::cout << "*****************************************************************************\n";
				std::cout << "Enemy equipped a shield!" << std::endl;
				break;
			}
			else
			{
				computerAction = (rand() % 7) + 1;
			}
		}
	}

	std::cout << "You have: " << player.raidPartySize << " warriors left" << std::endl;
	system("PAUSE");
}

void printWarriorInfo(Character * t_ourPartyArray[], Character * t_enemyPartyArray[])
{
	std::cout << "*****************************************************************************\n";
	std::cout << "You have: " << player.raidPartySize << " warriors left" << std::endl;
	std::cout << "Enemy has: " << computer.raidPartySize << " warriors left" << std::endl;
	std::cout << "Your warrior's health is: ";
	t_ourPartyArray[player.raidPartySize - 1]->printHealth();
	std::cout << "Enemy warrior's health is: ";
	t_enemyPartyArray[computer.raidPartySize - 1]->printHealth();

	std::cout << "ATTACKS" << std::endl;
	std::cout << "Action 1: ";
	t_ourPartyArray[player.raidPartySize - 1]->printMelee1();
	std::cout << "Action 2: ";
	t_ourPartyArray[player.raidPartySize - 1]->printMelee2();
	std::cout << "Action 3: ";
	t_ourPartyArray[player.raidPartySize - 1]->printMelee3();
	std::cout << "DEFENCES" << std::endl;
	std::cout << "Action 4: ";
	t_ourPartyArray[player.raidPartySize - 1]->printDefence1();
	std::cout << "Action 5: ";
	t_ourPartyArray[player.raidPartySize - 1]->printDefence2();
	std::cout << "ITEMS" << std::endl;
	std::cout << "Action 6: swords(" << player.swords << ")" << std::endl;
	std::cout << "Action 7: shields(" << player.sheild << ")" << std::endl;
	std::cout << "*****************************************************************************\n";
}

void attackEnemy(Character * t_ourPartyArray[], Character * t_enemyPartyArray[], PlayerType & t_enemyType, int t_actionNum, int t_ourPartySize)
{
	std::cout << "*****************************************************************************\n";
	if (false == t_enemyType.shieldActive)
	{
		int incomingDamage;
		if (1 == t_actionNum)
		{
			incomingDamage = t_ourPartyArray[t_ourPartySize - 1]->melee1();

			if (t_enemyPartyArray[t_enemyType.raidPartySize - 1]->takeDamage(incomingDamage))
			{
				t_enemyType.raidPartySize--;
			}
		}

		else if (2 == t_actionNum)
		{
			incomingDamage = t_ourPartyArray[t_ourPartySize - 1]->melee2();

			if (t_enemyPartyArray[t_enemyType.raidPartySize - 1]->takeDamage(incomingDamage))
			{
				t_enemyType.raidPartySize--;
			}
		}

		else
		{
			incomingDamage = t_ourPartyArray[t_ourPartySize - 1]->melee3();

			if (t_enemyPartyArray[t_enemyType.raidPartySize - 1]->takeDamage(incomingDamage))
			{
				t_enemyType.raidPartySize--;
			}
		}
	}

	else
	{
		std::cout << "Shield has been destroyed! " << std::endl;
		t_enemyType.shieldActive = false;
	}
	system("PAUSE");
}

void defendYourself(Character * t_ourPartyArray[], int t_actionNum, int t_ourPartySize)
{
	if (4 == t_actionNum)
	{
		t_ourPartyArray[t_ourPartySize - 1]->defence1();
	}

	else
	{
		t_ourPartyArray[t_ourPartySize - 1]->defence2();
	}

	system("PAUSE");
}

void battleConclusion()
{
	if (computer.raidPartySize == 0)
	{
		std::cout << "*****************************************************************************\n";
		std::cout << "You have Won the Battle!" << std::endl;
		std::cout << "All enemy ";
		if (Faction::ORC == player.ourFaction)
		{
			std::cout << "orcs have been killed!" << std::endl;
		}
		else
		{
			std::cout << "trolls have been killed!" << std::endl;
		}
		system("PAUSE");
		std::cout << "*****************************************************************************\n";
		std::cout << "Do you wish to attack enemy camp?" << std::endl;
		std::cout << "Type in (yes) to attack enemy camp, anything else to return to your camp:" << std::endl;
		std::string playerDecision;
		std::cin >> playerDecision;

		if ("yes" == playerDecision)
		{
			computer.campAttacked = true;
		}

		player.gold += 100;
	}
	else
	{
		std::cout << "*****************************************************************************\n";
		std::cout << "You have lost the Battle!" << std::endl;
		std::cout << "All your ";
		if (Faction::ORC == player.ourFaction)
		{
			std::cout << "orcs have been killed!" << std::endl;
		}
		else
		{
			std::cout << "trolls have been killed!" << std::endl;
		}
		system("PAUSE");

		int computerDecision = rand() % 2;
		if (0 == computerDecision)
		{
			player.campAttacked = true;
		}
		computer.gold += 100;
	}
}

void resetRaidPartyArray(Character * t_partyArray[])
{
	for (int i = 0; i < 100; i++)
	{
		t_partyArray[i] = nullptr;
	}
}

void resetWarriorArray()
{
	for (int i = 0; i < 100; i++)
	{
		orcWarriors[i]->resetStats();
		trollWarriors[i]->resetStats();
	}
}

void resetPlayerType(PlayerType &t_playerType)
{
	t_playerType.gold = 200;
	t_playerType.armySize = 0;
	t_playerType.campSize = 0;
	t_playerType.raidPartySize = 0;
	t_playerType.swords = 5;
	t_playerType.sheild = 5;

	t_playerType.shieldActive = false;
	t_playerType.campAttacked = false;

}
