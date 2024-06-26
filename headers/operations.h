#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "List.h"

void prepareValueList(Data *newPair);
int keyValidation( Data newPair, List *keyList);
void addNewKey( Data newPair, List *keyList);
void removeKey( int position, List *keyList);
void valueValidation( ListEntry *newPair, List *valueList, int sameList);

#endif
