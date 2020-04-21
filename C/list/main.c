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

    removeElementFromListAt(temp, 4);
    
    pushFrontTolist(temp, 75);
    pushFrontTolist(temp, 2);
    pushFrontTolist(temp, 31);

    insertElementToList(temp, 2, 777);
    insertElementToList(temp, 1, 888);
    insertElementToList(temp, 2, 999);

    popFrontFromList(temp);
    popBackFromList(temp);
    popFrontFromList(temp);
    
    popFrontFromList(temp);
    popBackFromList(temp);
    popBackFromList(temp);
    popBackFromList(temp);

    printf("FIRST: %d \n", firstValueInList(temp));
    printf("LAST: %d \n", lastValueInList(temp));
    printf("SIZE: %lu \n", sizeOfList(temp));    

    showAllListData(temp);
    
    printf("AFTER. \n\n");

    clearList(temp);
    showAllListData(temp);

    destroyList(&temp);    
    return 0;
}