#include <stdio.h>
#include <string.h>
#include "teams.h"

#define ALLOW 0
#define BLOCK 1

Teams teams[100];
int teams_count = 0;
Teams *teamsHead;

void add_teamsAcc(char *name)
{

    Teams *ptr;  
    int item;  
    ptr = (Teams *) malloc(sizeof(Teams));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        strcpy(ptr->emp_name, name);  
        ptr->emp_id = teams_count;
        strcpy(ptr->status,"available");
        ptr->status_code = 0;
        ptr->msg_count = 0;
        strcpy(ptr->parcelDesc,"reception");
        ptr->allow_call_stat=ALLOW;
        ptr->allow_del_stat=ALLOW;
        ptr->allow_visit_stat=ALLOW;
        teams_count++;
        ptr->next = teamsHead;  
        teamsHead = ptr;  
        printf("\nTeams account added successfully\n");  
        register_with_receptionist(ptr);
    }  
}

void list_all_teamAcc()
{
    Teams *ptr;  
    ptr = teamsHead;   
    if(ptr == NULL)  
    {  
        printf("\nNo Teams accounts in the database\n");  
    }  
    else  
    {  
        printf("\nPrinting the list of all teams accounts\n");   
        while (ptr!=NULL)  
        {  
            printf("Employee name : %s\t\t", ptr->emp_name);
            printf("Employee status : %d\n", ptr->emp_id);  
            ptr = ptr -> next;  
        }  
    }  
}

Teams *search_teamsAcc(char *name)
{
    Teams *ptr;  
    ptr = teamsHead;   
    if(ptr == NULL)  
    {  
        printf("\nTeams database in empty\n");  
    }  
    else  
    {   
        while (ptr!=NULL)  
        {  
            if((strcmp(ptr->emp_name, name)) == 0)  
            {  
                //printf("Returning structure pointer ---->  Employee is present\n");
                return ptr; 
            }     
            ptr = ptr -> next;  
        }  
    }
}

