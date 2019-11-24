/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the implementation for the Die class.
** The class has a private member for the number of die sides and a public member
** function that simulates a die roll by returning a value between 1 and the number of sides.
*******************************************************************************/
#include <string>
#include <iostream>
#include <time.h>
#include "die.hpp"


/*********************************************************************
*					Die::Die(int)
* This is the default constructor that initializes the Die object with
* two sides.
*********************************************************************/

Die::Die()
{
	numSides = 2;
}
/*********************************************************************
*					Die::Die(int)
* This  constructor initializes the Die object by
* taking in the user input ints for number of sides.
*********************************************************************/

Die::Die(int numSidesIn)
{
	numSides = numSidesIn;
}


/*********************************************************************
*					int Die::setSides()
* This function takes in an int parameter to set the number of sides for
* the die.
*********************************************************************/

void Die::setSides(int sideIn)
{
	numSides = sideIn;
}
/*********************************************************************
*					int Die::rollDie()
* This function simulates a roll of the die using the rand function.
*********************************************************************/

int Die::rollDie()
{
	return rand() % (numSides) + 1;
}

/*********************************************************************
*					int loadedDie::rollDie()
* This function simulates a roll of the loaded die using the rand function
* and a bias for higher numbers. The biased num integer ensures that 
* 80% of the time the roll will generate a number in the 50th percentile
*********************************************************************/

int loadedDie::rollDie()
{
	//Random number between 0 and 1.00
	double biasedNum = ((double)rand() / (double)RAND_MAX);

	if (numSides == 1)
	{
		return 1;
	}
	else if (biasedNum < .8)
	{
		return rand() % (numSides - (numSides/2)+ 1) + (numSides / 2); 
	}
	else
	{
		return rand() % (numSides - 2) + 1;
	}
}

/*********************************************************************
*					int Die::getSides()
* This function simulates a roll of the die using the rand function.
*********************************************************************/

int Die::getSides()
{
	return numSides;
}