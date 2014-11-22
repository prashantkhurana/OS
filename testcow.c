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
  printf(1,"Starting Fork %d\n ",uptime());
  //start=uptime();
  int ans=0;
  for(i=0;i<num;i++)
  {
    start=uptime();
    pid=fork();
    if(pid==0)
      exit();
     else
    {
      end=uptime();
      wait();
      ans+=(end-start);
    }
    
  }
//  printf(1,"Starting Fork:%d \n ",uptime());
   //end=uptime();
   avg_fork=ans/num;
   //printf(1,"End Fork\n: %d ",end-start);
// 
   printf(1,"End Fork %d\n ",uptime());
  printf(1,"Avg Time for fork: %d\n",avg_fork);
 printf(1,"Starting Cow Fork %d \n",uptime());
  ans=0;
 //start=uptime();
  for(i=0;i<num;i++)
  {
    start=uptime();
    pid=cowfork();
    if(pid==0)
      exit();
    else
    {
      end=uptime(); 
      wait();
      ans+=(end-start);
     //   printf(1,"%d ",i);  
    }
  }
  //printf(1,"Starting Cow Fork%d\n ",uptime());
  //end=uptime();
  avg_cowfork=ans/num;
//   printf(1,"End cowFork\n: %d ",end-start);
// 
  printf(1,"End CowFork %d\n ",uptime());
  printf(1,"Avg Time for Cowfork:%d\n",avg_cowfork);
  exit();
}

