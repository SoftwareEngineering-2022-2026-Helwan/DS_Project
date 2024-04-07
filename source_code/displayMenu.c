#include <stdio.h>
#include "../headers/LinkedList.h"


void displayKey(listEntry listItem)
{
    printf("\n[=] key: %s\n",listItem.keyPair.key);
}
void displayValue(listEntry listItem)
{
    printf("\n[=] value: %d\n",listItem.value);
}
void displayPair(listEntry listItem)
{
    displayKey(listItem);
    //TraverseList((listItem.keyPair.values_list),&displayValue);
}
void displayKeyHeader(listEntry list)
{
    printf("\n|------( %s Values)------|\n",list.keyPair.key);
}

