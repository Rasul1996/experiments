#ifndef __DOUBLE_LINKED_LIST_IN_C__
#define __DOUBLE_LINKED_LIST_IN_C__

#include <assert.h> // for assertion

#include <stdlib.h> // for malloc, calloc and free functions, 
                    // and as in the lib included stddef lib where size_t is defined, 
                    // there is no need to redefine the size_t

#define MIN_INT_VALUE -2147483648; // the minimum number that int value can store. It is for indicating error/wrong/initial value that means nothing

struct doubleLinkedList // this is a container that has only pointers to the first and last nodes
{    
    struct doubleLinkedListNode* first;     // pointer to the first node in doubleLinkedList
    struct doubleLinkedListNode* last;      // pointer to the last node in doubleLinkedList        
};

struct doubleLinkedListNode // this is the node that stores data and pointers to the next and previous nodes
{
    int data;                           // for simplicity the data is in int type
    struct doubleLinkedListNode* next;      // pointer to the next node 
    struct doubleLinkedListNode* prev;      // pointer to the previous node
};

typedef struct doubleLinkedList dlList;         // for simplicity
typedef struct doubleLinkedListNode dlListNode; // for simplicity

/* The user only uses doubleLinkedList struct and does not care about the node struct */

dlList* createDoubleLinkedList(); // creates the double linked list

dlListNode* createDoubleLinkedListNode(const dlListNode* prevNode, const int value); // creates double linked list node and initializes it with value to the data and 
                                                                                    // the prevNode that is THE previous node that the new node stores in prev pointer
void pushBackToDoubleLinkedList(dlList* head, const int value); // pushes value the list

#endif