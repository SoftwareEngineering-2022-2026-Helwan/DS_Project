#include "../headers/List.h"

void addNewValueToNewKey(List * KeyValueList);
void getKey(Data *keyData); 
void getValues(List *valueList);
void getPair(ListEntry *data); 
void getNewValue(ListEntry *newValue)
{
    String value = (String) malloc(255);
    printf("\n[+] New Value: ");
    scanf("%s",value);
    newValue->value = atoi(value);

    free(value);
}

