#include <stdio.h>
#include <string.h>
#include "administrator.h"
#include "teams.h"

Emp emp[100];
int emp_count = 0;
Emp *empHead;

void add_emp(char *name,int flag)
{
    Emp *ptr,*temp;  
    int item;     
    ptr = (Emp *)malloc(sizeof(Emp));        
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        strcpy(ptr->emp_name, name);  
        ptr->flag = flag;
        ptr->next = empHead;  
        empHead = ptr;  
        printf("\nEmployee added to the database");  
    } 
    add_teamsAcc(name);
    emp_count++;
}   

void list_all_emp()
{
    Emp *ptr;  
    ptr = empHead;   
    if(ptr == NULL)  
    {  
        printf("\nNo Employees in the database\n");  
    }  
    else  
    {  
        printf("\nPrinting the list of all employees\n");   
        while (ptr!=NULL)  
        {  
            printf("Employee name : %s\t\t", ptr->emp_name);
            printf("Employee status : %d\n", ptr->flag);  
            ptr = ptr -> next;  
        }  
    }  
}

void search_emp(char *name)
{
    Emp *ptr;  
    int flag=1;  
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
                printf("Employee is present\n");
                flag=0;  
            }     
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("Employee is not present\n"); 
        }  
    }     
}


