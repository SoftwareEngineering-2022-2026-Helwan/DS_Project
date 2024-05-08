#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "global.h"

typedef Data ListEntry;

typedef struct listnode
{
    ListEntry data;
    struct listnode *next;
}ListNode;

typedef struct list
{
    ListNode *head;
    int size;
}List;

// |-----------------( Main List Methods )-----------------|
void CreateList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void InsertList(List *pl,int pos,ListEntry e);
void DeleteList(List *pl,int pos,ListEntry *pe);
void RetrieveList(List *pl,int pos,ListEntry *pe);
void ReplaceList(List *pl,int pos,ListEntry e);

// |-----------------( User List Methods )-----------------|
void TraverseList(List *pl,void(*pf)(ListEntry));
void SortList(List *list, int (*compareTo)(ListEntry,ListEntry));





#endif // LIST_H_INCLUDED
