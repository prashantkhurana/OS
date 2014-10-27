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





#include "types.h"
#include "user.h"
#include "pthread.h"
// #include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>



int ARRAYSIZE;


struct sort_this
{
int (*a);
int sort;
pthread_mutex_t (*mut);
};
typedef struct sort_this sort_this;
sort_this *array;
pthread_t *thread;
void check_sort()
{
	int i;
	int x=1;
	while(x)
	{
	  printf(1,"Current Array(mid way sorting)");
	for(i=0;i<ARRAYSIZE;i++)
	{
	  printf(1,"%d",array->a[i]);
	}
		  printf(1,"\n");
  	
	
	x=0;
	for(i=0;i<ARRAYSIZE-1;i++)
	{
		if(array->a[i]>array->a[i+1])
		{
			x=1;
			sleep (20);
		}
	}
}

  array->sort=0;
  x=10;
  while(x>0)
  {
    //printf(1,"djdjd");
    x--;
  }
  printf(1,"After sorting");
  for(i=0;i<ARRAYSIZE;i++)
	{
	  printf(1,"%d",array->a[i]);
	}

  exit();
//  return (void*)1;
}


void sort (void *x)
{
  
// 	pthread_mutex_lock(&array->mut[0]);
// 	  printf(1,"locked");
// 	int m=100000;
// 	
// 	while(m>0)
// 		{
// 		//  printf(1,"%d",m);
// 		  m--;
// 		}
// 	//printf(1,"\n");
// 	pthread_mutex_unlock (&array->mut[0]);
// 	printf(1,"unlocked");
// 	exit();
		
	int *y=(int*)x;
	int i=*y;
	//int j;
	while(array->sort)
	 {
			//printf(1,"currently running %d \n", i);

		pthread_mutex_lock(&array->mut[i]);
		pthread_mutex_lock (&array->mut[i+1]);
		if(array->a[i]>array->a[i+1])
		{
			int temp=array->a[i];
			array->a[i]=array->a[i+1];
			array->a[i+1]=temp;
		}
		pthread_mutex_unlock (&array->mut[i]);
		pthread_mutex_unlock (&array->mut[i+1]);
		
	}
  int c=10;
  while(c>0)
  {
   // printf(1,"x");
    c--;
  }
  exit();
}

 sort_this  *arrayInit (void)
 {
 	struct sort_this *array;
 	array=(struct sort_this *)malloc(sizeof(struct sort_this));
 	array->a=(int *)malloc(ARRAYSIZE*sizeof(int));
 	array->mut=(pthread_mutex_t *)malloc(ARRAYSIZE*sizeof(pthread_mutex_t));
	array->sort=1;
 	int i;
 	for(i=0;i<ARRAYSIZE;i++)
 	{
	  array->a[i]=ARRAYSIZE-i-1;
	}
	for(i=0;i<ARRAYSIZE;i++)
	{
		pthread_mutex_init (&array->mut[i], 0);
	}  
// 	for(i=0;i<ARRAYSIZE;i++)
// 	{
// 		printf(1,"%d ",array->mut[i].id);
// 		  //printf(1,"%d ",array->mut[i].);
// 	}
	return array;
}
int main ( int argc, char *argv[] )
{
//	int v;
	ARRAYSIZE=atoi(argv[1])+1;
	pthread_t dummy[ARRAYSIZE];
	//pthread_t dummy[2];
	thread=dummy;
 	int b[ARRAYSIZE];
	//ARRAYSIZE=2;
 	sort_this *array2;
 	array2=arrayInit();
 	array=array2;
 	int i;
	//uint x=100000000;
 	for(i=0;i<ARRAYSIZE-1;i++)
 	{
 		b[i]=i;
		pthread_create (&thread[i], 0,sort, &b[i]);
	//	while(x>0)
	//	{
	//	  x--;
	//	}
 	}
 	
	pthread_create (&thread[i], 0,check_sort, 0);
	//int x=10000;
	//while(x>0)
	 // x--;
	//usleep(10000);
	void *stack;
	for(i=0;i<ARRAYSIZE;i++)
 	{
 		pthread_join (thread[ARRAYSIZE-i], &stack);
 	}
//  	pthread_join (thread[ARRAYSIZE-0], 0);
// 	pthread_join (thread[ARRAYSIZE-1], 0);
// 	pthread_join (thread[ARRAYSIZE-2], 0);
// 	pthread_join (thread[ARRAYSIZE-3], 0);
// 	pthread_join (thread[ARRAYSIZE-4], 0);
// 	pthread_join (thread[ARRAYSIZE-5], 0);
	//pthread_join (thread[ARRAYSIZE-1], 0);
//	printf(1,"done waiting");
	exit();
}