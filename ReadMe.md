
|--------( handler )--------|

void AddHandler( List *list); 
void RemoveHandler( List *list); 
void ModificationHandler( List *list);
void DisplayHandler( List *list);

|--------( List )--------|

//  |---------( main list methods )---------|
void CreateList( List *list);
int ListEmpty( List *list);
int ListFull( List *list);
void InsertList( List *list, int position, listEntry dataObject);
void DeleteList( List *list, int position, listEntry *dataObject);

//  |---------( user  methods )---------|
void TraverseList( List *list, void (*function)(listEntry));
int ListSize( List *list);
void RetriveList( List *list, int position, listEntry *dataObject);
void ReplaceList( List *list, int position, listEntry dataObject);
void DestroyList( List *list);

|--------( operation )--------|

void prepareValue(Data *newPair);
int keyValidation( Data newPair, List *keyList);
void addNewKey( Data newPair, List *keyList);
void addNewValuesToExistingKey( Data newPair, List *keyList, int position);
void removeKey( int position, List *keyList);

|--------( pair )--------|


void addNewValueToNewKey(List * KeyValueList);
void getKey(Data *keyData); 
void getValues(List *valueList);
void getPair(listEntry *data); 

|--------( sort )--------|

void sortString(List *keyList);
void sortInt(List *valueList);


