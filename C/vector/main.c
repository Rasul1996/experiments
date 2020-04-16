#include <stdio.h>
#include "intVector.h"

int main () 
{       
    struct intVector* temp = createIntVector();  
    
    insertValueToIntVector(temp, 0, 0);    
    insertValueToIntVector(temp, 1, 1); 
    insertValueToIntVector(temp, 1, 1); 
    insertValueToIntVector(temp, 1, 1); 
    insertValueToIntVector(temp, 1, 1); 
    insertValueToIntVector(temp, 2, 2); 

    insertValueToIntVector(temp, 3, 3); 
    insertValueToIntVector(temp, 4, 4); 
    insertValueToIntVector(temp, 5, 5); 

    // printf("%lu \n", temp->capacity);
    // printf("%lu \n", temp->size);
    insertValueToIntVector(temp, 6, 6); 
    insertValueToIntVector(temp, 7, 7); 
    insertValueToIntVector(temp, 8, 17); 
    insertValueToIntVector(temp, 9, 27); 
    insertValueToIntVector(temp, 10, 37); 
    insertValueToIntVector(temp, 11, 47); 
    insertValueToIntVector(temp, 12, 57); 
    insertValueToIntVector(temp, 13, 67); 
    insertValueToIntVector(temp, 14, 77); 
    insertValueToIntVector(temp, 15, 87); 
    insertValueToIntVector(temp, 16, 97); 
    insertValueToIntVector(temp, 17, 107); 
    insertValueToIntVector(temp, 18, 117); 
    insertValueToIntVector(temp, 19, 127); 
    insertValueToIntVector(temp, 20, 137); 
    
    
    //insertValueToIntVector(temp, 0, 33); 

    //getAllDataFromIntVector(temp);

    printf("%d \n", temp->head[0]);
    printf("%d \n", temp->head[1]);
    printf("%d \n", temp->head[2]);

    printf("%d \n", temp->head[3]);
    printf("%d \n", temp->head[4]);
    printf("%d \n", temp->head[5]);

    printf("%d \n", temp->head[6]);
    printf("%d \n", temp->head[7]);
    printf("%d \n", temp->head[8]);
    printf("%d \n", temp->head[9]);
    printf("%d \n", temp->head[10]);
    printf("%d \n", temp->head[11]);
    printf("%d \n", temp->head[12]);
    printf("%d \n", temp->head[13]);
    printf("%d \n", temp->head[14]);
    printf("%d \n", temp->head[15]);
    printf("%d \n", temp->head[16]);
    printf("%d \n", temp->head[17]);
    printf("%d \n", temp->head[18]);
    printf("%d \n", temp->head[19]);
    printf("%d \n", temp->head[20]);    
    printf("%d \n", temp->head[21]);    
    printf("%d \n", temp->head[22]);  
    printf("%d \n", temp->head[23]);      

    


    // int a[] = {1, 0, 0};

    // memcpy(a, a, sizeof(int) * 1);
    // printf("%d \n",a[0]);
    // printf("%d \n",a[1]);

    
        
    return 0;
}