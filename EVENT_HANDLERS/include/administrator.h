typedef struct employee
{
    char emp_name[100];
    int flag;
    struct employee* next;
} Emp;

void add_emp(char *,int);
void list_all_emp();
void search_emp(char *);
