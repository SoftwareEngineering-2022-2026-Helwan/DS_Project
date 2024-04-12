#include "../headers/List.h"

#include <stdlib.h>

void prepareValue(Data *newPair){
    List *valueList = (List *) malloc(sizeof(List));
    CreateList(valueList);
    newPair->keyPair.values_list = valueList;
}

int keyValidation( Data newPair, List *keyList){}
void addNewKey( Data newPair, List *keyList){}
void addNewValuesToExistingKey( Data newPair, List *keyList, int position){}
void removeKey( int position, List *keyList){}
