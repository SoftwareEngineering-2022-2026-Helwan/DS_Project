

#include "../headers/List.h"


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
void DisplayHandler( List *list){
    ListEntry data;
     int option;
    do{  
        TraverseList(list,&displayKey);
        printf("enter your choice : ");
        scanf("%d", &option);
       switch(optio){
         case 1:
            int pos;
             printf("\nEnter a Id to Insert : ");
             scanf(" %d",&pos);
             RetrieveList(&list,pos,&data);
            break;
         case 2:
            displayKeyHeader(data);
            break;
         case 3:
           TraverseList(list,&displayValue);
            break;
         case 4:
            return 1;
            break;
       }
    }while(option != 4);
    
};




