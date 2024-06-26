#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/List.h"
#include "../headers/sort.h"
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

    sortString(keyList);
    
}

void removeKey( int position, List *keyList)
{
    Data deletedPair;

    DeleteList(keyList,position,&deletedPair);

    printf("\n\n[!] Pair deleted\n");
    displayPair(deletedPair);
    
    DestroyList(deletedPair.keyPair.values_list);

}

int valueExist( ListEntry newPair, List *valueList, int sameList)
{
    int position = 0, exist = 0;
    ListEntry comparedData;

    while(position < ListSize(valueList))
    {
        RetrieveList(valueList,position,&comparedData);

        if( newPair.value == comparedData.value ) 
        {
		exist++;

		if(!sameList || exist >= 2)
		{   
			return position;
		}
			
        }

        position++;
    }

    return -1; //incase there is no value match the new pair

}

void valueValidation( ListEntry *newPair, List *valueList, int sameList)
{
    int position = 0;
    int valuePosition;
    ListEntry comparedData;

    while(position < ListSize(newPair->keyPair.values_list))
    {
        valuePosition = -1;
        if(!ListEmpty(newPair->keyPair.values_list) && position <= -1)
        {
            position = 0;
        }
        

        RetrieveList(newPair->keyPair.values_list,position,&comparedData);


        valuePosition = valueExist(comparedData, valueList, sameList);
        
    
        if(valuePosition != -1)
        {
            if(sameList == 1)
            {
                DeleteList(newPair->keyPair.values_list,valuePosition,&comparedData);
            }
            else
            {
                DeleteList(newPair->keyPair.values_list,position,&comparedData);   
            }
            position = 0;
        }
        else
        {
            position++;
        }
        
            
    }


}
