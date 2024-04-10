

#include "../headers/List.h"
#include "../headers/operations.h"


void AddHandler( List *keyList)
{
   
}
void ModificationHandler( List *list)
{

}


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

    
void RemoveHandler(List *keyList) {
    
    if(ListEmpty(keyList))
    {
        printf("\n[!] key List Empty !!\n");
        return;
    }
    
    int choice = 1;
    while (choice != 0 || choice > ListSize(keyList)+1) {
        printf("\n\n0) Back");
        TraverseList(keyList,&displayKey);
        printf("\n%d) All List\n",ListSize(keyList)+1);
        ResetCounter();
        choice = validateChoice(0,ListSize(keyList)+1);

        if (choice == 0)
        {
            return;
        }
        else if (choice == ListSize(keyList)+1)
        {
            DestroyList(keyList);
            return;
        }
        else
        {
            removeKey(choice - 1, keyList);
        }
    }
}





