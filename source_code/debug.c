#include "../headers/List.h"

void task2Test(List*,int);
void task4Test(List*);
void task6Test(List*);
void task11Test(List *keyList,ListEntry *newPair);
void task16Test(List *keyList);
void task7Test(List *keyList);
void task8Test(Data *newPair);
void task15Test(List *keyList, Data existPair);
void task12Test(List *keyList, Data existPair);
void task9Test(List *keyList);
void task10Test(List *keyList);

// |==================( Test Section )==================|

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
        case 16:
            task2Test(keyList, task);
            task16Test(keyList);
            break;
        case 7:
            task2Test(keyList,task);
            task7Test(keyList);
            task4Test(keyList);
            break;
        case 8:
            Data newPair;
            task8Test(&newPair);
            break;
        case 15:
            task2Test(keyList,task);
            Data existPair;
            task8Test(&existPair);
            task15Test(keyList,existPair);
            break;
        case 12: 
            task2Test(keyList,task);
            Data IexistPair;
            task8Test(&IexistPair);
            task12Test(keyList,IexistPair);
            break;
        case 9:
            task2Test(keyList,task);
            task9Test(keyList);
            break;
        case 10: 
            task2Test(keyList,task);
            task10Test(keyList);
            break;
        default:
            printf("\n[!] Invalid Debug Option!\n");
        

        
    }
}


// |-------------( Tasks )-------------|

// Task2: List
void task2Test(List *keyList, int task)
{
    Data pairData, value1, value2, value7;

    pairData.keyPair.key = "key1";
    prepareValueList(&pairData);

    value1.value = 20;
    value2.value = 10;
    value7.value = 70;

    InsertList(pairData.keyPair.values_list,0, value1);
    InsertList(pairData.keyPair.values_list,0, value7);
    InsertList(pairData.keyPair.values_list,0, value2);
    

    

    Data pairData2, value3, value4;

    pairData2.keyPair.key = "key6";
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
    

    InsertList(pairData3.keyPair.values_list,0,value6);
    InsertList(pairData3.keyPair.values_list,0,value3);

    InsertList(keyList, 0, pairData);
    InsertList(keyList, 0, pairData2);
    InsertList(keyList, 0, pairData3); 

    if (task == 2)
    {
        TraverseList(keyList,&displayPair);
    }
}


// Task4: Display Handler
void task4Test(List *keyList)
{
    DisplayHandler(keyList);
}


// Task6: Remove Handler
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


// Task16: Remove Key
void task16Test(List *keyList)
{
    removeKey(1,keyList);
}


// Task7: Remove Key
void task7Test(List *keyList)
{
    ModificationHandler(keyList);
}


// Task8: get pair
void task8Test(Data *newPair)
{
    getPair(newPair);
    displayPair(*newPair);
}


// Task15: addNewValuesToExistingKey
void task15Test(List *keyList, Data existPair)
{
   Data newData;
   addNewValuesToExistingKey(keyList,0,existPair);
   RetrieveList(keyList,0,&newData);
   displayPair(newData);
}



// Task12: validation
void task12Test(List *keyList, Data existPair)
{
    Data newData;
    int position = keyValidation(existPair,keyList);
    printf("pos = %d\n",position);
    if(position == -1)
    {   
        printf("\nNew Key!\n");
        return;
    }
    RetrieveList(keyList,position,&newData);
    displayPair(newData); 
}


//Task9 : sort int
void task9Test(List *keyList)
{
    Data dataToSort;

    RetrieveList(keyList,0,&dataToSort);
    printf("\nBefore: \n");
    displayPair(dataToSort);
    sortInt(dataToSort.keyPair.values_list);
    printf("\nAfter: \n");
    displayPair(dataToSort);

}

//Task10 : sort int
void task10Test(List *keyList)
{
    
    printf("\nBefore: \n");
    TraverseList(keyList,&displayKey);

    sortString(keyList);

    printf("\nAfter: \n");
    TraverseList(keyList,&displayKey);

}


