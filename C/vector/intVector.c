/*
    Implementation file for vector in C
*/

#include "./intVector.h"
#include <stdio.h>

/* PRIVATE --------> */
void resizeIntVectorMemory (int** head, const size_t capacity) 
{    
    int* result = (int*)realloc(*head, sizeof(size_t) * capacity); // first try reallocate the memory    

    // if if fails to reallocate enough space in linear mode, try allocate the same amount of memory from another place
    // and copy the previous memory data to the new allocated memory place
    if (result == NULL) 
    {   
        result = (int*)calloc(capacity, sizeof(size_t));

        assert(result); // if fails this time too, there is no free space for intVector data, that leads to crash the prgoram

        memcpy(result, *head, sizeof(size_t) * capacity);
        free(*head);
    }

    *head = result;
}

void checkIntVectorMemory (struct intVector* temp) 
{   
    bool needResizeMemory = false;

    const size_t length = temp->size;
    const size_t capacity = temp->capacity;
    const float difference = temp->difference;      
        
    // the difference should be '(*temp)->difference' between size and capacity
    if (length == capacity) // need to increase the capacity the '(*temp)->difference' times
    {                
        needResizeMemory = true;
        temp->capacity *= difference;
    }
    else if (!(length * difference > capacity) && length != 0) // need to decrease the capactiy the '(*temp)->difference' times
    {                 
        // needResizeMemory = true;
        // temp->capacity /= difference;
    }

    if (needResizeMemory) {            
        resizeIntVectorMemory(&temp->head, capacity);
    }
}

/* <------------PRIVATE */


/* PUBLIC -------------> */
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

void pushValueToIntVector(struct intVector* temp, const int value) 
{    
    // implementation
    const size_t index = temp->size; // the last index

    insertValueToIntVector(temp, index, value);
}

void unshiftValueToIntVector(struct intVector* temp, const int value) // add element to the beginning of the vector
{
    const size_t index = 0; // the last index

    insertValueToIntVector(temp, index, value);
}

int* getAllDataFromIntVector(const struct intVector* temp) 
{    
    return temp->head;
}

void showAllDataIntVector(const struct intVector* temp) 
{
    for (size_t i = 0; i < temp->size; i++)
    {
        printf("[%lu] = %d \n", i, temp->head[i]);
    }
    
}

void insertValueToIntVector (struct intVector* temp, const size_t index, const int value)
{   
    checkIntVectorMemory(temp); // check if the memory is enough for the next to be inserted value
        
    if (temp->size != index) { // if index is not the last         
        memcpy(temp->head+index+1, temp->head + index, sizeof(int) * (temp->size - index));        
    }

    temp->head[index] = value; // inserting    

    temp->size++;
}

/* <------------------------------ PUBLIC */

