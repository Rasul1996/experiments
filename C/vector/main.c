#include <stdio.h>
#include "intVector.h"

int main () 
{       
    struct intVector* temp = createIntVector();  

    printf("Is empty: %d \n\n", isIntVectorEmpty(temp));

    pushValueToIntVector(temp, 1);
    pushValueToIntVector(temp, 2);
    pushValueToIntVector(temp, 3);
    pushValueToIntVector(temp, 4);

    insertValueToIntVector(temp, 2, 11);
    insertValueToIntVector(temp, 4, 44);
    
    unshiftValueToIntVector(temp, 6);
    unshiftValueToIntVector(temp, 5);

    insertValueToIntVector(temp, 0, 1100);

    printf("Shifted value:%d  \n\n", shiftValueFromIntVector(temp));
    printf("Popped value: %d  \n\n", popValueFromIntVector(temp));

    printf("Is empty: %d \n\n", isIntVectorEmpty(temp));

    printf("Element at index (2): %d \n\n", getElementFromIntVectorAt(temp, 2));
    printf("First element: %d \n\n", getFirstElementFromIntVector(temp));
    printf("Last element: %d \n\n", getLastElementFromIntVector(temp));

    printf("All values: \n\n");
    showAllDataIntVector(temp);   

    destroyIntVector(&temp);                
    return 0;
}