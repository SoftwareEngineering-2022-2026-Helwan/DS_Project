#include <ctype.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

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
        option = atoi(Soption);
        if(option  > max || option < min)
        {
            printf("\n\n[!] Invalid Option!  \n");
        }
    }while(option < min || option > max);
}
char wantContinue()
{
    char option;
    do
    {
        printf("[?] Choose: ");
        scanf("\n%c",&option);
    }while(tolower(option) != 'n' && tolower(option) != 'y');
}

