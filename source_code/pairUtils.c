
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../headers/List.h"
#include "../headers/operations.h"
#include "../headers/sort.h"
#include "../headers/displayMenu.h"
#include "../headers/validation.h"

void getNewValue(ListEntry *newValue)
{
    int valid = 0;

    String value;
    do
    {
        value = (String) malloc(255);
        
        printf("\n[+] New Value: ");
        scanf("%s",value);
        getchar();
        valid = 1;
        
        for (int i = 0; value[i] != '\0'; ++i) 
        {
            if (!isdigit(value[i])) 
            {
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
            printf("\n[!] Invalid Value Positive Integer only!\n");
            free(value);
        }
    }while(valid == 0);
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
    getchar();
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
            anotherValue = (char) toupper(wantContinue("\n\n[?] Add Another Value ( Y/N ):\n"));
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

