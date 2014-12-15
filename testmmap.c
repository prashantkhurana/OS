#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"


int main()
{
  int fd;
  char buf2[5];
  
  fd=open("input",  O_CREATE|O_RDWR);
  
  char buff[4]="xxxx";
  printf(1,"Writing to Disk\n");
  write(fd,buff,4);
  
  int i; 
  sleek(fd,0);
  read(fd,buf2,4);
  printf(1, "Initial String :%s\n",buf2);
  
  void *buf3=sbrk(4096+4096);
  buf3=(char *)(((uint)buf3+4096-1)& ~(4095));
  printf(1, "Memory Mapping\n");
  sleek(fd,0);
  mmap(buf3,4096,0,0,fd,0);
  sleek(fd,0);
  
  read(fd,buf2,4);
  printf(1, "After memory mapping :%s\n",buf2);
  
  printf(1, "Modyfying memory mapped using write\n");
  sleek(fd,0);
  for( i=0;i<4;i++)
  {
    buff[i]='y';
  }
  write(fd,buff,4);
  sleek(fd,0);
  
  read(fd,buf2,4);
  printf(1, "After memory mapping modified using write :%s\n",buf2);
  
  printf(1,"Modifying last 2 chars using memory modification\n");
  for( i=2;i<4;i++)
  {
    *(((char*)buf3)+i)='x';
  }
  sleek(fd,0);
  
  read(fd,buf2,4);
  printf(1, "After memory mapping modified using mem modification :%s\n",buf2);
  printf(1, "Closing File:\n");
  close(fd);
  exit();
}