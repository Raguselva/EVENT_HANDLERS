typedef void(*visitCB)();
typedef void(*callCB)();
typedef void(*deliveryCB)();

typedef struct teamsAcc
{
    char emp_name[100],status[100],parcelDesc[100],guest_nameq[100][100],guest_purposeq[100][100];
    int emp_id,status_code,msg_count;
    int allow_call_stat,allow_del_stat,allow_visit_stat;
    visitCB VCB;
    callCB CCB;
    deliveryCB DCB;
    struct teamsAcc *next;
} Teams;

void add_teamsAcc(char *);
void list_all_teamAcc();
Teams * search_teamsAcc(char *);