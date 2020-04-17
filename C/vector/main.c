#include <stdio.h>
#include "intVector.h"

int main () 
{       
    struct intVector* temp = createIntVector();  

    pushValueToIntVector(temp, 1);
    pushValueToIntVector(temp, 2);
    pushValueToIntVector(temp, 3);
    pushValueToIntVector(temp, 4);

    insertValueToIntVector(temp, 2, 11);
    insertValueToIntVector(temp, 4, 44);
    
    unshiftValueToIntVector(temp, 6);
    unshiftValueToIntVector(temp, 5);

    insertValueToIntVector(temp, 0, 1100);

    printf("%d  \n", shiftValueFromIntVector(temp));
    printf("%d  \n", popValueFromIntVector(temp));

    printf("is empty %d \n", isIntVectorEmpty(temp));

    printf("element: %d \n\n", getElementFromIntVectorAt(temp, 2));
    printf("element: %d \n\n", getFirstElementFromIntVector(temp));
    printf("element: %d \n\n", getLastElementFromIntVector(temp));

    showAllDataIntVector(temp);   
        
    return 0;
}