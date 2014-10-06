#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();
void test_periodic();

int z;
int
main(int argc, char *argv[])
{
  //int i;
  printf(1, "alarmtest starting\n");
  signal(0, test_periodic);
 // while(1)
  //{
  int x=10;
  int y=0;
  z=x/y;
  //test_periodic();
  //z=x+y;
 // }
  printf(1,"test complete");
//   for(i = 0; i < 50*500000; i++){
//     if((i++ % 500000) == 0)
//       write(2, ".", 1);
//   }b
  exit();
}

void test_periodic()
{
    asm("push %%eax;push %%ebx; push %%ecx" :);
    periodic();

   //asm("movl 0x4(%%esp), %%ecx; movl 0x8(%%esp),%%ebx; movl 0xc(%%esp),%%eax" :);
   asm("movl (%%esp), %%ecx; movl 0x4(%%esp),%%ebx; movl 0x4(%%esp),%%eax" :);
//   z=5;
//   int g=0;
   //  printf(1,"in the test_periodic");
//   g=3;
//   printf(1,"%d",g);
//   retsignal();
  return;
}

void 
periodic()
{
printf(1, "Divideby0\n");
//   z=10;
  return;
 // return 1;
}