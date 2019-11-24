/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         10/19/2019
** Description:  This program contains the specification for the Die class.
** The class has a private member for the number of die sides and a public member
** function that simulates a die roll by returning a value between 1 and the number of sides.
*******************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
protected:
	int numSides = 0; // Number of die sides
public:
	Die();
	Die(int numSidesIn);
	virtual ~Die() {};
	virtual int rollDie(); //Simulates a die roll
	void setSides(int sideIn); //Sets the die's number of sides
	int getSides(); //Returns the die's number of sides
};

class loadedDie : public Die
{
public:
	loadedDie() : Die() {}; //Inherits the parent's constructor
	loadedDie(int numSidesIn) : Die(numSidesIn) {};
	virtual ~loadedDie() {};
	int rollDie(); //Simulates a die roll biased for higher numbers
};
#endif