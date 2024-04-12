#ifndef PAIRUTILS_H_INCLUDED 
#define PAIRUTILS_H_INCLUDED 

#include "List.h"

void getNewValue(ListEntry *newValue);
void addNewValuesToExistingKey(List * KeyList, int position, ListEntry newPair);
void getKey(Data *keyData); 
void getValues(List *valueList);
void getPair(ListEntry *data); 

#endif
