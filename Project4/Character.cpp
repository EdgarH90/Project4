/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the Character class.
** This is an abstract base class that contains protected members for the attack,
** strenght, armor, defense and characteristics. It contains two pure virtual
** attack and defense functions to be overriden by the derived classes.
*******************************************************************************/
#include "Character.hpp"


//Pure virtual destructor
Character::~Character() {}

/*********************************************************************
*					Character::setName()
* This function sets the name of the character by taking in the user's
* string input as a parameter.
*********************************************************************/
void Character::setName(std::string userName)
{
	name = userName;
}

/*********************************************************************
*					Character::recoverStrength()
* This function recovers the strength of a winning character by 20%.
*********************************************************************/
void Character::recoverStrength()
{
	if (strengthPoints < 12)
	{
		strengthPoints += (strengthPoints * .2);
	}
}