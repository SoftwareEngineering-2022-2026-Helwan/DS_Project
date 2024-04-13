

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
void DisplayHandler( List *keyList)
{
    
    if(ListEmpty(keyList))
    {
        printf("\n[!] key List Empty !!\n");
        return;
    }

    int choice = -1;
    char back = ' ';
    do
    {
        printDisplayMenu();
        printf("\n[*] Select Key To Display: \n");
        printf("\n0) Back");
        TraverseList(keyList,&displayKey);
        ResetCounter();
        
        choice = validateChoice(0,ListSize(keyList));

        if(choice != 0)
        {
            Data selecedPair;
            RetrieveList(keyList, choice-1, &selecedPair);

            displayKeyHeader(selecedPair);
            TraverseList(selecedPair.keyPair.values_list,&displayValue);

            do
            {
                printf("\n\n[?] Go Back ( Y/N ): ");
                scanf("\n%c",&back);
                back = (char) toupper(back);
                
                if(back != 'Y' && back != 'N')
                {
                    printf("\n\n[!]Invalid character\n[!] Valid characters Are (Y , y) and (N , n) Only!! \n");
                }
                else if (back == 'Y')
                {
                    choice = 0;
                }

            }while(back != 'Y' && back != 'N');


        }
        else
        {
            back = 'Y';
        }  

    }while(back != 'Y' && choice != 0);

}

