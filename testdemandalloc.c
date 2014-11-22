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



int dsbrk_alloc_time,dsbrk_write_time;
int before,after, after2;
printf(1,"dsbrk started\n");
for(i=0;i<num;i++)
{
//printf(1,"%d ",i);  
before=uptime();
addr=dsbrk(4096);
after=uptime();
dsbrk_alloc_time+=(after-before);

memset(addr,0,4096);
after2=uptime();
dsbrk_write_time+=(after2-after);

}

printf(1,"dsbrk done\n");

printf(1,"sbrk started\n");

int sbrk_alloc_time,sbrk_write_time;
for(i=0;i<num;i++)
{
//printf(1,"%d ",i);  
before=uptime();
addr=sbrk(4096);
after=uptime();
sbrk_alloc_time+=(after-before);
memset(addr,0,4096);
after2=uptime();
sbrk_write_time+=(after2-after);

}


printf(1,"sbrk done\n");

printf(1,"DSBRK ALLOC TIME:%d\nSBRK ALLOC TIME:%d\nDSBRK WRITE TIME:%d\nSBRK WRITE TIME:%d\n",dsbrk_alloc_time,sbrk_alloc_time,dsbrk_write_time,sbrk_write_time);
exit();
}