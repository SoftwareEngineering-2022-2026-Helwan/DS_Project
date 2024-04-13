#include "../headers/List.h"
#include "../headers/operations.h"

#include <stddef.h>
#include<stdlib.h>
#include<stdio.h>


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

void getKey(Data *keyData) {
    keyData->keyPair.key = (char*)malloc(64 * sizeof(char));
    printf("Enter key (max 63 characters): ");
    scanf("%63s", keyData->keyPair.key);
    getchar();
}

void getValues(List *valueList) {
    int value;
    char choice;
    ListEntry entry;
    String n = (String) malloc(255);
    do {
        printf("Enter value: ");
        scanf("%s", n);
        value = atoi(n);
        entry.value = value;
        InsertList(valueList, 0, entry);
        printf("Add another value? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void getPair(ListEntry *data) {
    getKey(data);
    prepareValueList(data);
    getValues(data->keyPair.values_list);
}


