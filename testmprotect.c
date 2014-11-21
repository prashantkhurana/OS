#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "asm.h"

void periodic(struct error x);
void wrapper(int (*pfi)(), struct error x);
int * addr;



int
main(int argc, char *argv[])
{
printf(1, "test mpro starting\n");  
signal(2, (void (*)(void))wrapper);
signal(0,(void (*)(void))periodic); 



addr=(int *)malloc(4096);
int len = 4096;
printf(1,"the base address of the page is %x\n",addr);

  
  
int i;

printf(1,"Writing to the page(1st 10 addresses)\n");
mpro(addr, len,PROT_READ);
for(i=0;i<10;i++)
{
  *((int *)(addr+i))=i;
}

printf(1,"The values of 1st 10 addresses written in the page\n");
for(i=0;i<10;i++)
{
  printf(1,"%d\n",*((int *)(addr+i)));
}

exit();
}



void wrapper(int (*pfi)(), struct error x)
{
    asm("push %%eax;push %%edx; push %%ecx;" :);
    pfi(x);
    asm(" movl 0x4(%%ebp), %%eax ;movl (%%ebp), %%ecx; addl $0x2, %%eax;  movl %%eax, 0x8(%%ebp) ;movl %%ecx, 0x4(%%ebp);movl %%ebp, %%ecx; addl $0x4, %%ecx; movl %%ecx, %%ebp;    movl (%%esp), %%ecx; movl 0x4(%%esp),%%edx; movl 0x8(%%esp),%%eax; " :);
    return;
}

void 
periodic(struct error x)
{
printf(1, "Faulty Memory Access: In Sigsev Test Handler\n");
printf(1, "The trap number and address are %d %x\n ", x.trap_no,x.addr);
mpro(x.addr, 4096,PROT_WRITE);
//printf(1, "Setting value of *y to be 10 \n");
printf(1, "Marked the page as write\n");
  return;
}