#include <ctype.h>
#include <stdio.h>
#include "../headers/List.h"
#include "../headers/sort.h"
#include "../headers/displayMenu.h"
#include "../headers/menu.h"
#include "../headers/pairUtils.h"
#include "../headers/operations.h"
#include "../headers/validation.h"



void AddHandler( List *keyList)
{
    Data newPair;

    char continueChoice;

    do
    {
        printAddMenu();
        getPair(&newPair);

        int keyPosition = keyValidation(newPair,keyList) ;

        

        if( keyPosition == -1) // if true ask to add new key
        {
            valueValidation(&newPair, newPair.keyPair.values_list, 1);
            addNewKey(newPair,keyList);
        }
        else // handle new key values if want to add them
        {
            char add;
            do
            {
                printf("\n[!] Key { %s } Exist !\n",newPair.keyPair.key);
                
                add = (char) toupper(wantContinue("[?] Do you Want Add its New Values ? (Y/N) :  \n")) ;
                if(add != 'Y' && add != 'N')
                {
                    printf("\n\n[!]Invalid character\n[!] Valid characters Are (Y , y) and (N , n) Only!! \n");
                }
                else if (add == 'Y')
                {
                    addNewValuesToExistingKey(keyList,keyPosition,newPair);
                }

            }while(add != 'Y' && add != 'N');
        }

        do
        {
            printAnotherPairMenu();
    
            continueChoice = (char) toupper(wantContinue("\n\n[?] Add Another Pair ( Y/N ):\n"));

            if(continueChoice != 'Y' && continueChoice != 'N')
            {
                printf("\n\n[!]Invalid character\n[!] Valid characters Are (Y , y) and (N , n) Only!! \n");
            }
            

        }while(continueChoice != 'Y' && continueChoice != 'N');

    }while(continueChoice == 'Y');

    sortString(keyList);

}

    
void ModificationHandler( List *keyList)
{
    if(ListEmpty(keyList))
    {
        printf("\n[!] key List Empty !!\n");
        return;
    }

    int option;
    do
    {
        printKeyModificationMenu();
        printKeyListMenu();
        printf("\n[*] Select Key To Modifiy: \n");
        printf("0) Back");
        TraverseList(keyList,&displayKey);
        ResetCounter();

        option = validateChoice(0,ListSize(keyList));
        
        if(option == 0)
        {
            break;
        }

        Data selectedData;
        RetrieveList(keyList,option-1,&selectedData);

        int selectedValue;
        do
        {
            if(ListEmpty(selectedData.keyPair.values_list))
            {
                printf("\n[!] value List Empty !!\n");
                break;
            }
            printValueListMenu();
            printf("\n[*] Select Value To Modifiy: \n");
            printf("0) Back");
            TraverseList(selectedData.keyPair.values_list,&displayValueToSelect); 
            ResetCounter();

            selectedValue = validateChoice(0,ListSize(selectedData.keyPair.values_list));
            
            if(selectedValue == 0)
            {
                break;
            }

            Data newValue;
            
            getNewValue(&newValue);
            if(newValue.value != (-0))
            {
                ReplaceList(selectedData.keyPair.values_list,selectedValue-1,newValue);
		        valueValidation(&selectedData ,selectedData.keyPair.values_list, 1);
            }

            printf("\n[!] Value Updated..!\n");


            sortInt(selectedData.keyPair.values_list);


        }while(selectedValue != 0);

        
    }while(option != 0);
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
        printDisplayMenu();
        printf("\n[*] Select Key To Display: \n");
        printf("0) Back");
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
                
                back = (char) toupper(wantContinue("\n\n[?] Go Back ( Y/N ): \n"));
                
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
    while (choice != 0 || choice > ListSize(keyList)+1) 
    {
        printRemoveMenu();
        printKeyListMenu();
        printf("\n0) Back");
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
	        TraverseList(keyList,&displayPair);
            DestroyList(keyList);
            return;
        }
        else
        {
            removeKey(choice - 1, keyList);
            if(ListEmpty(keyList))
            {
                break;
            }
        }
    }
}

