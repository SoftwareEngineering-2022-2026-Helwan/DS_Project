#include <stdlib.h>
#include <stdio.h>
#include "../headers/List.h"
//#include "../headers/sort.h"
#include <string.h>
#include "../headers/displayMenu.h"


void prepareValueList(ListEntry *newPair)
{
    List *valueList = (List *) malloc(sizeof(List));
    CreateList(valueList);

    newPair->keyPair.values_list = valueList;

}

int keyValidation( ListEntry newPair, List *keyList)
{
    int position = 0;
    ListEntry comparedData;
    
    while(position < ListSize(keyList))
    {
        RetrieveList(keyList,position,&comparedData);

        if(!strcmp(newPair.keyPair.key,comparedData.keyPair.key)) //return 0 if equal strings
        {
            return position;
        }
        
        position++;
    }

    return -1; //incase there is no key match the new pair 

}

void addNewKey( ListEntry newPair, List *keyList)
{
    InsertList(keyList,0,newPair);

    //sortString(keyList);
    
}

void removeKey( int position, List *keyList)
{
    Data deletedPair;

    DeleteList(keyList,position,&deletedPair);

    printf("\n\n[!] Pair deleted\n");
    displayPair(deletedPair);
    
    DestroyList(deletedPair.keyPair.values_list);

}
