#include <stdio.h>
#include "user.h"

void main() {
    int choice,rep=1;
    printf("\n------------------\n");
    printf("WELCOME TO IT-HUB\n");
    printf("------------------\n");
    printf("\nChoose your login preference:\n\n");
    printf("\t1. Admin / HR\n");
    printf("\t2. Employee\n");
    printf("\t3. Guest\n");
    while(rep)
    {
        printf("\nEnter your role as number :\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  :   printf("\nLogged in successfully as HR\n\n");
                        printf("\n------------------------------------------------------------------\n\n");
                        admin();
                        break;
            case 2  :   printf("\nLogged in successfully as EMPLOYEE\n");
                        employee();
                        printf("\n------------------------------------------------------------------\n\n");
                        break;
            case 3  :   printf("\nWelcome GUEST\n");
                        guest();
                        printf("\n------------------------------------------------------------------\n\n");
                        break;
            default :   printf("Enter a valid choice\n");
                        printf("\n------------------------------------------------------------------\n\n");
                        break;
        }
        printf("\nDo you wish to navigate to MAIN MENU?\n\n\t0. No\n\t1. Yes\n\n\tYour Choice:");
        scanf("%d",&rep);
    }
}