/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the Character class.
** This is an abstract base class that contains protected members for the attack,
** strenght, armor, defense and characteristics. It contains two pure virtual 
** attack and defense functions to be overriden by the derived classes.
*******************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <memory>

class Character
{
protected:
	int attackPoints = 0;
	int strengthPoints = 0;
	int armorPoints = 0;
	int defensePoints = 0;
	std::string name = "";
public:
	virtual int attack()=0;
	virtual void defense(int attackln)=0;
	virtual std::string getName()=0;
	virtual ~Character() = 0;
	virtual int getArmor() { return armorPoints; };
	virtual int getStrength() { return strengthPoints; };
	virtual void setName(std::string userName);
	virtual void recoverStrength();
};

#endif
