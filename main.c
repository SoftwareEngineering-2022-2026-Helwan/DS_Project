#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// |--------( headers )--------|

#include "headers/global.h"
#include "headers/List.h"
// #include "headers/sort.h"
// #include "headers/pairUtils.h"
// #include "headers/operations.h"
#include "source_code/displayMenu.c"
#include "source_code/validation.c"
#include "source_code/handler.c"
#include "source_code/menu.c"


void debug(int task, List *keyList);

int main(int argc, String argv[])
{
    List keyList;
    CreateList(&keyList);

    if(argc == 3 && !strcmp(argv[1],"-d"))
    {
        debug( atoi(argv[2]), &keyList ); 
        return 1;  
    }


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



void task2Test(List*,int);
void task4Test(List*);
void task6Test(List*);
void task11Test(List *keyList,ListEntry *newPair);


void debug(int task, List *keyList)
{
    printf("\n[!] Task%d:\n",task);
    switch(task)
    {
        case 2:
            task2Test(keyList, task);
            break;
        case 4:
            task2Test(keyList, task);
            task4Test(keyList);
            break;
        case 6:
            task2Test(keyList, task);
            task4Test(keyList);
            task6Test(keyList);
            task4Test(keyList);
            break;
        case 11:
            Data testPair;
            testPair.keyPair.key = "testKey";
            task11Test(keyList,&testPair);
            task4Test(keyList);
            break;
        

        
    }
}


// |-------------( Tasks )-------------|

void task2Test(List *keyList, int task)
{
    Data pairData, value1, value2;

    pairData.keyPair.key = "key1";
    prepareValueList(&pairData);

    value1.value = 10;
    value2.value = 30;

    InsertList(pairData.keyPair.values_list,0, value1);
    InsertList(pairData.keyPair.values_list,0, value2);
    
    InsertList(keyList, 0, pairData);

    

    Data pairData2, value3, value4;

    pairData2.keyPair.key = "key2";
    prepareValueList(&pairData2);

    value3.value = 20;
    value4.value = 40;
    
    InsertList(pairData2.keyPair.values_list,0, value3);
    InsertList(pairData2.keyPair.values_list,0, value4);

    Data value5, value6, pairData3;

    pairData3.keyPair.key = "key3";
    prepareValueList(&pairData3);

    value5.value = 50;
    value6.value = 60;

    ReplaceList(pairData2.keyPair.values_list,0,value5);
    
    InsertList(keyList, 1, pairData2);

    InsertList(pairData3.keyPair.values_list,0,value6);
    InsertList(pairData3.keyPair.values_list,0,value3);

    InsertList(keyList,1,pairData3);

    if (task == 2)
    {
        TraverseList(keyList,&displayPair);
    }
}

void task4Test(List *keyList)
{
    DisplayHandler(keyList);
}

void task6Test(List *keyList)
{

    printRemoveMenu();
    RemoveHandler(keyList);

}

// Task11: Prepare Value
void task11Test(List *keyList,ListEntry *newPair)
{   
    prepareValueList(newPair);
    Data testValue;
    testValue.value = 100;
    InsertList(newPair->keyPair.values_list,0,testValue);

    InsertList(keyList,0,*newPair);
}

