#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


struct process
{
	int pid;
	char name[16];
	int status;
};

char   state[][10]= { "UNUSED", "EMBRYO", "SLEEPING", "RUNNABLE", "RUNNING", "ZOMBIE" };


typedef struct process process;

process list[100];



int ps()
{
	int size=getproc(list);
	int i;
	for(i=0;i<size/24;i++)
	{
		printf(1,"%d   %s   %s\n",list[i].pid,list[i].name,state[list[i].status]);
	}
	
	return 1;
}


int main(int argc, char *argv[])
{

    ps() ;
    exit();
}

