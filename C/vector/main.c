#include <stdio.h>
#include "intVector.h"

int main () 
{       
    struct intVector* temp = createIntVector();   

    pushIntVector(&temp, 32);    
        
    return 0;
}