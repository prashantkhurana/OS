// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "fs.h"
// #include "param.h"
// 
// // lock_t *lock;
// // int counter;
// // 
// // // Increments a counter by one in a for-loop argument a number of times
// // void *
// // counter_inc(void * a)
// // { 
// //   int i;   
// //   for(i = 0; i < (int)a; i++) 
// //   { 
// //     lock_acquire(lock);
// //     counter++;  
// //     lock_release(lock);
// //   }
// //   return NULL;
// // }
// // 
// // void
// // usage()
// // {
// //   printf(1,"Usage: threadtest numThreads loopCount [outerLoopCount]\n");
// //   exit();
// // }
// 
// 
// int
// main(int argc, char *argv[])
// {
// //   if(argc != 3 && argc != 4) usage();
// //   int numThreads = atoi(argv[1]);
// //   int loopCount = atoi(argv[2]);
// // 
// //   // optional testing parameter for looping the entire process
// //   int outerLoopCount = 1;
// //   if(argc == 4) outerLoopCount = atoi(argv[3]);
// //   
// //   if (numThreads > NPROC - 3)
// //   {
// //     printf(2, "Error: Max number of threads is 61(NPROC - kernel, shell, this process)\n");
// //     exit();
// //   }
// //   counter = 0;
// //   lock = malloc(sizeof(lock_t));
// //   lock_init(lock);
// //   
// //   int j;
// //   for (j = 0; j < outerLoopCount; j++)
// //   {
// //     int i;
// //     for (i = 0; i < numThreads; i++)
// //       if (thread_create(counter_inc,(void *)loopCount) == -1)
// //       {
// //         printf(2, "Error: thread_create failure");
// //         exit();
// //       }
// // 
// //     for(; i > 0; i--)
// //       thread_join(); 
// //   }
// //   
// //   // make sure result is correct
// //   if(counter != numThreads * loopCount * outerLoopCount)
// //   {
// //     printf(1,"Error: counter != numThreads * loopCount [* outerLoopCount(optional)]\n");
// //     exit();
// //   }
// //   
// //   printf(1,"Counter: %d\n", counter);
// //   exit();
//   
//   
//   
// }






#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int ARRAYSIZE;


// struct sort_this
// {
// int (*a);
// pthread_mutex_t (*mut);
// };
// typedef struct sort_this sort_this;
// sort_this *array;
pthread_t *thread;
void *check_sort()
{
// 	int i;
// 	int x=1;
// 	while(x)
// 	{
// 		
// 	for(i=0;i<ARRAYSIZE;i++)
// 	{
// 	  printf("%d",array->a[i]);
// 	}
// 		  printf("\n");
// 		  x=0;
// 	for(i=0;i<ARRAYSIZE;i++)
// 	{
// 		if(array->a[i]>array->a[i+1])
// 		{
// 			x=1;
// 			usleep (2000000);
// 		}
// 	}
// }
// 	
// 	for(i=0;i<ARRAYSIZE;i++)
// 	{
// 	  pthread_cancel(thread[i]);
// 	}
  while(1)
  {printf("y");
  }
}


void *sort (void *x)
{
// 	int *y=(int*)x;
// 	int i=*y;
// 	int j;
// 	while(1)
// 	 {
// 		pthread_mutex_lock(&array->mut[i]);
// 		pthread_mutex_lock (&array->mut[i+1]);
// 		if(array->a[i]>array->a[i+1])
// 		{
// 			int temp=array->a[i];
// 			array->a[i]=array->a[i+1];
// 			array->a[i+1]=temp;
// 		}
// 		pthread_mutex_unlock (&array->mut[i]);
// 		pthread_mutex_unlock (&array->mut[i+1]);
// 		
// 	}
  while(1)
  {
    printf("x");
  }
}

// sort_this  *arrayInit (void)
// {
// 	struct sort_this *array;
// 	array=(struct sort_this *)malloc(sizeof(struct sort_this));
// 	array->a=(int *)malloc(ARRAYSIZE*sizeof(int));
// 	array->mut=(pthread_mutex_t *)malloc(ARRAYSIZE*sizeof(pthread_mutex_t));
// 	int i;
// 	for(i=0;i<ARRAYSIZE;i++)
// 	{
// 	  array->a[i]=ARRAYSIZE-i-1;
// 	}
// 	for(i=0;i<ARRAYSIZE;i++)
// 	{
// 		pthread_mutex_init (&array->mut[i], NULL);
// 	}  
// 	return array;
// }
int main ( int argc, char *argv[] )
{
//	int v;
	ARRAYSIZE=atoi(argv[1])+1;
	pthread_t dummy[ARRAYSIZE];
	thread=dummy;
 	int b[ARRAYSIZE];
 	//sort_this *array2;
 	//array2=arrayInit();
 	//array=array2;
 	int i;
	for(i=0;i<ARRAYSIZE-1;i++)
	{
		b[i]=i;
	  pthread_create (&thread[i], NULL,sort, &b[i]);
	}
	pthread_create (&thread[i], NULL,check_sort, NULL);
	//pthread_join (thread[ARRAYSIZE-1], NULL);
	return 0;
}