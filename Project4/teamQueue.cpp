/*******************************************************************************
** Author:       Edgar Hernandez
** Date:         11/15/2019
** Description:  This program contains the specification for the teamQueue class.
** It contains a pointer to the first QueueNode object as a member variable. It
** also contains five functions functions for teamQueue operations - check to see if
** teamQueue is empty, add value to back of teamQueue, get value at front, remove the value
** at front, and print teamQueue. An additional function is added to insert value at front
*******************************************************************************/
#include "teamQueue.hpp"



/*********************************************************************
*					teamQueue::teamQueue()
* This is the default constructor for the teamQueue. It initializes the value
* for the head to a nullptr.
*********************************************************************/
teamQueue::teamQueue()
{
	head = nullptr;
}

/*********************************************************************
*					teamQueue::~teamQueue()
* This is the default destructor for the teamQueue. It contains a garbage
* collector that deallocates all of the memory used by the list.
*********************************************************************/
teamQueue::~teamQueue()
{
	//Break the link at the back of list
	if (head != nullptr)
	{
		head->prev->next = nullptr;
	}
	//Start deallocating memory at the head of the list
	QueueNode* garbage = head;
	while (garbage != nullptr)
	{
		head = head->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = head;
	}
}

/*********************************************************************
*					teamQueue::getFront()
* This function prints the value at the head of the list.
*********************************************************************/
std::shared_ptr<Character> teamQueue::getFront()
{
	return head->playerChar;
}

/*********************************************************************
*					teamQueue::isEmpty()
* This function checks to see if the teamQueue is empty.
*********************************************************************/
bool teamQueue::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
*					teamQueue::addBack()
* This function adds a new node at the back of the list. It takes in a
* character from the user to be used as the value.
*********************************************************************/
void teamQueue::addBack(int& playerChoice, std::string userName)
{
	QueueNode* nodePtr = head;
	if (isEmpty())
	{
		//If list is empty, allocate a new node to the head and 
		//have previous and next both point to head
		head = new QueueNode();
		selectChar(playerChoice, head, userName);
		head->prev = head;
		head->next = head;
	}
	else
	{
		if (head->next == head)
		{
			//This function adds a node when the only other node is the
			//head.
			nodePtr = new QueueNode();
			selectChar(playerChoice, nodePtr, userName);
			//Both the previous and next of new node point to head
			nodePtr->next = head;
			nodePtr->prev = head;
			//Change head pointers to make sure the link is circular
			head->prev = nodePtr;
			head->next = nodePtr;
		}
		else
		{
			nodePtr = new QueueNode();
			selectChar(playerChoice, nodePtr, userName);
			//Latest node to be added always has next point to head
			nodePtr->next = head;
			//Previous points to the current last node
			nodePtr->prev = head->prev;
			//Sets current last node to second from end
			head->prev->next = nodePtr;
			//Sets new node to last node
			head->prev = nodePtr;
		}
	}
}

/*********************************************************************
*					teamQueue::removeFront()
* This function deletes the first value in the list. It uses a node
* pointer to keep track of the head.
*********************************************************************/
void teamQueue::removeFront()
{
	//Hold location of head until operations are complete
	QueueNode* nodePtr = head;
	if (isEmpty())
	{
		std::cout << "Your team is empty." << std::endl;
	}
	else
	{
		if (head->next == head)
		{
			//If only one value in teamQueue, set head to null
			head = nullptr;
			delete nodePtr;
		}
		else
		{
			//Otherwise, change head pointers and delete
			//the current head
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
			delete nodePtr;
		}
	}
}

/*********************************************************************
*					teamQueue::printQueue()
* This function traverses the list beginning with the first value. It
* first checks that the list is not empty.
*********************************************************************/
void teamQueue::printQueue()
{
	QueueNode* nodePtr = head;

	//If head is not null, print head value
	if (nodePtr != nullptr)
	{
		std::cout << " \n The losers are: " << std::endl;
		std::cout << nodePtr->playerChar->getName() << "  ";

		//Loop if there is more than one value in the teamQueue
		while (nodePtr->next != head)
		{
			nodePtr = nodePtr->next;
			std::cout << nodePtr->playerChar->getName() << "  ";
		}
	}
	else
	{
		std::cout << "The loser list is empty." << std::endl;
	}
	std::cout << "\n" << std::endl;
}


/*********************************************************************
*					teamQueue::selectChar()
* This function has the user select the character to be created by taking
* in the player number and the player's choice as integer parameters.
*********************************************************************/

void teamQueue::selectChar(int playerChoice, QueueNode* nodePtr, std::string userName)
{
	//Create a new character based on the player selection

	if (playerChoice == 1)
	{
		nodePtr->playerChar = std::make_shared<HarryPotter>();
	}
	else if (playerChoice == 2)
	{
		nodePtr->playerChar = std::make_shared<Vampire>();
	}
	else if (playerChoice == 3)
	{
		nodePtr->playerChar = std::make_shared<BlueMen>();
	}
	else if (playerChoice == 4)
	{
		nodePtr->playerChar = std::make_shared<Barbarian>();
	}
	else
	{
		nodePtr->playerChar = std::make_shared<Medusa>();
	}
	nodePtr->playerChar->setName(userName);
}

/*********************************************************************
*					teamQueue::getfrontInformation()
* This function prints the values of the character at the front of the list
*********************************************************************/
std::string teamQueue::getfrontInformation()
{

	return head->playerChar->getName();
}

/*********************************************************************
*					teamQueue::rotateBack()
* This function adds a new node at the back of the list. It takes in a
* character from the user to be used as the value.
*********************************************************************/
void teamQueue::rotateBack(std::shared_ptr<Character> charIn)
{
	QueueNode* nodePtr = head;
	if (isEmpty())
	{
		//If list is empty, allocate a new node to the head and 
		//have previous and next both point to head
		head = new QueueNode();
		head->playerChar= charIn;
		head->prev = head;
		head->next = head;
	}
	else
	{
		if (head->next == head)
		{
			//This function adds a node when the only other node is the
			//head.
			nodePtr = new QueueNode();
			nodePtr->playerChar = charIn;
			//Both the previous and next of new node point to head
			nodePtr->next = head;
			nodePtr->prev = head;
			//Change head pointers to make sure the link is circular
			head->prev = nodePtr;
			head->next = nodePtr;
		}
		else
		{
			nodePtr = new QueueNode();
			nodePtr->playerChar = charIn;;
			//Latest node to be added always has next point to head
			nodePtr->next = head;
			//Previous points to the current last node
			nodePtr->prev = head->prev;
			//Sets current last node to second from end
			head->prev->next = nodePtr;
			//Sets new node to last node
			head->prev = nodePtr;
		}
	}
}

/*********************************************************************
*					teamQueue::getfrontNode()
* This function prints the value at the head of the list.
*********************************************************************/
QueueNode* teamQueue::getfrontNode()
{
	return head;
}


/*********************************************************************
*					teamQueue::addtoLoser()
* This function adds a new node at the top of the loser list. It takes in a
* character from the user to be used as the value.
*********************************************************************/
void teamQueue::addtoLoser(std::shared_ptr<Character> charIn)
{
	QueueNode* nodePtr = head;
	if (isEmpty())
	{
		//If list is empty, allocate a new node to the head and 
		//have previous and next both point to head
		head = new QueueNode();
		head->playerChar = charIn;
		head->prev = head;
		head->next = head;
	}
	else
	{
		if (head->next == head)
		{
			//This function adds a node when the only other node is the
			//head.
			head = new QueueNode();
			head->playerChar = charIn;
			//Both the previous and next of new node point to head
			nodePtr->next = head;
			nodePtr->prev = head;
			//Change head pointers to make sure the link is circular
			head->prev = nodePtr;
			head->next = nodePtr;
		}
		else
		{
			head = new QueueNode();
			head->playerChar = charIn;;
			//New head points to previous head
			head->next = nodePtr;
			//Previous head points to the current last node
			head->prev = nodePtr->prev;
			//Sets current last node to point to new head
			nodePtr->prev->next = head;
		}
	}
}
