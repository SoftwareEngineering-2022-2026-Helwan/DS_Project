#include <stdio.h>
#include "../headers/List.h"


void displayKey(ListEntry listItem)
{
    printf("\n[=] key: %s\n",listItem.keyPair.key);
}
void displayValue(ListEntry listItem)
{
    printf("\n[=] value: %d\n",listItem.value);
}
void displayPair(ListEntry listItem)
{
    displayKey(listItem);
    if(!ListEmpty(listItem.keyPair.values_list))
    {
        TraverseList((listItem.keyPair.values_list),&displayValue);
    }
}
void displayKeyHeader(ListEntry list)
{
    printf("\n|------( %s Values)------|\n",list.keyPair.key);
}

