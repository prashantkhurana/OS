#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();
void test_periodic(int (*pfi)());

int x;
int
main(int argc, char *argv[])
{
  //int i;
  printf(1, "alarmtest starting, alarm of 1000 i.e. 10000 ms or 10 s\n");
  signal(2, (void (*)(void))test_periodic);
  signal(1,periodic);
  alarm(1000);
  x=1;
  while(x>0)
  {
  }
  printf(1,"test complete\n");
  exit();
}

void test_periodic(int (*pfi)())
{
    asm("push %%eax;push %%edx; push %%ecx;" :);
    pfi();
    asm(" movl 0x4(%%ebp), %%eax ;movl (%%ebp), %%ecx; movl %%eax, 0x8(%%ebp) ;movl %%ecx, 0x4(%%ebp);movl %%ebp, %%ecx; addl $0x4, %%ecx; movl %%ecx, %%ebp;    movl (%%esp), %%ecx; movl 0x4(%%esp),%%edx; movl 0x8(%%esp),%%eax; " :);
    return;
}

void 
periodic()
{
printf(1, "Alarm rings\n");
  x=0;
  return;
}
