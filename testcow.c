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
  printf(1,"Starting Time%d\n ",uptime());  
  for(i=0;i<1000;i++)
  {
    pid=fork();
    if(pid==0)
      exit();
    else if(pid<0)
      printf(1,"%d\n",pid);
    else
    {
      wait();
        printf(1,"%d ",i);  
    }
  }
  
  
 printf(1,"\nFinal Time %d\n ",uptime());    
  for(i=0;i<1000;i++)
  {
    pid=cowfork();
    if(pid==0)
      exit();
    else if(pid<0)
      printf(1,"%d\n",pid);
    else
    {
      wait();
        printf(1,"%d ",i);  
    }
  }
 // exit();
 printf(1,"\nFinal TIme %d\n ",uptime());
  exit();
}

