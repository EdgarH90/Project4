/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the playGame class.
** 
*******************************************************************************/
#ifndef PLAYGAME_HPP
#define PLAYGAME_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>
#include <vector>
#include "Character.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "teamQueue.hpp"

class Game
{
private:
	int roundWinner = 0;
	int damage = 0;
	int teamoneScore = 0;
	int teamtwoScore = 0;
	teamQueue teamOne;
	teamQueue teamTwo;
	teamQueue loserList;
	std::shared_ptr<Character> player1;
	std::shared_ptr<Character> player2;
public:
	Game();
	~Game();
	void playeroneAttacks();
	void playertwoAttacks();
	void playGame();
	void teamSelect(int playerChoice, int& teamNumber, std::string userName);
	void getloserInfo();
};

#endif
