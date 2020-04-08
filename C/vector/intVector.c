/*
    Implementation file for vector in C
*/

#include "./intVector.h"
#include <stdio.h>


struct intVector* createIntVector ()
{       
    struct intVector* temp = (struct intVector*)malloc( sizeof(struct intVector) );     

    //assert(temp); // checking if there is enough memory in heap for temp
    
    //initializing the temp struct
    temp->head = NULL;
    temp->size = 0;
    temp->capacity = 3;  // avoiding unused memory    

    temp->head = (int*)calloc(temp->capacity, sizeof(size_t));

    return temp;
}

void pushIntVector(struct intVector** head, const int value) 
{    
    // implementation
}