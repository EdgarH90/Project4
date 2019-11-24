/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         9/29/2019
** Description:  This program contains the implementation for the menu function.
** The menu takes in a pointer to a game object as a parameter. The menu then prints
** out all of the instructions for the user and plays the game.
*******************************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "inputValidation.hpp"
#include "Game.hpp"
#include "teamQueue.hpp"

// The function takes in all user inputs and validates them
void menu()
{
	std::string errorMsg = "Please enter a valid integer";
	int status = 1;
	int userChoice = 0;
	int numofChars = 0;
	std::string playerName = "";


	std::cout << "*** Welcome to my Fantasy Combat Game! ***" << std::endl;
	std::cout << "Please select a number from the options below and press enter: " << std::endl;
	std::cout << "1. Start new game." << std::endl;
	std::cout << "2. Quit program." << std::endl;
	inputValidation(status, errorMsg, 1, 2);

	while (status != 2)
	{
		Game gameIn;
		if (status == 1)
		{
			std::string charNames[5] = { "Harry Potter", "Vampire", "Blue Men", "Barbarian", "Medusa" };

			//Select characters for both teams
			std::cout << "Please select the number of characters per team (max of 3). " << std::endl;
			inputValidation(numofChars, errorMsg, 1, 3);

			//Display list of characters
			std::cout << "Available characters: " << std::endl;
			for (int i = 0; i < 5; i++)
			{
				std::cout << std::setw(10) << i + 1 << ". " << charNames[i];
			}
			std::cout << std::endl<< std::endl;

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < numofChars; j++)
				{
					//Get current team number to pass to function
					int team = i + 1;

					std::cout << "Please select Character number " << j + 1 << " for Team " <<
						i + 1<< ": " << std::endl;
					inputValidation(userChoice, errorMsg, 1, 5);
					std::cout << "What is your character's name? " << std::endl;
					std::getline(std::cin, playerName);
					gameIn.teamSelect(userChoice, team, playerName);
				}
			}
			gameIn.playGame();
		}

		std::cout << "Would you like to play again? " << std::endl;
		std::cout << std::setw(10) << "1. Yes" << std::setw(10) << "2. No" << std::endl;
		inputValidation(userChoice, errorMsg, 1, 2);
		status = userChoice;
	}
	std::cout << "\n *********************** \n" << 
		"Game over. Thanks for playing!!" << std::endl;
	std::cout << " *********************** \n";
}

