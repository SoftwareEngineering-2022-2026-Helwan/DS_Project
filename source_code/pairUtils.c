
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../headers/List.h"
#include "../headers/operations.h"
// #include "../headers/sort.h"
// #include "../headers/displayMenu.h"


void getNewValue(ListEntry *newValue)
{
    String value = (String) malloc(255);
    printf("\n[+] New Value: ");
    scanf("%s",value);
    newValue->value = atoi(value);

    free(value);
}

void addNewValuesToExistingKey(List * KeyList, int position, ListEntry newPair)
{
    Data existKey;
    RetrieveList(KeyList,position,&existKey);

    while(!ListEmpty(newPair.keyPair.values_list))
    {
        ListEntry newValue;

        DeleteList(newPair.keyPair.values_list,0,&newValue);
        InsertList(existKey.keyPair.values_list,0,newValue);

    }
    //sortInt(existKey.keyPair.values_list);
    ReplaceList(KeyList,position,existKey);

}

void getKey(Data *keyData)
{
    String key = (String) malloc(255);
    printf("\n[?] Enter Key Name: ");
    scanf("\n%s",key);
    strcpy(keyData->keyPair.key,key);
}

void getValues(List *valueList)
{
    char anotherValue;
    Data newValue;

    do
    {

        getNewValue(&newValue);
        InsertList(valueList,0,newValue);
        
        do
        {
            printf("\n\n[?] Add Another Pair ( Y/N ): ");
            scanf("\n%c",&anotherValue);
            anotherValue = (char) toupper(anotherValue);
                        
            if(anotherValue != 'Y' && anotherValue != 'N')
            {
                printf("\n\n[!]Invalid character\n[!] Valid characters Are (Y , y) and (N , n) Only!! \n");
            }
        }while(anotherValue != 'Y' && anotherValue != 'N');

    }while(anotherValue == 'Y');

    //sortInt(valueList);

}

void loop(ListEntry entry)
{

    printf("\nkey: %s\n",entry.keyPair.key);
    Data value;
    int i = 0 , size = ListSize(entry.keyPair.values_list);
    printf("\nsize: %d",size);
    while(i != size)
    {
        RetrieveList(entry.keyPair.values_list,i,&value);
        printf("\nvalue%d: %d\n",i,value.value);
        i++;
    }
}
void getPair(ListEntry *data)
{
    getKey(data);

    prepareValueList(data);

    getValues(data->keyPair.values_list);

    loop(*data);
}

