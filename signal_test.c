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
  signal(0, periodic);
 // while(1)
  //{
  int x=10;
  int y=4;
  test_periodic();
  z=x+y;
 // }
  printf(1,"test complete");
//   for(i = 0; i < 50*500000; i++){
//     if((i++ % 500000) == 0)
//       write(2, ".", 1);
//   }
  exit();
}

void test_periodic()
{
  z=5;
  int g=0;
  g=3;
  printf(1,"%d",g);
  retsignal();
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