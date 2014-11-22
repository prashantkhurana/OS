#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "asm.h"

int
main(int argc, char *argv[])
{
  int num=500;
  int pid;
  int i;
  void *addr=malloc(24576*2*2*2);
  *(int *)addr=0;
  int start,end,avg_fork,avg_cowfork;
  printf(1,"Starting Fork\n ");
  start=uptime();
  for(i=0;i<num;i++)
  {
    pid=fork();
    if(pid==0)
      exit();
    else if(pid<0)
      printf(1,"%d\n",pid);
    else
    {
      wait();
    }
  }
//  printf(1,"Starting Fork:%d \n ",uptime());
   end=uptime();
   avg_fork=(end-start)/num;
   //printf(1,"End Fork\n: %d ",end-start);
// 
  printf(1,"Avg Time for fork: %d\n",avg_fork);
 printf(1,"Starting Cow Fork\n");

 start=uptime();
  for(i=0;i<num;i++)
  {
    pid=cowfork();
    if(pid==0)
      exit();
    else if(pid<0)
      printf(1,"%d\n",pid);
    else
    {
      wait();
     //   printf(1,"%d ",i);  
    }
  }
  //printf(1,"Starting Cow Fork%d\n ",uptime());
  end=uptime();
  avg_cowfork=(end-start)/num;
//   printf(1,"End cowFork\n: %d ",end-start);
// 
  printf(1,"Avg Time for Cowfork:%d\n",avg_cowfork);
  exit();
}

