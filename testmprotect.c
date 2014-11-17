#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "asm.h"

int
main(int argc, char *argv[])
{
void * addr;
addr=malloc(4096);
int len = 4096;
printf(1,"%d",mpro(addr, len,PROT_READ));
*((int *)addr)=10;
printf(1,"%d",uptime());
exit();
}