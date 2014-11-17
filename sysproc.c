#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}


int
sys_signal(void){
  
int signum;
int handlerInt;
//sighandler_t handler;
if (argint(0, &signum) < 0)
return -1;
if (argint(1, &handlerInt) <0)
return -1;
return signal(signum, (sighandler_t) handlerInt);
}


int
    sys_alarm(void)
    {
      int ticks;
//      void (*handler)();

      if(argint(0, &ticks) < 0)
        return -1;
//       if(argptr(1, (char**)&handler, 1) < 0)
//         return -1;
      proc->alarm_time = ticks;
      proc->time_elapsed=0;
//       proc->alarmhandler = handler;
      return 0;
    }
    
int
    sys_retsignal(void)
    {
     return retsignal();
    }

    
int
sys_mpro(void)
{
  void * addr;
  int len;
  int x;
  int prot;
  if(argint(0, &x)<0)
    return -1;
  addr = (void*) x;
  if(argint(1, &len)<0)
    return -1;
  if(argint(2, &prot)<0)
    return -1;
  cprintf("Len and prot are:");
  return mprotect(addr,len,prot);
  return 1;
}


