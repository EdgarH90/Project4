/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the Barbarian class.
** This is class is derived from the Character class. It contains five
** functions that override the virtual functions in the base class.
*******************************************************************************/
#include "Barbarian.hpp"


/*********************************************************************
*					Barbarian::Barbarian()
* This is the default constructor that intializes the attributes for the
* Barbarian character
*********************************************************************/
Barbarian::Barbarian()
{
	name = "Barbarian";
	armorPoints = 0;
	strengthPoints = 12;
}

/*********************************************************************
*					Barbarian::attack()
* This function contains the attack function for Barbarian. It simulates
* the roll of 2 six-sided dice and returns the value of the attack points
*********************************************************************/
int Barbarian::attack()
{
	int firstDie = charDie.rollDie();
	int secondDie = charDie.rollDie();
	attackPoints = (firstDie + secondDie);
	std::cout << "\n" << "Barbarian's attack roll: " << firstDie << "+" << secondDie
		<< std::endl;
	return attackPoints;
}

/*********************************************************************
*					Barbarian::defense()
* This function contains the defense function for Barbarian. It simulates
* the roll of 2 six-sided dice and displays the damage information.
*********************************************************************/
void Barbarian::defense(int attackIn)
{
	int damage = 0;
	int firstDie = charDie.rollDie();
	int secondDie = charDie.rollDie();
	defensePoints = (firstDie + secondDie);
	std::cout << "\n" << "Barbarian's defense roll: " << firstDie << "+" << secondDie
		<< std::endl;
	damage = (attackIn - defensePoints - armorPoints);
	//Make sure damage is not negative
	if (damage < 0)
	{
		damage = 0;
	}
	std::cout << "Total damage inflicted: " << attackIn << "-" <<
		defensePoints << "-" << armorPoints << " = " << damage << std::endl;

	strengthPoints -= damage;
}

/*********************************************************************
*					Barbarian::getName()
* This function returns the name of the character.
*********************************************************************/
std::string Barbarian::getName()
{
	return name;
}

/*********************************************************************
*					Barbarian::getArmor()
* This function returns the armor of the character.
*********************************************************************/
int Barbarian::getArmor()
{
	return armorPoints;
}

/*********************************************************************
*					Barbarian::getStrength()
* This function returns the strength of the character.
*********************************************************************/
int Barbarian::getStrength()
{
	return strengthPoints;
}

/*********************************************************************
*					Barbarian::setName()
* This function returns the name of the character.
*********************************************************************/
void Barbarian::setName(std::string userName)
{
	name = userName;
}