/*
 *  CharLinkedList.h
 *  Naveed Naeem
 *  June 12, 2023
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  Contains the class definition for the CharLinkedList class
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <string>
#include <stdexcept>

using namespace std;

/* Error Message variables and strings*/
static const int RUNTIME_ERROR_FIRST = 0;
static const int RUNTIME_ERROR_LAST = 1;
static const int RUNTIME_ERROR_POP = 2;
static const int RUNTIME_ERROR_NEGATIVE_SIZE = 3;

static const string RUNTIME_ERROR_FIRST_STR = 
                    "cannot get first of empty LinkedList";
static const string RUNTIME_ERROR_LAST_STR =
                    "cannot get last of empty LinkedList";
static const string RUNTIME_ERROR_POP_STR =
                    "cannot pop from empty LinkedList";

class CharLinkedList
{
    public:

        // Constructor Method Declarations
        CharLinkedList();
        CharLinkedList(char c);
        CharLinkedList(char arr[], int size);
        // Copy Constructor Method Declarations
        CharLinkedList(const CharLinkedList &other);
        CharLinkedList& operator=(const CharLinkedList& other);
        // Destructor Method Declaration
        ~CharLinkedList();

        // Public Method Declaration
        bool isEmpty() const;
        void clear();
        int size() const;
        char first() const;
        char last() const;
        char elementAt(int index) const;
        string toString() const;
        string toReverseString() const;
        void pushAtBack(char c);
        void pushAtFront(char c);
        void insertAt(char c, int index);
        void insertInOrder(char c);

        void popFromFront();
        void popFromBack();
        void removeAt(int index);
        void replaceAt(char c, int index);
        void concatenate(CharLinkedList *other);

    private:

        class Node
        {
            public:
                Node(char c)
                {
                    this->thisChar = c;
                    this->nextNode = nullptr;
                    this->prevNode = nullptr;
                }

                Node(char c, Node *prev, Node *next)
                {
                    this->thisChar = c;
                    this->nextNode = next;
                    this->prevNode = prev;
                }

                void setNextNode(Node* nodePtr)
                {
                    nextNode = nodePtr;
                }

                void setPrevNode(Node* nodePtr)
                {
                    prevNode = nodePtr;
                }

                void setChar(char c)
                {
                    thisChar = c;
                }

                Node* getNextNode() const
                {
                    return nextNode;
                }

                Node* getPrevNode() const
                {
                    return prevNode;
                }

                char getChar() const
                {
                    return thisChar;
                }

            private:
                char thisChar;
                Node *nextNode;
                Node *prevNode;
        };

        /* Pointer to the node at the front of the CharLinkedList */
        Node *frontNode;
        /* Pointer to the node at the back of the CharLinkedList */
        Node *backNode;
        /* Size of the linkedList */
        int listSize;

        /* Private Helper Functions */

        /* Throws a range error with message taking inputs index and endChar */
        void throw_range_error(int index, char endChar) const
        {
            throw range_error("index (" + 
                       to_string(index) +
                  ") not in range [0.." + 
                      to_string(size()) + endChar);
        }

        /* Throw a runtime error based on the mode selected */
        void throw_runtime_error(const int mode) const
        {
            switch(mode)
            {
                case RUNTIME_ERROR_FIRST:
                {
                    throw runtime_error(RUNTIME_ERROR_FIRST_STR);
                    break;
                }
                case RUNTIME_ERROR_LAST:
                {
                    throw runtime_error(RUNTIME_ERROR_LAST_STR);
                    break;
                }
                case RUNTIME_ERROR_POP:
                {
                    throw runtime_error(RUNTIME_ERROR_POP_STR);
                    break;
                }
                default:
                {
                    throw runtime_error("generic runtime error");
                    break;
                }
            }

        }

        /* Recursive function for deleting all nodes in the linked list*/
        void deleteNodes(Node *currentNode)
        {
            /* Base Case */
            if( currentNode == nullptr)
            {
                return;
            }

            deleteNodes(currentNode->getNextNode());
            delete currentNode;
        }

        /* Recursive function for getting the value at the desired index */
        char getElement(Node *node, int index) const
        {
            /* Base Case */
            if(index == 0)
            {
                return node->getChar();
            }

            return getElement(node->getNextNode(), (index - 1));
        }

        /* Recursive function for setting the char value at the desired index */
        void setElement(Node *node, int index, char c)
        {
            /* Base Case */
            if(index == 0)
            {
                return node->setChar(c);
            }

            return setElement(node->getNextNode(), (index - 1), c);
        }
};

#endif
