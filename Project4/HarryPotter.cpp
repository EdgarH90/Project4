/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the HarryPotter class.
** This is class is derived from the Character class. It contains two attack and
** defense functions that override the virtual functions in the base class.
*******************************************************************************/
#include "HarryPotter.hpp"


/*********************************************************************
*					HarryPotter::HarryPotter()
* This is the default constructor that intializes the attributes for the
* HarryPotter character
*********************************************************************/
HarryPotter::HarryPotter()
{
	name = "Harry Potter";
	livesRemaining = 1;
	armorPoints = 0;
	strengthPoints = 10;
	charDie.setSides(6);
}

/*********************************************************************
*					HarryPotter::attack()
* This function contains the attack function for Harry. It simulates
* the roll of 2 six-sided dice and returns the value of the attack points
*********************************************************************/
int HarryPotter::attack()
{
	int firstDie = charDie.rollDie();
	int secondDie = charDie.rollDie();
	attackPoints = (firstDie+secondDie);
	std::cout <<"\n" << "Harry's attack roll: " << firstDie << "+" << secondDie
		<< std::endl;
	return attackPoints;
}


/*********************************************************************
*					HarryPotter::defense()
* This function contains the defense function for Harry. It simulates
* the roll of 1 six-sided die, displays the damage information, and
* returns an integer for the damage. It also contains the implementation
* for the Hogwarts special ability.
*********************************************************************/
void HarryPotter::defense(int attackIn)
{
	int damage = 0;
	int firstDie = charDie.rollDie();
	int secondDie = charDie.rollDie();
	defensePoints = (firstDie + secondDie);
	std::cout << "\n" << "Harry's defense roll: " << firstDie << "+" << secondDie
		<< std::endl;
	damage = (attackIn - defensePoints - armorPoints);
	//Make sure damage is not negative
	if (damage < 0)
	{
		damage = 0;
	}

	strengthPoints -= damage;

	std::cout << "Total damage inflicted: " << attackIn << "-" <<
		defensePoints << "-" << armorPoints << " = " << damage << std::endl;

	//Check if Harry has any lives remaining if strength falls to 0 or below
	if (livesRemaining == 1 && strengthPoints <= 0)
	{
		std::cout << "Harry was killed by his opponent, but successfully used" <<
			" Hogwarts to come back to life!" << std::endl;
		strengthPoints = 20;
		livesRemaining = 0;
	}
}


/*********************************************************************
*					HarryPotter::getName()
* This function returns the name of the character.
*********************************************************************/
std::string HarryPotter::getName()
{
	return name;
}


/*********************************************************************
*					HarryPotter::getArmor()
* This function returns the armor of the character.
*********************************************************************/
int HarryPotter::getArmor()
{
	return armorPoints;
}

/*********************************************************************
*					HarryPotter::getStrength()
* This function returns the strength of the character.
*********************************************************************/
int HarryPotter::getStrength()
{
	return strengthPoints;
}

/*********************************************************************
*					HarryPotter::recoverStrength()
* This function recovers the strength of a winning character by 20%.
*********************************************************************/
void HarryPotter::recoverStrength()
{
	if (strengthPoints < 20)
	{
		strengthPoints += (strengthPoints * .2);
	}
}