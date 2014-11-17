#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "asm.h"

void periodic();
void wrapper(int (*pfi)());
void * addr;

int
main(int argc, char *argv[])
{
printf(1, "test mpro starting\n");  
signal(2, (void (*)(void))wrapper);
signal(0,periodic); 

addr=malloc(4096);
int len = 4096;
mpro(addr, len,PROT_READ);
*((int *)addr)=10;
*((int *)addr)=20;
printf(1,"addr after modification is %d    len is: %d",*((int *)addr),len);
exit();
}



void wrapper(int (*pfi)())
{
    asm("push %%eax;push %%edx; push %%ecx;" :);
    pfi();
    asm(" movl 0x4(%%ebp), %%eax ;movl (%%ebp), %%ecx; addl $0x2, %%eax;  movl %%eax, 0x8(%%ebp) ;movl %%ecx, 0x4(%%ebp);movl %%ebp, %%ecx; addl $0x4, %%ecx; movl %%ecx, %%ebp;    movl (%%esp), %%ecx; movl 0x4(%%esp),%%edx; movl 0x8(%%esp),%%eax; " :);
    return;
}

void 
periodic()
{
  //y=&z;
printf(1, "Faulty Memory Access: In Sigsev Test Handler\n");
mpro(addr, 4096,PROT_WRITE);
//printf(1, "Setting value of *y to be 10 \n");
  return;
}