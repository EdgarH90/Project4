#include "Game.hpp"



Game::Game()
{
}


Game::~Game()
{
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
	std::cout << "Armor: " << player2->getArmor() << std::setw(15) <<
		"Strength: " << player2->getStrength() << std::endl;

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
		std::cout << "\n**************************** \n"
			<< player2->getName() << " died. " <<
			player1->getName() << " (Team One) wins! \n";
		std::cout << "**************************** \n";
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
	std::cout << player1->getName() << "'s (Team Two Defender) stats: " << std::endl;
	std::cout << "Armor: " << player1->getArmor() << std::setw(15) <<
		"Strength: " << player1->getStrength() << std::endl;

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
		std::cout << "\n**************************** \n" 
			<< player1->getName() << " died. " <<
			player2->getName() << " (Team Two) wins! \n";
		std::cout << "**************************** \n";
		roundWinner = 2;
	}
}

/*********************************************************************
*					Game::playGame()
* This function implements the gameplay until one character dies.
* It uses the attack functions in the game class to simulate the rounds
* for the members at the front of the team queues.
*********************************************************************/

void Game::playGame()
{
	//Loop until one team has no fighters left
	while (teamOne.getfrontNode() != nullptr && teamTwo.getfrontNode() != nullptr)
	{
		player1 = teamOne.getFront();
		player2 = teamTwo.getFront();

		//Display team scores
		std::cout << "Current score: " << std::endl;
		std::cout << std::setw(10) << "Team One: " << teamoneScore <<
			" Team Two: " << teamtwoScore << std::endl;
		//Loop until one character from the current round dies
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
			//Player one wins, recover character strength and move character to back
			player1->recoverStrength();
			teamOne.rotateBack(player1);
			teamOne.removeFront();
			
			//Add loser to back of loser list and remove from team two
			loserList.addtoLoser(player2);
			teamTwo.removeFront();
			//Update team score
			teamoneScore += 5;
		}
		else
		{
			//Player one wins, recover character strength and move character to back
			player2->recoverStrength();
			teamTwo.rotateBack(player2);
			teamTwo.removeFront();

			//Add loser to back of loser list and remove from team one
			loserList.addtoLoser(player1);
			teamOne.removeFront();
			teamtwoScore += 5;
		}
	}
	std::cout << "\n*********************** \n" <<
		"The final score is: \n" << "Team One: "<<
		teamoneScore << " Team Two: " << teamtwoScore << std::endl;
	if (teamoneScore > teamtwoScore)
	{
		std::cout << "Team One Wins!!!" << std::endl;
	}
	else if (teamoneScore < teamtwoScore)
	{
		std::cout << "Team Two Wins!!!" << std::endl;
	}
	else
	{
		std::cout << "The tournament resulted in a tie!!!" << std::endl;
	}
	std::cout << "*********************** \n";
}

/*********************************************************************
*					Game::teamSelect()
* This function adds a character to the queue based on the team. It takes
* in the user's character choice, team number, and name choice as parameters.
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
*					Game::getloserInfo()
* This function returns the information for the attacker
*********************************************************************/

void Game::getloserInfo()
{
	loserList.printQueue();
}