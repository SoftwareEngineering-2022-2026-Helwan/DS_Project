#include "../headers/List.h"
#include <stdlib.h>


void CreateList(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
}

int ListEmpty(List *pl)
{
    return !pl->size;
}

int ListFull(List *pl)
{
    return 1;
}

int ListSize(List *pl)
{
    return pl->size;
}

void DestroyList(List *pl)
{
    ListNode *q;
    while(pl->head)
    {
        q = pl->head->next;
        free(pl->head);
        pl->head = q;
    }
    pl->size = 0;

}

void InsertList(List *pl,int pos,ListEntry e)
{
    int i;
    ListNode *q;
    ListNode *pn = (ListNode *)malloc(sizeof(ListNode));
    pn->data = e;
    pn->next = NULL;

    if(pos == 0)
    {
        pn->next = pl->head;
        pl->head = pn;
    }
    else
    {
        for(q = pl->head,i = 0; i < pos-1;i++)
            q = q->next;
        pn->next = q->next;
        q->next = pn;
    }

    pl->size++;

}

void DeleteList(List *pl,int pos,ListEntry *pe)
{
    int i;
    ListNode *q,*tmp;
    if(pos == 0)
    {
        *pe = pl->head->data;
        q = pl->head;
        pl->head = q->next;
        free(q);
    }
    else
    {
        for(q = pl->head,i  = 0;i < pos-1;i++)
            q = q->next;
        tmp = q->next;
        *pe = tmp->data;
        q->next = tmp->next;
        free(tmp);
    }
    pl->size--;
}

void RetrieveList(List *pl,int pos,ListEntry *pe)
{
    int i;
    ListNode *q;
    for(q = pl->head,i = 0;i < pos;i++)
        q = q->next;
    *pe = q->data;
}

void ReplaceList(List *pl,int pos,ListEntry e)
{
    int i;
    ListNode *q;
    for(q = pl->head,i = 0;i < pos;i++)
        q = q->next;
    q->data = e;
}

void TraverseList(List *pl,void(*pf)(ListEntry))
{
    ListNode *q = pl->head;
    while(q)
    {
        (*pf)(q->data);
        q = q->next;

    }

}


void SortList(List *list, int (*compareTo)(ListEntry,ListEntry))
{
    ListNode *isBig, *isSmall;

    isBig = list->head;
    isSmall = isBig->next; 
    
    while(isBig)
    {
        isSmall = list->head;
        while(isSmall)
        {
            if((*compareTo)(isBig->data, isSmall->data))
            {
                ListEntry tmp = isBig->data;
                isBig->data = isSmall->data;
                isSmall->data = tmp;                
            }  
            
            if(isSmall)
            {
                isSmall = isSmall->next;
            }
        }
        if(isBig)
        {
            isBig = isBig->next; 
        }
    }

}


// #include<string.h>

// int isLarge(String key1, String key2)
// {
//     if(strcmp(key1,key2))
//     {
        
//         for( int index = 0;( (index < strlen(key1)) && (index < strlen(key2)) )  ;  index++)
//         {
//             if(sortDirection == ASC)
//             {
//                 if(key1[index] > key2[index])
//                 {
//                     return 1;
//                 }
//             }
//             else
//             {
//                 if(key1[index] < key2[index])
//                 {
//                     return 1;
//                 }
//             }
//         }
//     }

//     return 0;
// }

// void sortString(List *keyList)
// {
//         ListNode *isBig, *isSmall;

//     isBig = keyList->head;
//     isSmall = isBig->next; 
    
//     while(isBig)
//     {
//         isSmall = keyList->head;
//         while(isSmall)
//         {
//             if(isLarge(isBig->data.keyPair.key, isSmall->data.keyPair.key))
//             {
//                 ListEntry tmp = isBig->data;
//                 isBig->data = isSmall->data;
//                 isSmall->data = tmp;                
//             }  
            
//             if(isSmall)
//             {
//                 isSmall = isSmall->next;
//             }
//         }
//         if(isBig)
//         {
//             isBig = isBig->next; 
//         }
//     }

// }

// void sortInt(List *valueList)
// {
//     ListNode *isBig, *isSmall;

//     isBig = valueList->head;
//     isSmall = isBig->next; 
    
//     while(isBig)
//     {
//         isSmall = valueList->head;
//         while(isSmall)
//         {
//             if(sortDirection == ASC)
//             {
//                 if(isBig->data.value < isSmall->data.value)
//                 {
//                     int tmp = isBig->data.value;
//                     isBig->data.value = isSmall->data.value;
//                     isSmall->data.value = tmp;                
//                 }  
//             }
//             else
//             {
//                 if(isBig->data.value > isSmall->data.value)
//                 {
//                     int tmp = isBig->data.value;
//                     isBig->data.value = isSmall->data.value;
//                     isSmall->data.value = tmp;                
//                 }  
//             }
//             if(isSmall)
//             {
//                 isSmall = isSmall->next;
//             }
//         }
//         if(isBig)
//         {
//             isBig = isBig->next; 
//         }
//     }
// }
