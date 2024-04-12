#include "../headers/List.h"

#include <stdlib.h>

void prepareValueList(Data *newPair){
    List *valueList = (List *) malloc(sizeof(List));
    CreateList(valueList);
    newPair->keyPair.values_list = valueList;
}

int keyValidation( Data newPair, List *keyList){}
void addNewKey( Data newPair, List *keyList){}
void addNewValuesToExistingKey( List *keyList, int position, Data newPair){}
void removeKey( int position, List *keyList){}
