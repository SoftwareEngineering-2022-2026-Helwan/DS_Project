
#include "../headers/List.h"


void prepareValueList(ListEntry *newPair)
{
    List *valueList = (List *) malloc(sizeof(List));
    CreateList(valueList);

    newPair->keyPair.values_list = valueList;

    free(valueList);
}

int keyValidation( ListEntry newPair, List *keyList);
void addNewKey( ListEntry newPair, List *keyList);
void addNewValuesToExistingKey( ListEntry newPair, List *keyList, int position);
void removeKey( int position, List *keyList)
{
    Data deletedPair;

    DeleteList(keyList,position,&deletedPair);

    printf("\n\n[!] Pair deleted\n");
    displayPair(deletedPair);
    
    DestroyList(deletedPair.keyPair.values_list);

}
