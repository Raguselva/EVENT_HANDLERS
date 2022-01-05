#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "receptionist.h"   
#include "administrator.h"
#include "teams.h"

extern Teams *teamsHead;
extern Emp *empHead;
extern int emp_count;
extern int teams_count;

int search_employee(char *name)
{
    Emp *ptr;  
    int flag=0;  
    ptr = empHead;   
    if(ptr == NULL)  
    {  
        printf("\nEmployee database in empty\n");  
    }  
    else  
    {   
        while (ptr!=NULL)  
        {  
            if((strcmp(ptr->emp_name, name)) == 0)  
            {  
                //printf("Employee is present\n");
                flag=1;  
                return flag;
            }     
            ptr = ptr -> next;  
        }  
        if(flag==0)  
        {  
            //printf("Employee is not present\n"); 
            return flag;
        }  
    }
}

int check_status(char *name)
{
    Emp *ptr;  
    int flag=0;  
    ptr = empHead;   
    if(ptr == NULL)  
    {  
        printf("\nEmployee database in empty\n");  
    }  
    else  
    {   
        while (ptr!=NULL)  
        {  
            if((strcmp(ptr->emp_name, name)) == 0)  
            {  
                if(ptr->flag == 0) 
                {
                    return 0; // AVAILABLE
                }
                else
                {
                    return 1; // UNAVAILABLE
                }
            }     
            ptr = ptr -> next;  
        }  
    }
}

void inform_employee(char *emp_name,char *purpose,char *guest_name)
{
    printf("\nRECEPTIONIST : Hi %s, a person %s wants you for a %s\n",emp_name,guest_name,purpose);
    Teams *search_index;
    search_index = search_teamsAcc(emp_name);
    strcpy(search_index->guest_nameq[search_index->msg_count],guest_name);
    strcpy(search_index->guest_purposeq[search_index->msg_count],purpose);
    search_index->msg_count++;
}

int check_services(char *e_name,char *g_purpose)
{
    char purp[100];
    strcpy(purp,g_purpose);
    Teams *ptr;
    ptr = search_teamsAcc(e_name);
    if(strcmp(purp,"visit")== 0)
    {
        if(ptr->allow_visit_stat == 0)
        {
            return 1;
        }
    }
    else if(strcmp(purp,"call") == 0)
    {
        if(ptr->allow_call_stat == 0)
        {
            return 1;
        }
    }
    else if(strcmp(purp,"delivery") == 0)
    {
        if(ptr->allow_del_stat == 0)
        {
            return 1;
        }
    }  
    else
    {
        return 0;
    }
}

int enquire_receptionist(char *g_name,char *e_name,char *g_purpose)
{
    int avail,serv;
    avail = search_employee(e_name);
    if(avail == 1)
    {
        avail = check_status(e_name);
        Teams *search_index;
        search_index = search_teamsAcc(e_name);
        if(avail == 0)
        {
            serv = check_services(e_name,g_purpose);
            if(serv == 1)
            {
                if(search_index->status_code == 0)
                {
                    inform_employee(e_name,g_purpose,g_name);
                    return 1;
                }
                else
                {
                    printf("Sorry the employee is unavailable - %s",search_index->status);
                    return 0;
                }
            }
            else
            {
                printf("\nEmployee cannot process your service\n");
            }
        }
        else
        {
            printf("\nThe employee you have requested is on-leave / unavailable today\n.Please come again another day.\n");
            return 0;
        }
    }
    else
    {
        printf("\nThe employee you have requested is not a part of our firm\nThank You\n");
        return 0;
    }
}

