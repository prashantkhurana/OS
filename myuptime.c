#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "asm.h"


int myuptime(void);
int myuptime1(void);


int (**ptr2)();

char* (**ptr3)();

char *x;
int (**ptr6)();

int
main(int argc, char *argv[])
{
	int (*ptr)()=myuptime1;
	ptr2=&ptr;
	ptr6=&ptr;
	
	findkalloc(ptr3);
	printf(1,"%d\n",uptime());
	
	sysreplace(14,ptr,ptr2);
	uptime();
	int (*ptr4)()=(int(*)(void))(x+sizeof(*ptr2));
	sysreplace(14,ptr4,ptr6);
	printf(1,"%d\n",uptime());
	exit();
}


int myuptime(void)
{

	uint esp;
	asm ("mov %%eax, %0" : "=g" (esp));
	int (**ptr)()=(int(**)())(esp-4);
	return (**ptr)()+50000;
}

int myuptime1(void)
{
	x =(char *)  (**ptr3)();
	memmove(x,ptr2,sizeof(*ptr2));
	memmove(x+sizeof(*ptr2),&myuptime,&myuptime1-&myuptime);
	return 1;
}
