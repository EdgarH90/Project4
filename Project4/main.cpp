/*******************************************************************************************
** Author: Edgar Hernandez
** Creation Date: 11/23/2019
** Description: This program contains the implementation of a fantasy combat game using 2 teams
** of fighters to run a tournament.
********************************************************************************************/
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include <memory>
#include "inputValidation.hpp"
#include "Game.hpp"
#include "menu.hpp"



int main()
{
	//Uses the current time to generate a random seed for each roll
	//Downcast as unsigned int to convert to 32-bit integer
	srand((unsigned int)time(NULL));

	//Game fantasyGame;
	//menu(&fantasyGame);

	Game fantasyTourney;
	menu(&fantasyTourney);

	fantasyTourney.getPlayerInfo();

	return 0;
}