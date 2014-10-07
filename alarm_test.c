#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();
void test_periodic();

int x;
int
main(int argc, char *argv[])
{
  //int i;
  printf(1, "alarmtest starting, alarm of 1000 i.e. 10000 ms or 10 s\n");
  signal(1, test_periodic);
  alarm(1000);
  x=1;
  while(x>0)
  {
  }
  printf(1,"test complete");
  exit();
}

void test_periodic()
{
    asm("push %%eax;push %%ebx; push %%ecx" :);
    periodic();
    asm("movl (%%esp), %%ecx; movl 0x4(%%esp),%%ebx; movl 0x4(%%esp),%%eax" :);
  return;
}

void 
periodic()
{
printf(1, "Alarm rings\n");
  x=0;
  return;
}