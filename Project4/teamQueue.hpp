/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         11/15/2019
** Description:  This program contains the specification for the queue class.
** It contains a pointer to the first QueueNode object as a member variable. It
** also contains five functions functions for queue operations - check to see if
** queue is empty, add value to back of queue, get value at front, remove the value
** at front, and print queue. An additional function is added to insert value at front
*******************************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#ifndef TEAMQUEUE_HPP
#define TEAMQUEUE_HPP
#include "Character.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "BlueMen.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"


//This struct represents each node
struct QueueNode
{
	std::shared_ptr<Character> playerChar;
	QueueNode* next;
	QueueNode* prev;
};

class teamQueue
{
private:
	QueueNode* head;
public:
	teamQueue();
	~teamQueue();
	bool isEmpty();
	void addBack(int &playerChoice, std::string userName);
	void rotateBack(std::shared_ptr<Character> winningChar);
	void addtoLoser(std::shared_ptr<Character> winningChar);
	std::shared_ptr<Character> getFront();
	QueueNode* getfrontNode();
	void removeFront();
	void printQueue();
	void selectChar(int playerChoice, QueueNode* nodePtr, std::string userName);
	std::string getfrontInformation();
};

#endif