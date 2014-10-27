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
sys_clone(void) {
void *stack;
//int *p;
//int size;
if ( argptr(0,(char **) &stack,4096) < 0)
return -1;
return clone(stack);
}



int
sys_join(void) {
void *stack;
//int *p;
//int size;
if ( argptr(0,(char **) &stack,10) < 0)
return -1;
return wait2(stack);
}


int sys_mutex_init(void)
{
  return mutex_init();
}
int sys_mutex_trylock(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  return mutex_trylock(n);
}
int sys_mutex_lock(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  return mutex_lock(n);
}

int sys_mutex_unlock(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  return mutex_unlock(n);
}
int sys_mutex_destroy(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  return mutex_destroy(n);
}
