#include <stdio.h>
#include "list.h"

int main()
{
    struct list* temp = createlist();

    pushFrontTolist(temp, 1);    

    pushBackTolist(temp, 3);
    pushBackTolist(temp, 45);
    pushBackTolist(temp, 10);
    pushBackTolist(temp, 101);
    
    pushFrontTolist(temp, 75);
    pushFrontTolist(temp, 2);
    pushFrontTolist(temp, 31);

    printf("FIRST: %d \n", firstValueInList(temp));
    printf("LAST: %d \n", lastValueInList(temp));
    printf("SIZE: %lu \n", sizeOfList(temp));

    showAllListData(temp);
    
    printf("AFTER. \n\n");

    //clearList(temp);
    //showAllListData(temp);

    destroyList(&temp);
    return 0;
}