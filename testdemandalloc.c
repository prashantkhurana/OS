#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "asm.h"

int
main(int argc, char *argv[])
{
  int num=10000;
void * addr;
int i;
printf(1,"%d\n ",uptime());  
for(i=0;i<num;i++)
{
//printf(1,"%d ",i);  
addr=dsbrk(4096);
*((int *)addr)=10;
}
printf(1,"%d\n ",uptime());  
printf(1,"dsbrk done");



printf(1,"%d\n ",uptime());  
for(i=0;i<num;i++)
{
//printf(1,"%d ",i);  
addr=sbrk(4096);
*((int *)addr)=10;
}
printf(1,"%d\n ",uptime());  
printf(1,"sbrk done");

//int len = 4096;
//printf(1,"%d",mpro(addr, len,PROT_READ));
// for(i=0;i<num;i++)
// {
// 
// *((int *)addr[i])=10;
// }
printf(1,"assignment done");
//printf(1,"%d",uptime());
exit();
}