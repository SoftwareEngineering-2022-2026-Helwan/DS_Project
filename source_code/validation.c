#include <ctype.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/global.h"

void ResetCounter()
{
    Data resetToken;
    resetToken.value = -1;

    displayKey(resetToken);
    displayValueToSelect(resetToken);
}

int validateChoice(int min, int max)
{
    int option;
    char *Soption = (char*) malloc(5);
    do
    {

        printf("\n\n[?] Choose: ");
        scanf("\n%s",Soption);
        getchar();
        if(isdigit(*Soption))
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
char wantContinue()
{
    char option;
    do
    {
        printf("[?] Choose: ");
        scanf("\n%c",&option);
        getchar();
    }while(tolower(option) != 'n' && tolower(option) != 'y');
    return option;
}

