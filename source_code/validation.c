#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/global.h"
#include "../headers/displayMenu.h"

void ResetCounter()
{
    Data resetToken;
    resetToken.value = -1;

    displayKey(resetToken);
    displayValueToSelect(resetToken);
}

int validateChoice(int min, int max)
{
    int option, valid;
    char *Soption = (char*) malloc(5);
    do
    {
        valid = 1;
        printf("\n\n[?] Choose: ");
        scanf("\n%s",Soption);
        getchar();
        for (int i = 0; Soption[i] != '\0'; ++i) 
        {
            if (!isdigit(Soption[i])) 
            {
                valid = 0;
                break;
            }
            
        }
        if(valid)
        {
            option = atoi(Soption);
        }
        else
        {
            option = -1;
        }
        if(option  > max || option < min)
        {
            printf("\n\n[!] Invalid Option!  \n");
        }
    }while(option < min || option > max);
    return option;
}
char wantContinue(String question)
{
    char *Soption = (char*) malloc(3);
    char option ;
    do
    {
        option = ' ';
        printf("%s",question);
        printf("[?] Choose: ");
        scanf("\n%s",Soption);
        getchar();
        for (int i = 0; Soption[i] != '\0'; ++i) 
        {
            if (tolower(Soption[i]) != 'n' && tolower(Soption[i]) != 'y') 
            {
                option = 'a';
                break;
            }
            
        }

        if(option != 'a')
        {
            option = Soption[0];
        }

    }while(tolower(option) != 'n' && tolower(option) != 'y');
    return option;
}

