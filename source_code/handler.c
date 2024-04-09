

#include "../headers/List.h"


void AddHandler( List *keyList)
{
   
}
void RemoveHandler( List *keyList)
{
    
}
void ModificationHandler( List *list)
{

}


void DisplayHandler( List *keyList)
{
    
    if(ListEmpty(keyList))
    {
        printf("[!] key List Empty !!");
        return;
    }

    int choice = -1;
    char back = ' ';
    do
    {

        printf("\n|-------------( Key Menu )-------------|\n");
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

