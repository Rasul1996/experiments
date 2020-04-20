#ifndef __DOUBLE_LINKED_LIST_IN_C__
#define __DOUBLE_LINKED_LIST_IN_C__

#include <assert.h> // for assertion

#include <stdlib.h> // for malloc, calloc and free functions, 
                    // and as in the lib included stddef lib where size_t is defined, 
                    // there is no need to redefine the size_t

#define MIN_INT_VALUE -2147483648; // the minimum number that int value can store. It is for indicating error/wrong/initial value that means nothing

struct list // this is a container that has only pointers to the first and last nodes
{    
    struct listNode* first;     // pointer to the first node in list
    struct listNode* last;      // pointer to the last node in list        
    size_t size;    
};

struct listNode // this is the node that stores data and pointers to the next and previous nodes
{
    int data;                           // for simplicity the data is in int type
    struct listNode* next;      // pointer to the next node 
    //struct listNode* prev;      // pointer to the previous node
};

/* The user only uses list struct and does not care about the node struct */

struct list* createlist(); // creates the double linked list

struct listNode* createListNode(const int value); // creates double linked list node and initializes it with value to the data and 
                                                                                    // the prevNode that is THE previous node that the new node stores in prev pointer
void pushBackTolist(struct list* head, const int value); // pushes value the list at the end

void pushFrontTolist(struct list* head, const int value); // pushes value the list at the front

void showAllListData(struct list* head); // shows all the data in the list by iterating

size_t sizeOfList(struct list* head); // gets the size of the list

int firstValueInList(struct list* head);

int lastValueInList(struct list* head);

void clearList(struct list* head); // clearing the list
#endif