

#include "../headers/List.h"
#include "../headers/displayMenu.h"

void AddHandler( List *list)
{}
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

void ModificationHandler( List *list)
{}
void DisplayHandler( List *list){
    ListEntry data;
     int option;
    do{  
        TraverseList(list,&displayKey);
        printf("enter your choice : ");
        scanf("\n%d", &option);
       switch(option){
         case 1:
             Retrieve(list,&data);
            break;
         case 2:
            displayKeyHeader(data);
            break;
         case 3:
           TraverseList(list,&displayValue);
            break;
         case 4:
            return ;
            break;
       }
    }while(option != 4);

}
void Retrieve(List *list,ListEntry listItem){
       int pos;
        printf("\nEnter a position to Retrieve : ");
        scanf("\n%d",&pos);
       RetrieveList(list,pos,&listItem);
       printf("\n%d\n",listItem.value);
       }



