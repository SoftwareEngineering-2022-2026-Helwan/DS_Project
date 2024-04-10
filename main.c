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
#include "source_code/debug.c"


int main(int argc, String argv[])
{
    List keyList;
    CreateList(&keyList);

    // |----( Debug And Test method )----|
    if(argc == 3 && !strcmp(argv[1],"-d"))
    {
        debug( atoi(argv[2]), &keyList ); 
        return 1;  
    }

    // |----( Main Project )----|
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




