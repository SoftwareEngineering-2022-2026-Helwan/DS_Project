#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// |--------( headers )--------|

#include "headers/global.h"
#include "headers/List.h"
//#include "headers/LinkedList.h"
// #include "headers/sort.h"
// #include "headers/pairUtils.h"
// #include "headers/operations.h"
//#include "headers/handler.h"
#include "source_code/displayMenu.c"
#include "source_code/validation.c"
#include "source_code/handler.c"
#include "source_code/menu.c"


void debug(int task);

int main(int argc, String argv[])
{
    if(argc == 3 && !strcmp(argv[1],"-d"))
    {
        debug( atoi(argv[2]) ); 
        return 1;  
    }

    List keyList;
    CreateList(&keyList);

    int option = -1;
    
    do
    {
        printMainMenu();
        option = validateChoice(0,4);
        
        switch(option)
        {
            case 1:
                printAddMenu();
                AddHandler(&keyList);
                break;
            case 2:
                printRemoveMenu();
                RemoveHandler(&keyList);
                break;
            case 3:
                printKeyModificationMenu();
                ModificationHandler(&keyList);
                break;
            case 4:
                printDisplayMenu();
                DisplayHandler(&keyList);
                break;
            case 0: 
                printf("\n[!] Exiting....! \n");
                break;                
        }


    }while(option != 0);

    return 0;
}


// |==================( Test Section )==================|



void task2Test();

void debug(int task)
{
    printf("\n[!] Task%d:\n",task);
    switch(task)
    {
        case 2:
            task2Test();
            break;
        
    }
}


// |-------------( Tasks )-------------|

void task2Test()
{
    List keyList , valueList, valueList2;

    CreateList(&keyList);
    CreateList(&valueList);
    CreateList(&valueList2);

    Data pairData, value1, value2;

    pairData.keyPair.key = "key1";
    pairData.keyPair.values_list = &valueList;

    value1.value = 10;
    value2.value = 30;

    InsertList(pairData.keyPair.values_list,0, value1);
    
    InsertList(pairData.keyPair.values_list,0, value2);
    
    InsertList(&keyList, 0, pairData);

    

    Data pairData2, value3, value4;

    pairData2.keyPair.key = "key2";
    pairData2.keyPair.values_list = &valueList2;

    value3.value = 20;
    value4.value = 40;
    Data value5;
    value5.value = 50;
    InsertList(pairData2.keyPair.values_list,0, value3);
        
    InsertList(pairData2.keyPair.values_list,0, value4);

    ReplaceList(pairData2.keyPair.values_list,0,value5);
        
    InsertList(&keyList, 1, pairData2);

    //TraverseList(&keyList,&displayPair);

    DisplayHandler(&keyList);
    
    
}