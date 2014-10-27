// #include "types.h"
// #include "mmu.h"
// #include "stat.h"
// #include "user.h"
// #include "param.h"
// #include "fs.h"
// #include "proc.h"
// #include "x86.h"
// #include "pthread.h"
// #

// When called by parent, waits for the child threads to complete execution
// by calling the wait() routine.
// int
// thread_join(void)
// {
//   return wait();
// }


// Allocates a new stack for the child thread and calls clone with the newly 
// allocated stack. The parent returns the pid of the child thread and the
// child calls the routine pointed to by the start_routine argument and passes
// it with the arg argument. Then the child frees the allocated stack and exits
// If allocproc fails, returns -1

// //#include "user.h"
//#include "pthread1.h"
#include "types.h"
//#include "mmu.h"
//#include "stat.h"
#include "user.h"
#include "pthread.h"
//#include "param.h"
//#include "fs.h"
//#include "proc.h"
//#include "x86.h"


int pthread_join(pthread_t thread, void **value_ptr)
{
 // printf(1,"in join");
return join(value_ptr);  
}


int pthread_create(pthread_t *thread, const void *attr,
                          void (*func)(void*), void *arg)
{
  void *stack = malloc(4096);  
  int rc = clone(stack);
  if (rc == 0)
  {
//    printf(1,"thread created befores :");
   (*func)(arg);
//   printf(1,"thread created after:");
   return 1;
    //free(stack);
    //exit();
  }
  else
    return rc;
}

int pthread_mutex_init(pthread_mutex_t *mutex,const void *attr)
{
  int x=mutex_init();
  mutex->id=x;
  return x;
}

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
  return  mutex_lock(mutex->id);
  //return 0;
}
int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
  //if(mutex_tlock(mutex->id)==0)
   // return 0;
  //else
    return  mutex_unlock(mutex->id);
  //return 0;
}

int pthread_mutex_destory(pthread_mutex_t *mutex)
{
  return  mutex_destroy(mutex->id);
  //return 0;
}


void pthread_mutex_yield()
{
  sleep(5);
}


int pthread_mutex_exit()
{
  return exit();
}


// Initializes a spinlock
// void
// lock_init(lock_t * lock){
//   xchg(&lock->flag, 0);
// }

// Acquires a spinlock which returns if no one already has the lock and spins
// if the lock is already acquired.
// void
// lock_acquire(lock_t * lock)
// {
//   while(xchg(&lock->flag, 1) == 1)
//     ;//spinny spin spins
// }
// 
// // Releases a spinlock
// void
// lock_release(lock_t * lock)
// {
//   xchg(&lock->flag, 0);
// }
