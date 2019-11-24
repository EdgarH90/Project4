#include "Game.hpp"



Game::Game()
{
}


Game::~Game()
{
}

/*********************************************************************
*					Game::selectChar()
* This function has the user select the character to be created by taking
* in the player number and the player's choice as integer parameters.
*********************************************************************/

void Game::selectChar(int playerNum, int playerChoice)
{
	//Create a new character based on the player selection

	if (playerChoice == 1)
	{
		if (playerNum == 1)
		{
			player1 = std::make_shared<HarryPotter>();
		}
		else
		{
			player2 = std::make_shared<HarryPotter>();
		}
	}
	else if (playerChoice == 2)
	{
		if (playerNum == 1)
		{
			player1 = std::make_shared<Vampire>();
		}
		else
		{
			player2 = std::make_shared<Vampire>();
		}
	}
	else if (playerChoice == 3)
	{
		if (playerNum == 1)
		{
			player1 = std::make_shared<BlueMen>();
		}
		else
		{
			player2 = std::make_shared<BlueMen>();
		}
	}
	else if (playerChoice == 4)
	{
		if (playerNum == 1)
		{
			player1 = std::make_shared<Barbarian>();
		}
		else
		{
			player2 = std::make_shared<Barbarian>();
		}
	}
	else
	{
		if (playerNum == 1)
		{
			player1 = std::make_shared<Medusa>();
		}
		else
		{
			player2 = std::make_shared<Medusa>();
		}
	}
}

/*********************************************************************
*					Game::playeroneAttacks()
* This function implements the round when player one attacks first.
* It uses the attack and defense functions from both characters to 
* display the round stats.
*********************************************************************/
void Game::playeroneAttacks()
{
	//Display the attacker and defender types
	std::cout<< "\n ***" << player1->getName() << " (Team One)" <<
	" attacks "<< player2->getName() << " (Team Two)" << "!***\n" << std::endl;

	//Display defender's stats
	std::cout << player2->getName() << "'s (Team Two Defender) stats: " << std::endl;
	std::cout << "Armor: " << player2->getArmor() << std::endl;
	std::cout << "Strength: " << player2->getStrength() << std::endl;

	//Used to store the points for the player's attacks
	int pOneAttack = player1->attack();

	//Player 2 defends and takes damage
	player2->defense(pOneAttack);
	
	//Check to see if player died
	if (player2->getStrength() > 0)
	{
		std::cout << player2->getName() << "'s Strength is now: " <<
			player2->getStrength() << std::endl;
	}
	else
	{
		std::cout << "\n *********************** \n"
			<< player2->getName() << " died. " <<
			player1->getName() << " (Team One) wins! \n ";
		std::cout << " *********************** \n";
		roundWinner = 1;
	}
}

/*********************************************************************
*					Game::playertwoAttacks()
* This function implements the round when player two attacks first.
* It uses the attack and defense functions from both characters to
* display the round stats.
*********************************************************************/
void Game::playertwoAttacks()
{
	//Display the attacker and defender types
	std::cout << "\n***" << player2->getName() << " (Team Two)" <<
		" attacks " << player1->getName() << " (Team One)!***\n" << std::endl;

	//Display defender's stats
	std::cout << player1->getName() << "'s (Team One Defender) stats: " << std::endl;
	std::cout << "Armor: " << player1->getArmor() << std::endl;
	std::cout << "Strength: " << player1->getStrength() << std::endl;

	//Used to store the points for the player's attacks
	int pTwoAttack = player2->attack();

	//Player 1 defends and takes damage
	player1->defense(pTwoAttack);

	//Check to see if player died
	if (player1->getStrength() > 0)
	{
		std::cout << player1->getName() << "'s Strength is now: " <<
			player1->getStrength() << std::endl;
	}
	else
	{
		std::cout << "\n *********************** \n" 
			<< player1->getName() << " died. " <<
			player2->getName() << " (Team Two) wins! \n ";
		std::cout << " *********************** \n";
		roundWinner = 2;
	}
}

/*********************************************************************
*					Game::playGame()
* This function implements the gameplay until one character dies.
*********************************************************************/

void Game::playGame()
{
	while (teamOne.getfrontNode() != nullptr && teamTwo.getfrontNode() != nullptr)
	{
		player1 = teamOne.getFront();
		player2 = teamTwo.getFront();

		std::cout << "Current score: " << std::endl;
		std::cout << std::setw(10) << "Team One: " << teamoneScore <<
			" Team Two: " << teamtwoScore << std::endl;
		while (player1->getStrength() > 0 && player2->getStrength() > 0)
		{
			playeroneAttacks();
			if (player2->getStrength() > 0)
			{
				playertwoAttacks();
			}
		}
		if (roundWinner == 1)
		{
			teamOne.rotateBack(player1);
			teamTwo.removeFront();
			teamOne.removeFront();
			teamoneScore += 5;
		}
		else
		{
			teamTwo.rotateBack(player2);
			teamOne.removeFront();
			teamTwo.removeFront();
			teamtwoScore += 5;
		}
	}
}

/*********************************************************************
*					Game::teamSelect()
* This function adds a character to the queue based on the team
*********************************************************************/

void Game::teamSelect(int playerChoice, int& teamNumber, std::string userName)
{
	if (teamNumber == 1)
	{
		teamOne.addBack(playerChoice, userName);
	}
	else
	{
		teamTwo.addBack(playerChoice, userName);
	}
}	


/*********************************************************************
*					Game::teamoneInfo()
* This function returns the information for the attacker
*********************************************************************/

void Game::getPlayerInfo()
{
	teamOne.printQueue();
	std::cout << std::endl;
	teamTwo.printQueue();
}