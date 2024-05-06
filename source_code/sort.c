#include "../headers/List.h"
#include<string.h>

int compareString(ListEntry pair1, ListEntry pair2)
{
    String key1 = pair1.keyPair.key;
    String key2 = pair2.keyPair.key;

    if(strcmp(key1,key2))
    {
        
        for( int index = 0;( (index < strlen(key1)) && (index < strlen(key2)) )  ;  index++)
        {
            if(sortDirection == ASC)
            {
                if(key1[index] < key2[index])
                {
                    return 1;
                }
            }
            else
            {
                if(key1[index] > key2[index])
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int compareInt(ListEntry pair1, ListEntry pair2)
{
    ListEntry e1 = pair1;
    ListEntry e2 = pair2;
    if(sortDirection == ASC)
    {
        if (e1.value < e2.value) 
        {
            return 1;
        }
    }
    else
    {
        if (e1.value > e2.value)
        {
            return 1;
        }
    }

    return 0;
} 

void sortString(List *keyList)
{
    SortList(keyList,&compareString);
}
void sortInt(List *valueList)
{
    SortList(valueList, &compareInt);
}

// void sortString(List *keyList)
// {
//     int i, j;
//     ListEntry temp;

//     for (i = 0; i < ListSize(keyList); i++) {
//         for (j = i+1; j < ListSize(keyList); j++) {
//             ListEntry e1, e2;
//             RetrieveList(keyList, i, &e1 );
//             RetrieveList(keyList,j, &e2);

//             if (compareString(e1.keyPair.key,e2.keyPair.key)) {
//                 temp = e1;
//                 ReplaceList(keyList,i, e2 );
//                 ReplaceList(keyList,j, temp );
//             }
//         }
//     }
// }
// void sortInt(List *valueList)
// {
//     int i, j;
//     ListEntry temp;

//     for (i = 0; i < ListSize(valueList); i++) {
//         for (j = i+1; j < ListSize(valueList); j++) {
//             ListEntry e1, e2;
//             RetrieveList(valueList, i, &e1 );
//             RetrieveList(valueList,j, &e2);

//             if(sortDirection == ASC)
//             {
//                 if (e1.value > e2.value) {
//                     temp = e1;
//                     ReplaceList(valueList,i, e2 );
//                     ReplaceList(valueList,j, temp );
//                 }
//             }
//             else
//             {
//                 if (e1.value < e2.value) {
//                     temp = e1;
//                     ReplaceList(valueList,i, e2 );
//                     ReplaceList(valueList,j, temp );
//                 }
//             }
//         }
//     }
// }

