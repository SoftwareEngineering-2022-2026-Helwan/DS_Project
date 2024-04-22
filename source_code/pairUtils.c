
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../headers/List.h"
#include "../headers/operations.h"
#include "../headers/sort.h"
#include "../headers/displayMenu.h"

void getNewValue(ListEntry *newValue)
{
    String value = (String) malloc(255);
    printf("\n[+] New Value: ");
    scanf("%s",value);
    int valid = 1;
    
    for (int i = 0; value[i] != '\0'; ++i) {
        if (!isdigit(value[i])) {
            valid = 0;
            break;
        }
        
    }
    if(valid)
    {
        newValue->value = atoi(value);

        free(value);

    }
    else
    {   
        newValue->value = -0;
        printf("\n[!] Invalid Value Integer only!\n");
    }
}

void addNewValuesToExistingKey(List * KeyList, int position, ListEntry newPair)
{
    Data existKey;
    RetrieveList(KeyList,position,&existKey);

    valueValidation( &newPair, existKey.keyPair.values_list, 0);

    while(!ListEmpty(newPair.keyPair.values_list))
    {
        ListEntry newValue;

        DeleteList(newPair.keyPair.values_list,0,&newValue);
        InsertList(existKey.keyPair.values_list,0,newValue);

    }
    sortInt(existKey.keyPair.values_list);
    ReplaceList(KeyList,position,existKey);

}

void getKey(Data *keyData)
{
    keyData->keyPair.key = (String) malloc(255);
    
    printf("\n[?] Enter Key Name: ");
    scanf("\n%s",keyData->keyPair.key);
}

void getValues(List *valueList)
{
    char anotherValue;
    Data newValue;

    do
    {
        
        getNewValue(&newValue);
        if(newValue.value != (-0))
        {
            InsertList(valueList,0,newValue);
        }
        
        do
        {
            printf("\n\n[?] Add Another Value ( Y/N ): ");
            scanf("\n%c",&anotherValue);
            anotherValue = (char) toupper(anotherValue);
                        
            if(anotherValue != 'Y' && anotherValue != 'N')
            {
                printf("\n\n[!]Invalid character\n[!] Valid characters Are (Y , y) and (N , n) Only!! \n");
            }
        }while(anotherValue != 'Y' && anotherValue != 'N');

    }while(anotherValue == 'Y');

    sortInt(valueList);

}


void getPair(ListEntry *data)
{
    
    getKey(data);

    prepareValueList(data);

    getValues(data->keyPair.values_list);

}

