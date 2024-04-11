#ifndef PAIRUTILS_H_INCLUDED 
#define PAIRUTILS_H_INCLUDED 

#include "List.h"

void addNewValueToExistingKey(List * KeyValueList);
void getKey(Data *keyData); 
void getValues(List *valueList);
void getPair(ListEntry *data); 
void getNewValue(ListEntry *newValue);

#endif
