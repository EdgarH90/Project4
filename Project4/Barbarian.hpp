/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the Barbarian class.
** This is class is derived from the Character class. It contains five
** functions that override the virtual functions in the base class.
*******************************************************************************/
#include "Character.hpp"
#include "die.hpp"
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian :
	public Character
{
private:
	Die charDie;
public:
	Barbarian();
	virtual ~Barbarian() {};
	int attack();
	void defense(int attackIn);
	std::string getName();
	int getArmor();
	int getStrength();
};

#endif