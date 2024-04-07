#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "global.h"
typedef Data listEntry;

typedef struct node
{
	listEntry data;
	struct node (*nextNode);
}ListNode;

struct list
{
	ListNode *head;
	int size;
};

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
#endif
