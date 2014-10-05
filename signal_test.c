#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();

int
main(int argc, char *argv[])
{
  //int i;
  printf(1, "alarmtest starting\n");
  signal(0, periodic);
  int x=10;
  int y=0;
  int z=x/y;
  z++;
  printf(1,"test complete");
//   for(i = 0; i < 50*500000; i++){
//     if((i++ % 500000) == 0)
//       write(2, ".", 1);
//   }
  exit();
}

void
periodic()
{
  printf(1, "Divideby0\n");
}