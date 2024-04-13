#include <stdio.h>
#include "../headers/List.h"


void displayKey(ListEntry listItem)
{
    static int position = 1;
    if(listItem.value == -1)
    {
        position = 1;
    }
    else
    {
        printf("\n%d) key: %s",position,listItem.keyPair.key);
        position++;
    }
}
void displayValue(ListEntry listItem)
{
    printf("\n[=] value: %d\n",listItem.value);
}

void displayValueToSelect(ListEntry listItem)
{
    static int position = 1;
    if(listItem.value == -1)
    {
        position = 1;
    }
    else
    {
        printf("\n%d) value: %d",position,listItem.value);
        position++;
    }
}

void displayKeyHeader(ListEntry list)
{
    printf("\n|------( %s Values)------|\n",list.keyPair.key);
}

void displayPair(ListEntry listItem)
{
    displayKeyHeader(listItem);
    if(!ListEmpty(listItem.keyPair.values_list))
    {
        TraverseList(listItem.keyPair.values_list,&displayValue);
    }
}

