/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the HarryPotter class.
** This is class is derived from the Character class. It contains five
** functions that override the virtual functions in the base class.
*******************************************************************************/
#include "Character.hpp"
#include "die.hpp"
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter :
	public Character
{
private:
	Die charDie;
	int livesRemaining;
public:
	HarryPotter();
	virtual ~HarryPotter() {};
	int attack();
	void defense(int attackIn);
	std::string getName();
	int getArmor();
	int getStrength();
	void recoverStrength();
};

#endif

