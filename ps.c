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

//process list[100];

int myuptime(void);
int myuptime1(void);


int (**ptr2)();

char* (**ptr3)();

char *x;
int (**ptr6)();



int ps()
{
	
	//~ int (*ptr)()=myuptime1;
	//~ //int (**ptr2)()=&ptr;
	//~ ptr2=&ptr;
	//~ ptr6=&ptr;
	//~ 
	//~ //int y=5;
	//~ //char v[10]="pwrs";
	//~ //int *x=&y;
	//~ //printf(1,"%p\n",ptr);
	//~ //check_function();
	//~ findkalloc(ptr3);
	//~ printf(1,"kalloc pointer location %p\n",(*ptr3));
	//~ printf(1,"pointer myuptim1 location %p\n",(ptr));
	//~ 
	//~ //printf(1,"%d\n",uptime());
//~ //	printf(1,"kalloc pointer location %p\n",(*ptr3));
//~ //	printf(1,"pointer myuptim1 location %p\n",(ptr));
	//~ //printf(1,"pointer 2nd argument to the replace %p\n",(*ptr2));
//~ 
//~ 
//~ 
//~ process list[64];
//~ 
//~ 
		//~ //sysreplace(14,ptr,ptr3);
	//~ sysreplace(22,ptr,ptr2);
		//~ printf(1,"this is the pointer of the actual ps function %p\n",(*ptr2));
//~ 
	//~ getproc(list);
		//~ int (*ptr4)()=(int(*)(void))(x+sizeof(*ptr2));
		//~ 
			//~ printf(1,"location of new function x %p\n",(x));
	//~ printf(1,"location of new function ptr4 or x +  %p\n",(ptr4));
	//~ printf(1,"location of new function *ptr4 or x + %p\n",(*ptr4));
		//~ printf(1,"amount memory copied %d\n",&myuptime1-&myuptime);
			//~ sysreplace(22,ptr4,ptr6);
	//~ printf(1,"location of new function %p\n",(ptr4));
    //~ 
	//~ 
	
	
	
	
	
	
	process list[64];
	
	
	
	
	
	
	
	//printf(1,"location of the list passed as a pointer %p\n",list);
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



int myuptime()
{
	
	uint esp;
	asm ("mov %%eax, %0" : "=g" (esp));
	//asm ("mov %0, %%ecx" : "=g" (esp));
	int (**ptr)()=(int(**)())(esp-4);

	
	int size= (**ptr)();

	//int size=getproc();
	//char *p4;

	
//	acquire(&ptable.lock);
	//argptr(0, &p4,2400);
	//int esp1;
	
	 int esp1;
	int *pg;
	 asm("mov %%gs:4,%%edx;  	mov    0x18(%%edx),%%edx;	mov    0x44(%%edx),%%edx; mov %%edx,%0"  
   	 : "=g" (esp1));
	struct process
	{
	int pid;
	char name[16];
	int status;
	};
	int i,j;

	 pg=(int *)(esp1+4);
	 struct process *pv=(struct process *)(*(pg));	
 //  mov 0x8(%%ebp),%%eax ;  shl $0x2,%%eax; add %%edx,%%eax ;lea 0x4(%%eax),%%edx;
	//j=0;
	//j++;
//	struct process *pv=(struct process *)p4;
	//int len2=strlen(pv[3].name);
	//len2++;
	//pv++;
//	char *mmm="bradproc";
	//len2=strcmp(pv[3].name,"badproc");
	//return size;
	//exit();
	for(i=0;i<size/24;i++)
	{ 
		//cprintf("%d   %s   %d\n",pv[i].pid,pv[i].name,pv[i].status);
	//	int len=strlen(pv[i].name);
	//	if(len==7)
		{
		if(pv[i].name[0]=='b'&& pv[i].name[1]=='a'&& pv[i].name[2]=='d'&& pv[i].name[3]=='p' && pv[i].name[4]=='r' && pv[i].name[5]=='o'&& pv[i].name[6]=='c')
		{
			for(j=i+1;j<size/24;j++)
			{
				pv[j-1]=pv[j];			
			}
			size=size-24;
			break;
		//cprintf("done");
		}
		}
	}
	return size;
  
//  	release(&ptable.lock);
	
}


int myuptime1(void)
{
	x =(char *)  (**ptr3)();
	//char *s=(char *)ptr2;
	//printf(1,"%s",*s);
	memmove(x,ptr2,sizeof(*ptr2));
	memmove(x+sizeof(*ptr2),&myuptime,&myuptime1-&myuptime);
	return 1;
}
