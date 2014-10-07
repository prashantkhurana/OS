#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();
void test_sigsegv();
int *y;
int z=10;

int
main(int argc, char *argv[])
{
  printf(1, "sigsev test starting\n");
  signal(0, test_sigsegv);
   y=(int *)0x890c458b;
  (*y)++;
  (*y)++;
  printf(1,"Back from the fault. The new value of the *y after adding 1 is %d\n",*y);
  printf(1,"Test complete");
  exit();
}

void test_sigsegv()
{
   asm("push %%eax;push %%ecx; push %%edx" :);
   periodic();
   asm("movl (%%esp), %%edx; movl 0x4(%%esp),%%ecx; movl 0x4(%%esp),%%eax" :);
  return;
}

void 
periodic()
{
  y=&z;
printf(1, "Faulty Memory Access: In Sigsev Test Handler\n");
printf(1, "Setting value of *y to be 10 \n");
  return;
}