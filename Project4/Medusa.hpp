/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the Medusa class.
** This is class is derived from the Character class. It contains five
** functions that override the virtual functions in the base class.
*******************************************************************************/
#include "Character.hpp"
#include "die.hpp"
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

class Medusa :
	public Character
{
private:
	Die charDie;
public:
	Medusa();
	virtual ~Medusa() {};
	int attack();
	void defense(int attackIn);
	std::string getName();
	int getArmor();
	int getStrength();
	void setName(std::string userName);
};

#endif

