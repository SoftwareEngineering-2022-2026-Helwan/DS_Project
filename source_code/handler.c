

#include "../headers/List.h"
#include "../headers/displayMenu.h"

void AddHandler( List *list)
{
    ListEntry int data;
    char answer;
    int position ;
    position = keyValidation(data, &keyList);
    do {
        getPair(&data);
        if (position ==-1) {
            printf("This key already exists.\n");
            printf("Do you want to add a new value to the existing key? (Yes or No): ");
            scanf(" %c", &answer); 
            if (answer == 'N') {
                printf("Do you want to add another pair? (Yes or No): ");
                scanf(" %c", &answer); 
                if (answer != 'Y') {
                    sortString(&keyList);
                }
            } else {
                addNewValuesToExistingKey(&keyList, position, data); 
            }
        } else {
            addNewKey(data, &keyList); 
        }
    } while (answer == 'Y');
}
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
        printf("\n0) Back");
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
            printf("\n0) Back");
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

