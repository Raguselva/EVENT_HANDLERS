#include <stdio.h>
#include <string.h>
#include "user.h"
#include "employee.h"

void admin()
{
    int ch,cntu=1;
    printf("Welcome HR\n\n");
    printf("You can,\n");
    printf("\t1. Add an employee\n");
    printf("\t2. List all employees\n");
    printf("\t3. Search an employee\n");
    while(cntu)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("\nChoose you operation\n\nYour Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1  :   printf("\nAdding an employee\n");
                        add_emp("ragu",0);
                        add_emp("varsha",0);
                        add_emp("naveen",1);
                        break;
            case 2  :   printf("\nListing all employees\n");
                        list_all_emp();
                        break;
            case 3  :   printf("\nSearching an employee\n\n");
                        search_emp("nitishs");
                        break;
            default :   printf("\nEnter a valid choice\n");
                        break;
        }
        printf("\nDo you wish to navigate to ADMIN MENU?\n\n\t0. No\n\t1. Yes\n\n\tYour Choice:");
        scanf("%d",&cntu);
    }
}

void employee()
{
    int ch,cntu=1,status_code;
    char name[100],status_desc[100];
    printf("\nWelcome EMPLOYEE\n\n");
    printf("You can,\n");
    printf("\t1. Update your status\n");
    printf("\t2. Update for parcel info\n");
    printf("\t3. Clear Status\n");
    while(cntu)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("\nChoose your operation\n\nYour Choice :\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1  :   printf("\nSTATUS UPDATE\n");
                        printf("\n\tSTATUS CODES\t\tDESCRIPTION\n\n");
                        printf("\t0\t\t\tavailable\n\t1\t\t\tIn a meeting\n\t2\t\t\tIn a call\n\t3\t\t\tappear away\n\t4\t\t\twill be right back\n\t5\t\t\tout of office\n");
                        printf("\n\tEnter your name :\t");
                        scanf("%s",name);
                        printf("\n\tEnter status code :\t");
                        scanf("%d",&status_code);
                        printf("\n\tEnter status description :\t");
                        scanf("%s",status_desc);
                        update_status(name,status_code,status_desc);
                        break;
            case 2  :   printf("\nPARCEL INFO\n");
                        printf("\n\tEnter your name :\t");
                        scanf("%s",name);
                        printf("\n\tEnter where to keep the parcel :\t");
                        scanf("%s",status_desc);
                        update_parcelInfo(name,status_desc);
                        break;
            case 3  :   printf("\nCLEAR STATUSn\n");
                        printf("\n\tEnter your name :\t");
                        scanf("%s",name);
                        reply(name);
                        break;
            case 4  :   printf("\nSET SERVICES STATUS\n");
                        printf("\n\tEnter your name :\t");
                        scanf("%s",name);
                        set_service_status(name);
            default :   printf("\nEnter a valid choice\n");
                        break;
        }
        printf("\nDo you wish to navigate to EMPLOYEE MENU?\n\n\t0. No\n\t1. Yes\n\n\tYour Choice:");
        scanf("%d",&cntu);
    }
}

void guest()
{
    char g_name[100],e_name[100],g_purpose[100];
    int emp_status;

    //Guest Approaching
    printf("\nEnter Guest name :\t");
    scanf("%s",g_name);
    printf("\nEnter employee to be visitied by the guest :\t");
    scanf("%s",e_name);
    printf("\nEnter Purpose of vist :\t");
    scanf("%s",g_purpose);

    //Receptionist checking for employee details and informing the employee
    emp_status = enquire_receptionist(g_name,e_name,g_purpose);
    
    //employee replying for receptionist
    if(emp_status == 1)
    {
        //printf("ENTERING REPLY");
        reply(e_name);
    }
}