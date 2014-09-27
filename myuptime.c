//~ #include "types.h"
//~ #include "stat.h"
//~ #include "user.h"
//~ #include "fs.h"
//~ 
//~ 
//~ 
//~ int myuptime(void);
//~ 
//~ 
//~ int (**ptr2)();
//~ 
//~ 
//~ int
//~ main(int argc, char *argv[])
//~ {
	//~ int (*ptr)()=myuptime;
	//~ //int (**ptr2)()=&ptr;
	//~ ptr2=&ptr;
	//~ //int y=5;
	//~ //char v[10]="pwrs";
	//~ //int *x=&y;
	//~ //printf(1,"%p\n",ptr);
	//~ //check_function();
	//~ printf(1,"%d\n",uptime());
	//~ //printf(1,"pointer before update %p\n",(ptr2));
	//~ //printf(1,"pointer bfr update %p\n",(*ptr2));
	//~ sysreplace(14,ptr,ptr2);
	//~ //printf(1,"pointer after update %p\n",(ptr2));
	//~ //printf(1,"pointer after update %p\n",(*ptr2));
	//~ printf(1,"%d\n",uptime());
	//~ //printf(1,"time after update %d\n",(**ptr2)());
	//~ //printf(1,"%p\n",(ptr2));
	//~ //printf(1,"%p\n",ptr);
	//~ //printf(1,"%d\n",process_list());
 	//~ //exit();
	//~ //replace_table(22); 
	//~ //return 1;
	//~ exit();
//~ }
//~ 
//~ 
//~ int myuptime(void)
//~ {
	//~ //printf(1,"time after update %d\n",(**ptr2)());
	//~ return (**ptr2)()+50000;
//~ }


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
	//int (**ptr2)()=&ptr;
	ptr2=&ptr;
	ptr6=&ptr;
	
	//int y=5;
	//char v[10]="pwrs";
	//int *x=&y;
	//printf(1,"%p\n",ptr);
	//check_function();
	findkalloc(ptr3);
	printf(1,"%d\n",uptime());
	
	//printf(1,"%d\n",uptime());
//	printf(1,"kalloc pointer location %p\n",(*ptr3));
//	printf(1,"pointer myuptim1 location %p\n",(ptr));
	//printf(1,"pointer 2nd argument to the replace %p\n",(*ptr2));




		//sysreplace(14,ptr,ptr3);
	sysreplace(14,ptr,ptr2);
//	printf(1,"this is what will be copied from  %p\n",(*ptr2));
	uptime();
	int (*ptr4)()=(int(*)(void))(x+sizeof(*ptr2));
//	printf(1,"location of new function x %p\n",(x));
//	printf(1,"location of new function ptr4 %p\n",(ptr4));
//	printf(1,"location of new function *ptr4 %p\n",(*ptr4));
	//printf(1,"location of 2nd argument %p\n",(ptr6));
	int esp=454;
	//asm ("mov %%esp, %0" : "=g" (esp));
	int (*ptr10)()=(int(*)(void))(esp-4);
	ptr10++;
//	printf(1,"amount memory copied %d\n",&myuptime1-&myuptime);
	sysreplace(14,ptr4,ptr6);
//	printf(1,"location of new function %p\n",(ptr4));
	//printf(1,"pointer after update %p\n",(*ptr2));
	printf(1,"%d\n",uptime());
	//printf(1,"time after update %d\n",(**ptr2)());
	//printf(1,"%p\n",(ptr2));
	//printf(1,"%p\n",ptr);
	//printf(1,"%d\n",process_list());
 	//exit();
	//replace_table(22); 
	//return 1;
	exit();
}


int myuptime(void)
{

	uint esp;
	asm ("mov %%eax, %0" : "=g" (esp));
	//asm ("mov %0, %%ecx" : "=g" (esp));
	int (**ptr)()=(int(**)())(esp-4);

	
	return (**ptr)()+50000;
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
