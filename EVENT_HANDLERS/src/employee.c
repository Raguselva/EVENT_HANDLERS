#include <stdio.h>
#include <string.h>
#include "teams.h"

extern Teams *teamsHead;
extern int teams_count;

/*
 // Employee can set the status to following number codes
 // 0 - available
 // 1 - In a meeting
 // 2 - In a call
 // 3 - appear away
 // 4 - will be right back
 // 5 - out of office
*/
void update_status(char *name,int status,char *status_desc)
{
    Teams *index;
    index = search_teamsAcc(name);
    strcpy(index->status,status_desc);
    index->status_code = status;
    printf("STATUS UPDATED\n");
}

/*
 // To update the parcel delivery details of employee
*/
void update_parcelInfo(char *name,char *desc)
{
    Teams *index;
    index = search_teamsAcc(name);
    strcpy(index->parcelDesc,desc);
    printf("PARCEL LOCATION UPDATED\n");
}

void set_service_status(char * name)
{
    Teams *index;
    int stat;
    index = search_teamsAcc(name);
    printf("\nDo you want to 0.ALLOW / 1.BLOCK calls?\n");
    scanf("%d",&stat);
    index->allow_call_stat = stat;
    printf("\nDo you want to 0.ALLOW / 1.BLOCK visitors?\n");
    scanf("%d",&stat);
    index->allow_visit_stat = stat;
    printf("\nDo you want to 0.ALLOW / 1.BLOCK delivery?\n");
    scanf("%d",&stat);
    index->allow_del_stat = stat;
}

void reply(char *name)
{
    Teams *index;
    index = search_teamsAcc(name);
    char purp[100];
    if(index->status_code == 0)
    {
        strcpy(purp,index->guest_purposeq[(index->msg_count)-1]);
        if(strcmp(purp,"visit")== 0)
        {
            strcpy(index->status,"In a meeting");
            index->status_code = 1;
            index->VCB();
        }
        else if(strcmp(purp,"call") == 0)
        {
            strcpy(index->status,"In a call");
            index->status_code = 2;
            index->CCB();
        }
        else if(strcmp(purp,"delivery") == 0)
        {
            index->DCB();
        }
        index->msg_count--;
    }
    else
    {
        printf("Sorry I'm currently unavailable - %s. Please wait.\n",index->status);
    }
 
}

void visitor1()
{
    printf("\nEMPLOYEE-1 : Please send the visitor to my cabin\n");
}

void delivery1()
{
    printf("\nEMPLOYEE-1 : Please leave the parcel\n");
}

void caller1()
{
    printf("\nEMPLOYEE-1 : Please connect me through the call\n");
}

void visitor2()
{
    printf("\nEMPLOYEE-2 : Please send the visitor to my cabin\n");
}

void delivery2()
{
    printf("\nEMPLOYEE-2 : Please leave the parcel\n");
}

void caller2()
{
    printf("\nEMPLOYEE-2 : Please connect me through the call\n");
}

void visitor3()
{
    printf("\nEMPLOYEE-3 : Please send the visitor to my cabin\n");
}

void delivery3()
{
    printf("\nEMPLOYEE-3 : Please leave the parcel\n");
}

void caller3()
{
    printf("\nEMPLOYEE-3 : Please connect me through the call\n");
}


void (*visit_actions[])() = {&visitor1,&visitor2,&visitor3};
void (*call_actions[])() = {&caller1,&caller2,&caller3};
void (*delivery_actions[])() = {&delivery1,&delivery2,&delivery3};

void register_with_receptionist(Teams *ptr)
{
    ptr->VCB = visit_actions[ptr->emp_id];
    ptr->CCB = call_actions[ptr->emp_id];
    ptr->DCB = delivery_actions[ptr->emp_id];
}