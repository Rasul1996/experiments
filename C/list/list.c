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

void insertElementToList(struct list* head, const size_t index, const int value) // inserts element at the given position to the list
{
    if (index > head->size) {
        return;
    }

    if (index == 0) {
        pushFrontTolist(head, value);
        return;
    }
    else if (index == head->size)
    {
        pushBackTolist(head, value);
        return;
    }
        

    struct listNode* prevNode = NULL;
    struct listNode* temp = head->first;

    for (size_t i = 0; i < index; i++)
    {           
        temp = temp->next;
    }

    prevNode = temp;
    temp = temp->next;

    struct listNode* node = createListNode(value);    

    prevNode->next = node;
    node->next = temp;

    ++head->size;
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

bool popBackFromList(struct list* head) // pops tha last element from the list
{
    struct listNode* targetNode = head->first;

    if(targetNode == NULL){
        return false;
    }

    struct listNode* temp = targetNode;
    while (targetNode->next != NULL) // iterate till the last element
    {   
        temp = targetNode;
        targetNode = targetNode->next;
    }    
    
    free(targetNode);
    temp->next = NULL;

    head->last = temp;
    --head->size;

    return true;
}

bool popFrontFromList(struct list* head) // pops tha first element from the list
{
    struct listNode* temp = head->first;

    if(temp == NULL){
        return false;
    }    
        
    head->first = head->first->next ? head->first->next : NULL;

    free(temp);

    --head->size;

    return true;
}

bool removeElementFromListAt(struct list* head, const size_t index) // removes an element from the list at the given index
{
    if (index > head->size) {
        return false;
    }
    else if (index == 0)
    {
        return popFrontFromList(head);
    }
    else if (index == head->size)
    {
        return popBackFromList(head);
    }
    
    struct listNode* targetNode = head->first;
    struct listNode* temp = targetNode;

    for (size_t i = 0; i < index; i++)
    {
        temp = targetNode;

        targetNode = targetNode->next;
    }
    
    temp->next = targetNode->next;
    free(targetNode);

    --head->size;
    return true;
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

    head->first = NULL;
    head->last = NULL;
    head->size = 0;
}

void destroyList(struct list** head) // destroy the list
{            
    (*head)->first = NULL;
    (*head)->last = NULL;

    free(*head);
    *head = NULL;    
}