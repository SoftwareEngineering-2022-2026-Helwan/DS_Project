
#include "../headers/List.h"


void prepareValue(Data *newPair);
int keyValidation( Data newPair, List *keyList);
void addNewKey( Data newPair, List *keyList);
void addNewValuesToExistingKey( Data newPair, List *keyList, int position);
void removeKey( int position, List *keyList);
