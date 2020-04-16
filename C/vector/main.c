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

    insertValueToIntVector(temp, 0, 1100);

    unshiftValueToIntVector(temp, 6);
    unshiftValueToIntVector(temp, 5);

    showAllDataIntVector(temp);    
        
    return 0;
}