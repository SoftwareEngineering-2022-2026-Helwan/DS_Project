#include "../headers/List.h"

void sortString(List *keyList)
{

}
void sortInt(List *valueList)
{
    int i, j;
    ListEntry temp;

    for (i = 0; i < ListSize(valueList); i++) {
        for (j = i+1; j < ListSize(valueList); j++) {
            ListEntry e1, e2;
            RetrieveList(valueList, i, &e1 );
            RetrieveList(valueList,j, &e2);

            if (e1.value > e2.value) {
                temp = e1;
                ReplaceList(valueList,i, e2 );
                ReplaceList(valueList,j, temp );
            }
        }
    }
}

