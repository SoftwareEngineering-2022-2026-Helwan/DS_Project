

#include "headers/LinkedList.h"

void AddHandler( List *list);
void RemoveHandler(List *list) {
    int x = 1;
    while (x != 0) {
        TraverseList(list,&displayKey);
        printf("enter your choice : ");
        scanf("%d", &x);

        if (x == 0)
            {
            break;
            }
        else if (x < 1 || x > list->size)
            {
            return ;
            }
        else if (x==list->size+1)
        {
            DestroyList(list);
        }
         else
         {
            removeKey(x - 1, list);
         }
    }
}

void ModificationHandler( List *list);
void DisplayHandler( List *list);

