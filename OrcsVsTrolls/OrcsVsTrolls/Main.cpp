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
	for (int i = 0; i < 10; i++)
	{
		orcWarriors[i]->setAlive(true);
	}

	for (int i = 0; i < 5; i++)
	{
		orcWarriors[i]->setAlive(true);
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
	campLoop();
	
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
			addWarriors(player, villagersToEnlist);
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
	std::cout << "is ready for battle!";
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
			break;
		}

		else
		{
			std::cout << "You don't have that many warriors! \nTry again: ";
			std::cin >> numOfWarriors;
		}
	}
}

void addWarriors(PlayerType & t_playerType, int t_warriorsToAdd)
{
	int warrirosAdded = 0;
	int currentWarrior = 0;

	if (Faction::ORC == t_playerType.ourFaction)
	{
		while(warrirosAdded != t_warriorsToAdd)
		{
			if (false == orcWarriors[currentWarrior]->getAlive())
			{
				orcWarriors[currentWarrior]->setAlive(true);
				warrirosAdded++;
			}
			currentWarrior++;
		}
	}
	else
	{
		while (warrirosAdded != t_warriorsToAdd)
		{
			if (false == trollWarriors[currentWarrior]->getAlive())
			{
				trollWarriors[currentWarrior]->setAlive(true);
				warrirosAdded++;
			}
			currentWarrior++;
		}
	}
}

void addWarriorsToRaidParty(PlayerType & t_playerType, int t_warriorsToAdd)
{
	int warrirosAdded = 0;
	int currentWarrior = 100;
	int currentRaidWarrior = 0;


	if (Faction::ORC == t_playerType.ourFaction)
	{
		while (warrirosAdded != t_warriorsToAdd)
		{
			if (true == orcWarriors[currentWarrior]->getAlive())
			{
				orcRaidParty[currentRaidWarrior] = orcWarriors[currentWarrior];
				warrirosAdded++;
				currentRaidWarrior++;
			}
			currentWarrior--;
		}
	}

	else
	{
		while (warrirosAdded != t_warriorsToAdd)
		{
			if (true == trollWarriors[currentWarrior]->getAlive())
			{
				trollRaidParty[currentRaidWarrior] = trollWarriors[currentWarrior];
				warrirosAdded++;
				currentRaidWarrior++;
			}
			currentWarrior--;
		}
	}
}
