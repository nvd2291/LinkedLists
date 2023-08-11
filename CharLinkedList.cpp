/*
 *  CharLinkedList.cpp
 *  Naveed Naeem
 *  June 12, 2023
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  Contains the public method definitions for the CharLinkedList class
 *
 */

#include <string>
#include <stdexcept>
#include "CharLinkedList.h"

using namespace std;
/*
 * name:      CharLinkedList default constructor
 * purpose:   initialize an empty CharLinkedList
 * arguments: none
 * returns:   none
 * effects:   frontNode = backNode = nulltpr
 */
CharLinkedList::CharLinkedList()
{
    listSize = 0;
    frontNode = nullptr;
    backNode = nullptr;
}

/*
 * name:      CharLinkedList second constructor
 * purpose:   Initialize a CharLinkedList with a single node
 * arguments: char C: Input character in the node to be stored
 * returns:   none
 * effects:   frontNode is allocated on the heap, all Node value initialized
 *            backNode = frontNode.
 */
CharLinkedList::CharLinkedList(char c)
{
    /* Allocate the frontNode on the heap */
    frontNode = new Node(c);
    /* Set backNode = frontNode */
    backNode = frontNode;
    listSize = 1;
}

/*
 * name:      CharLinkedList third constructor
 * purpose:   Initialize a CharLinkedList with a char array and int size.
 * arguments: char array: Input character array to be stored 
 *            in the CharLinkedList
 *            int size: The size of the input character array
 * returns:   none
 * effects:   Constructs a CharLinkedList with each node containing a character
 *            form the char arr in order and the size provided as an input
 */
CharLinkedList::CharLinkedList(char arr[], int size)
{
    frontNode = nullptr;
    backNode = nullptr;
    listSize = 0;

    for (int i = 0; i < size; i++)
    {
        pushAtBack(arr[i]);
    }

    listSize = size;
}

/*
 * name:      CharLinkedList copy constructor
 * purpose:   Initialize a CharLinkedList with same values as the input
 *            CharLinkedList
 * arguments: const CharLinkedList &other: Reference to the linked list to
 *            be copied
 * returns:   none
 * effects:   Copys the values from the input LinkedList to this LinkedList
 */

CharLinkedList::CharLinkedList(const CharLinkedList &other)
{
    /* Initialize and empty list */
    frontNode = nullptr;
    backNode = nullptr;
    listSize = 0;

    if (other.isEmpty())
    {
        return;
    }

    int otherSize = other.listSize;

    for (int i = 0; i < otherSize; i++)
    {
        pushAtBack(other.elementAt(i));
    }

    listSize = other.size();
}

/*
 * name:      CharLinkedList Operator Overload Copy Constructor
 * purpose:   Initialize a CharLinkedList with same values as the
 *            CharLinkedList on the right-hand side of the = operator
 * arguments: const CharLinkedList &other: Reference to the linked list to
 *            be copied
 * returns:   none
 * effects:   Copys the values from the LinkedList on the right-hand size of
 *            the = operator to this LinkedList
 */
CharLinkedList &CharLinkedList::operator=(const CharLinkedList &other)
{
    /* Initialize and empty list */
    frontNode = nullptr;
    backNode = nullptr;
    listSize = 0;

    /* If the other is empty use logic from the default constuctor */
    if(other.isEmpty())
    {
        return *this;
    }

    /* If this CharLinkedList isn't empty clear it */
    if(not isEmpty())
    {
        clear();
    }

    for (int i = 0; i < other.listSize; i++)
    {
        pushAtBack(other.elementAt(i));
    }
    listSize = other.listSize;

    return *this;
}

/*
 * name:      CharLinkedList destructor
 * purpose:   Frees all memory associated the CharLinkedList
 * arguments: none
 * returns:   none
 * effects:   frees all memory on the heap for this CharLinkedList
 */
CharLinkedList::~CharLinkedList()
{
    /* Clear has the same effect*/
    /* Only clear the list if it's NOT empty */
    if (isEmpty() == false)
    {
        deleteNodes(frontNode);
    }
    frontNode = nullptr;
    backNode = nullptr;
    listSize = 0;
}

/*
 * name:      size
 * purpose:   Returns the size of the CharLinkedList
 * arguments: none
 * returns:   integer with the number of nodes in the CharLinkedList
 * effects:   None
 */
int CharLinkedList::size() const
{
    return listSize;
}

/*
 * name:      pushAtBack
 * purpose:   Creates a new Node at the end of the linkedList with the
 *            character value provided
 * arguments: char c: Character to add to the linked list
 * returns:   none
 * effects:   Adds a new node at the end of the list and updates
 *            the other nodes accordingly
 */
void CharLinkedList::pushAtBack(char c)
{
    /* If the list is empty make this node the front and back node*/
    if(isEmpty())
    {
        /* Default Node constructor takes in a character */
        /* Sets prevNode and nextNode to nullptr */
        Node *newNode = new Node(c);
        frontNode = newNode;
        backNode = newNode;
        listSize = 1;
    }
    else
    {
        /* Allocate a new node with the prevNode pointer = backNode*/
        /* The newNode's nextNode = nullptr*/
        Node *newNode = new Node(c, backNode, nullptr);        
        /* The previous node is the old backNode*/
        /* Set the backNode's next node to the newNode */
        
        backNode->setNextNode(newNode);
        /* Set the backNode = newNode*/
        backNode = newNode;
        listSize++;
    }
}

/*
 * name:      pushAtFront
 * purpose:   Creates a new Node at the front of the linkedList with the
 *            character value provided and updates the list
 * arguments: char c: Character to add to the linked list
 * returns:   none
 * effects:   Adds a new node at the front of the list and updates
 *            the other nodes accordingly
 */
void CharLinkedList::pushAtFront(char c)
{
    /* If the list is empty make this node the front and back node*/
    if(isEmpty())
    {
        Node *newNode = new Node(c);
        frontNode = newNode;
        backNode = newNode;
        listSize = 1;
    }
    else
    {
        /* Allocate a new node with the prev pointer = backNode*/
        /* The newNode's nextNode = nullptr*/
        Node *newNode = new Node(c, nullptr, frontNode); 

        /* Set the frontNode's prevNode to the newNode */
        frontNode->setPrevNode(newNode);
        /* Set the frontNode = newNode*/
        frontNode = newNode;
        listSize++;
    }
}

/*
 * name:      isEmpty()
 * purpose:   Returns a boolean value indicating whether the
 *            the linkedList is empty
 * arguments: none
 * returns:   Bool: true if empty, false if not empty
 * effects:   None
 */
bool CharLinkedList::isEmpty() const
{
    return (frontNode == nullptr);
}

/*
 * name:      first()
 * purpose:   Returns the character of at the front of the linked list
 * arguments: none
 * returns:   Character of the first node
 * effects:   None
 */
char CharLinkedList::first() const
{
    if(isEmpty())
    {
        throw_runtime_error(RUNTIME_ERROR_FIRST);
    }
    else
    {
        return frontNode->getChar();
    }
}

/*
 * name:      last()
 * purpose:   Returns the character of at the back of the linked list
 * arguments: none
 * returns:   Character of the last node
 * effects:   None
 */ 
char CharLinkedList::last() const
{
    if(isEmpty())
    {
        throw_runtime_error(RUNTIME_ERROR_LAST);
    }
    else
    {
        return backNode->getChar();
    }
}

/*
 * name:      popFromBack
 * purpose:   Removes the last node from the linked list
 * arguments: none
 * returns:   none
 * effects:   Removes the last node of the linked list, frees its 
 *            memory from the heap, and updates the list accordingly
 */
void CharLinkedList::popFromBack()
{
    /* Check if the Linked List is empty */
    if (isEmpty())
    {
        throw_runtime_error(RUNTIME_ERROR_POP);
    }

    /* Set nodeToRemove to backNode */
    Node *nodeToRemove = backNode;
    /* Check if frontNode == backNode */
    if(frontNode == backNode)
    {
        frontNode = nullptr;
        backNode = nullptr;
    }
    else
    {
        /* Update backNode to backNode's prevNode */
        backNode = backNode->getPrevNode();
        /* Update backNode's nextNode to nullptr */
        backNode->setNextNode(nullptr);
    }

    /* Decrement the listsize */
    listSize--;

    /* Free the memory for the nodeToRemove (old backNode) */
    delete nodeToRemove;
}

/*
 * name:      popFromFront
 * purpose:   Removes the front node from the linked list
 * arguments: none
 * returns:   none
 * effects:   Removes the front node of the linked list, frees its 
 *            memory from the heap, and updates the list accordingly
 */
void CharLinkedList::popFromFront()
{
    /* Check if the CharLinkedList is empty */
    if (isEmpty())
    {
        throw_runtime_error(RUNTIME_ERROR_POP);
    }

    /* Set nodeToRemove to frontNode */
    Node *nodeToRemove = frontNode;
    /* Check if frontNode == backNode */
    if(frontNode == backNode)
    {
        frontNode = nullptr;
        backNode = nullptr;
    }
    else
    {
        /* Update frontNode to frontNode's nextNode */
        frontNode = frontNode->getNextNode();
        /* Update frontNode's prevNode to nullptr */
        frontNode->setPrevNode(nullptr);
    }

    /* Decrement the listsize */
    listSize--;

    /* Free the memory for the nodeToRemove (old frontNode) */
    delete nodeToRemove;
}

/*
 * name:      clear
 * purpose:   Clears the contents of the linked list and free all
 *            of its memory on the heap
 * arguments: none
 * returns:   none
 * effects:   Frees all the memory of the 
 */
void CharLinkedList::clear()
{
    /* Only clear the list if its NOT empty */
    if (isEmpty() == false)
    {
        deleteNodes(frontNode);
        frontNode = nullptr;
        backNode = nullptr;
        listSize = 0;
    }
}

/*
 * name:      toString()
 * purpose:   Outputs the contents of the CharLinkedList as a string
 * arguments: none
 * returns:   A string in the following format:
 *            "[CharLinkedList of size <listSize> <<LinkedListString>>]""
 * effects:   None
 */
string CharLinkedList::toString() const
{
    if (isEmpty())
    {
        return "[CharLinkedList of size 0 <<>>]";
    }

    /* Starter String based on the assignment prompt */
    string outputStr = "[CharLinkedList of size " +
                    to_string(listSize) +
                    " <<";
    
    /* Start at the frontNode and move towards to end of the list */
    Node *currentNode = frontNode;
    while(currentNode != nullptr)
    {
        outputStr += currentNode->getChar();
        currentNode = currentNode->getNextNode();
    }

    outputStr += ">>]";
    return outputStr;
}

/*
 * name:      toReverseString()
 * purpose:   Outputs the contents of the CharLinkedList as a string 
 *            in reverse
 * arguments: none
 * returns:   A string in the following format:
 *            "[CharLinkedList of size <listSize> <<gnirtS>>]""
 * effects:   None
 */
string CharLinkedList::toReverseString() const
{
    /* Starter String based on the assignment prompt */
    string outputStr = "[CharLinkedList of size " +
                    to_string(listSize) +
                    " <<";

    /* Start at the backNode and move towards to front of the list */
    Node *currentNode = backNode;
    while(currentNode != nullptr)
    {
        outputStr += currentNode->getChar();
        currentNode = currentNode->getPrevNode();
    }

    outputStr += ">>]";
    return outputStr;
}

/*
 * name:      removeAt()
 * purpose:   Removes the node at the index provided as input
 * arguments: int index: The index of the node to remove
 * returns:   None
 * effects:   None
 */
void CharLinkedList::removeAt(int index)
{
    /* If the CharLinkedList is empty throw a range error*/
    /* If index is negative or greater than the (listSize - 1) */
    if ( isEmpty() || (index < 0) || (index > (listSize - 1)) )
    {
        throw_range_error(index, ')');
    }

    if ( index == 0 )
    {
        popFromFront();
        return;
    }

    if ( index == (listSize - 1))
    {
        popFromBack();
        return;
    }

    Node *currentNode = frontNode;
    int currentNodeIndex = 0;

    while( currentNode != nullptr && currentNodeIndex != index)
    {
        currentNode = currentNode->getNextNode();
        currentNodeIndex++;
    }

    if(currentNode != nullptr)
    {
        /* Get the prevNode of the current Node */
        Node *prevNode = currentNode->getPrevNode();
        /* Get the nextNode of the current Node */
        Node *nextNode = currentNode->getNextNode();

        /* Link the nodes backtogether */
        prevNode->setNextNode(nextNode);
        nextNode->setPrevNode(prevNode);

        delete currentNode;

        listSize--;
    }
}

/*
 * name:      replaceAt()
 * purpose:   Replace the char value of node with the provided index
 * arguments: int index: The index of the node to replace
 *            char c: The character to replace
 * returns:   None
 * effects:   Changes the character of the node at the given index
 *            to the input char.
 */
void CharLinkedList::replaceAt(char c, int index)
{
    /* If the CharLinkedList is empty throw a range error*/
    /* If index is negative or greater than the (listSize - 1) */
    if ( isEmpty() || (index < 0) || (index > (listSize - 1)) )
    {
        throw_range_error(index, ')');
    }

    return setElement(frontNode, index, c);
}

/*
 * name:      elementAt()
 * purpose:   Gets the char value at the node with the corresponding index
 * arguments: int index: The index of the node 
 * returns:   The character stored at the node at the input index
 * effects:   None
 */
char CharLinkedList::elementAt(int index) const
{
    /* If the CharLinkedList is empty throw a range error*/
    /* If index is negative or greater than the (listSize - 1) */
    if ( isEmpty() || (index < 0) || (index > (listSize - 1)) )
    {
        throw_range_error(index, ')');
    }

    return getElement(frontNode, index);
}

/*
 * name:      insertAt()
 * purpose:   Inserts a new node at the desired index with the provided 
 *            input value
 * arguments: int index: The index of the node to insert
 *            char c: The character to insert
 * returns:   None
 * effects:   None
 */
void CharLinkedList::insertAt(char c, int index)
{
    /* If the linked list is empty and the index is 0 */
    if(isEmpty() && (index == 0))
    {
        return pushAtBack(c);
    }

    /* Check if the index is out of range */
    if((index < 0) || (index > listSize))
    {
        throw_range_error(index, ']');
    }

    /* If the index is 0 push at the front of non-empty list */
    if (index == 0)
    {
        return pushAtFront(c);
    }

    /* If the index is listSize push at the back of the non-empty list*/
    if(index == listSize)
    {
        return pushAtBack(c);
    }

    Node *currentNode = frontNode;
    int currentNodeIndex = 0;

    /* Loop until the desired node is found */
    while(currentNode != nullptr && currentNodeIndex != index)
    {
        currentNode = currentNode->getNextNode();
        currentNodeIndex++;
    }

    if (currentNode != nullptr)
    {
        /* Allocate the node to insert on the heap */
        Node *newNode = new Node(c);
        /* Get the previous node */
        Node *prevNode = currentNode->getPrevNode();
        /* Set the newNode's nextNode to the current Node */
        newNode->setNextNode(currentNode);
        /* Set the newNode's prevNode to the previous Node */
        newNode->setPrevNode(prevNode);
        /* Set the prevNode's nextNode to the newNode */
        prevNode->setNextNode(newNode);
        /* Set the currentNode's prevNode to the newNode */
        currentNode->setPrevNode(newNode);
        listSize++;
    }
}

/*
 * name:      insertInOrder()
 * purpose:   Inserts a new node in ASCII order
 *            input value
 * arguments: char c: The char value to insert
 * returns:   None
 * effects:   Inserts a new node containing the input character
 *            in ASCII order
 */
void CharLinkedList::insertInOrder(char c)
{
    /* If the linked list is empty just push at back*/
    if(isEmpty())
    {
        return pushAtBack(c);
    }

    /* Copy the pointer to the front node */
    Node *currentNode = frontNode;
    Node *prevNode = nullptr;

    /* Loop through the list until the currentChar is greater than c */
    while ((currentNode != nullptr) && (currentNode->getChar() < c))
    {
        prevNode = currentNode;
        currentNode = currentNode->getNextNode();
    }

    /* Allocate a new Node on the heap */
    Node *newNode = new Node(c);

    /* If the current Node is nullptr then insert AFTER the backNode */
    if(currentNode == nullptr)
    {
        /* Set the next node of the back Node to the new mode*/
        backNode->setNextNode(newNode);
        /* Set the prevNode of the newNode to the backNode */
        newNode->setPrevNode(backNode);
        /* Set the backNode = newNode */
        backNode = newNode;
    }
    /* Else insert before the current node */
    else
    {
        /* Set the newNode's next node to the current node */
        newNode->setNextNode(currentNode);
        /* Set the newNode's  previous node to prevNode */
        newNode->setPrevNode(prevNode);
        /* Set the currentNode's previous value to the newNode */
        currentNode->setPrevNode(newNode);

        /* Check if the previous node is the nullptr */
        if(prevNode == nullptr)
        {
            /* Insert at the front if it is */
            frontNode = newNode;
        }
        else
        {
            prevNode->setNextNode(newNode);
        }

    }

    /* Increment the listSize */
    listSize++;
}

/*
 * name:      concatenate()
 * purpose:   Copy the contents of the input CharLinkedList to this linked list
 * arguments: CharLinkedList *other: pointer to another CharLinkedList instance
 * returns:   None
 * effects:   Adds the elements from the input CharLinkedList to the end of
 *            this linked list in the same order as the input linked
 */
void CharLinkedList::concatenate(CharLinkedList *other)
{
    /* If ther other CharLinkedList is empty do nothing.*/
    if (other->isEmpty())
    {
        return;
    }

    int otherSize = other->size();
    /* If the otherList isn't empty, 
    *  loop through it and push each element at the back */
    for (int i = 0; i < otherSize; i++)
    {
        char temp = other->elementAt(i);
        pushAtBack(temp);
    }
}
