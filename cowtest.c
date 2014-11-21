#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "asm.h"

int
main(int argc, char *argv[])
{
//  int num=10000;
  int pid;
  int i;
  printf(1,"%d\n ",uptime());  
  for(i=0;i<1000;i++)
  {
    pid=fork();
    if(pid==0)
      exit();
    if(pid<0)
      printf(1,"1");
    
  }
 printf(1,"%d\n ",uptime());    
  for(i=0;i<1000;i++)
  {
    pid=fork();
    if(pid==0)
      exit();
    if(pid<0)
      printf(1,"2");
  }
 // exit();
 printf(1,"%d\n ",uptime());  
  exit();
}

