/*
    Header file for vector in
*/

//#include <stddef.h>   // for size_t type that cannot be a negative value
//typedef unsigned int size_t; // as only size_t is needed from above lib, it can be declared customly

#ifndef __VECTOR_IN_C__
#define __VECTOR_IN_C__

#include <assert.h> // for assertion

#include <stdlib.h> // for malloc, calloc and free functions, 
                    // and as in the lib included stddef lib where size_t is defined, 
                    // there is no need to redefine the size_t

struct intVector 
{
    int* head;         // for holding the head of the vector of integers
    size_t capacity;   // capacity should be 1.5 times greater than the size in order to prevent memory overflow
    size_t size;       // the size of the vector of integers
};

struct intVector* createIntVector (); // creating vector of integers

void pushIntVector(struct intVector** head, const int value); // pushing the value to the array and if there is no 
                                                              // place allocate larger memory for it and copy all 
                                                              // the data and free the previous memory and set head
                                                              // to the new allocated memory place

#endif