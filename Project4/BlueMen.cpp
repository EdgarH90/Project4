/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the BlueMen class.
** This is class is derived from the Character class. It contains five
** functions that override the virtual functions in the base class.
*******************************************************************************/
#include "BlueMen.hpp"


/*********************************************************************
*					BlueMen::BlueMen()
* This is the default constructor that intializes the attributes for the
* BlueMen character
*********************************************************************/
BlueMen::BlueMen()
{
	name = "Blue Men";
	armorPoints = 3;
	strengthPoints = 12;
	for (int i = 0; i < 3; i++)
	{
		charDie[i].setSides(6);
	}
}

/*********************************************************************
*					BlueMen::defense()
* This function contains the defense function for BlueMen. It simulates
* the roll of 2 ten-sided dice and displays the damage information.
*********************************************************************/
int BlueMen::attack()
{
	charDie[0].setSides(10);
	charDie[1].setSides(10);
	int firstDie = charDie[0].rollDie();
	int secondDie = charDie[1].rollDie();
	attackPoints = (firstDie+secondDie);
	std::cout << "\n" << "Blue Men's attack roll: " << firstDie << "+" << secondDie
		<< std::endl;

	return attackPoints;
}


/*********************************************************************
*					BlueMen::defense()
* This function contains the defense function for Blue Men. It simulates
* the roll of 3 six-sided dice and displays the damage information.
* It also contains the implementation of the "Mob" special ability.
*********************************************************************/
void BlueMen::defense(int attackIn)
{
	int damage = attackIn;

	//Reset dice and defence points
	for (int i = 0; i < 3; i++)
	{
		charDie[i].setSides(6);
	}
	defensePoints = 0;

	//Remove one die for every four points of damage taken
	std::cout << "Blue Men's defense roll: ";
	int roll = 0;
	if (strengthPoints <= 8)
	{
		if (strengthPoints <= 4)
		{
			defensePoints = charDie[0].rollDie();
			std::cout << defensePoints << std::endl;
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				roll = charDie[i].rollDie();
				std::cout << roll;
				if (i < 1)
				{
					std::cout << "+";
				}
				defensePoints += roll;
			}
			std::cout << "\n";
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			roll = charDie[i].rollDie();
			std::cout << roll;
			if (i < 2)
			{
				std::cout << "+";
			}
			defensePoints += roll;
		}
		std::cout << "\n";
	}
	damage = (attackIn - defensePoints - armorPoints);

	//Make sure damage is not negative
	if (damage < 0)
	{
		damage = 0;
	}

	strengthPoints -= damage;

	std::cout << "Total damage inflicted: " << attackIn << "-" <<
		defensePoints << "-" << armorPoints << " = " << damage << std::endl;
}


/*********************************************************************
*					BlueMen::getName()
* This function returns the name of the character.
*********************************************************************/
std::string BlueMen::getName()
{
	return name;
}


/*********************************************************************
*					BlueMen::getArmor()
* This function returns the armor of the character.
*********************************************************************/
int BlueMen::getArmor()
{
	return armorPoints;
}

/*********************************************************************
*					BlueMen::getStrength()
* This function returns the strength of the character.
*********************************************************************/
int BlueMen::getStrength()
{
	return strengthPoints;
}

/*********************************************************************
*					BlueMen::setName()
* This function returns the name of the character.
*********************************************************************/
void BlueMen::setName(std::string userName)
{
	name = userName;
}