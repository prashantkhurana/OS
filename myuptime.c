#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"



int myuptime(void);


int (**ptr2)();


int
main(int argc, char *argv[])
{
	int (*ptr)()=myuptime;
	//int (**ptr2)()=&ptr;
	ptr2=&ptr;
	//int y=5;
	//char v[10]="pwrs";
	//int *x=&y;
	//printf(1,"%p\n",ptr);
	//check_function();
	printf(1,"%d\n",uptime());
	//printf(1,"pointer before update %p\n",(ptr2));
	//printf(1,"pointer bfr update %p\n",(*ptr2));
	sysreplace(14,ptr,ptr2);
	//printf(1,"pointer after update %p\n",(ptr2));
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
	//printf(1,"time after update %d\n",(**ptr2)());
	return (**ptr2)()+50000;
}
