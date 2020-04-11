/*
    Implementation file for vector in C
*/

#include "./intVector.h"
#include <stdio.h>


struct intVector* createIntVector ()
{       
    struct intVector* temp = (struct intVector*)malloc( sizeof(struct intVector) );     

    assert(temp); // checking if there is enough memory in heap for temp
    
    //initializing the temp struct
    temp->head = NULL;
    temp->size = 0;
    temp->capacity = 3;  // avoiding unused memory    
    temp->difference = 1.5;
    temp->MIN_INT_VALUE = -2147483648;

    temp->head = (int*)calloc(temp->capacity, sizeof(size_t));    

    assert(temp->head);    
    

    return temp;
}

void resizeIntVectorMemory (int** head, const int capacity) 
{
    int* result = (int*)realloc(*head, capacity); // first try reallocate the memory

    // if if fails to reallocate enough space in linear mode, try allocate the same amount of memory from another place
    // and copy the previous memory data to the new allocated memory place
    if (result == NULL) 
    {   
        result = (int*)calloc(capacity, sizeof(size_t));

        assert(result); // if fails this time too, there is no free space for intVector data, that leads to crash the prgoram

        memcpy(result, *head, capacity);
    }

    *head = result;
}

void checkIntVectorMemory (struct intVector* temp) 
{   
    bool needResizeMemory = false;

    const size_t length = temp->size;
    const size_t capacity = temp->capacity;
    const size_t difference = temp->difference;
    
    // the difference should be '(*temp)->difference' between size and capacity
    if (length == capacity) // need to increase the capacity the '(*temp)->difference' times
    {
        needResizeMemory = true;
        temp->capacity *= difference;
    }
    else if (length * difference !> capacity) // need to decrease the capactiy the '(*temp)->difference' times
    { 
        needResizeMemory = true;
        temp->capacity /= difference;
    }

    if (needResizeMemory) {
        resizeIntVectorMemory(&temp->head, capacity);
    }
}

void pushIntVector(struct intVector* temp, const int value) 
{    
    // implementation
    temp->head[0] = value;        
}