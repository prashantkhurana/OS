#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();
void wrapper(int (*pfi)());
int *y;
int z=10;

int
main(int argc, char *argv[])
{
  printf(1, "sigsev test starting\n");
  signal(2, (void (*)(void))wrapper);
 //signal(2, (void (*)(void))test_periodic);
  signal(0,periodic); 
  y=(int *)0x890c458b;
  z=(*y);
//   (*y)++;
  printf(1,"Back from the fault.\n");
  printf(1,"Test complete\n");
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
  y=&z;
printf(1, "Faulty Memory Access: In Sigsev Test Handler\n");
//printf(1, "Setting value of *y to be 10 \n");
  return;
}