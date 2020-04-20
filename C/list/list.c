#include "list.h"
#include <stdio.h>

struct list* createlist() // creates the list
{
    struct list* temp = (struct list*)malloc(sizeof(struct list));

    assert(temp);
    
    //initializing    
    temp->first = NULL;
    temp->last = NULL;
    temp->size = 0;

    return temp;
}

struct listNode* createListNode(const int value) // creates double linked list node
{
    struct listNode* node = (struct listNode*)malloc(sizeof(struct listNode));

    assert(node);

    // initializing
    node->data = value;
    node->next = NULL;    

    return node;
}

void pushBackTolist(struct list* head, const int value) // pushes value the list
{   
    struct listNode* prevNode = head->last;

    struct listNode* node = createListNode(value);    

    if (prevNode != NULL) {
        prevNode->next = node;
    }

    head->last = node;        
    if (head->first == NULL){
        head->first = node;
    }

    ++head->size;
}

void pushFrontTolist(struct list* head, const int value) // pushes value the list at the front
{
    struct listNode* firstNode = head->first; // get the first node if it points to NULL that`s ok

    struct listNode* node = createListNode(value);    

    head->first = node; // assigning the first node
    node->next = firstNode;

    if (head->last == NULL){
        head->last = node;
    }

    ++head->size;
}

void showAllListData(struct list* head) // shows all the data in the list by iterating
{   
    struct listNode* node = head->first;

    while (node != NULL)
    {
        printf("%d \n", node->data);

        node = node->next;
    }
    
}

size_t sizeOfList(struct list* head) // gets the size of the list
{
    return head->size;
}

int firstValueInList(struct list* head)
{
    return head->first ? head->first->data : MIN_INT_VALUE;
}

int lastValueInList(struct list* head)
{
    return head->last ? head->last->data : MIN_INT_VALUE;
}

void clearList(struct list* head) // clearing the list
{
    struct listNode* node = head->first;

    while (node != NULL)
    {        
        free(node); // dealocate each dynamic memory for each node
        node = node->next;
    }
}