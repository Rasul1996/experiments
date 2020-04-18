#include "doubleLinkedList.h"

dlList* createDoubleLinkedList() // creates the list
{
    dlList* temp = (dlList*)malloc(sizeof(dlList));

    assert(temp);
    
    //initializing    
    temp->first = NULL;
    temp->last = NULL;

    return temp;
}

dlListNode* createDoubleLinkedListNode(const dlListNode* prevNode, const int value) // creates double linked list node
{
    dlListNode* node = (dlListNode*)malloc(sizeof(dlListNode));

    assert(node);

    // initializing
    node->data = value;
    node->next = NULL;
    node->prev = prevNode;

    return node;
}

void pushBackToDoubleLinkedList(dlList* head, const int value) // pushes value the list
{    
    
}