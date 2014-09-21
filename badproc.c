#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char str[100];

void reverse(char s[], int l)
 {
     int i, j;
     char c;
 
     for (i = 0, j = l-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }



char* itoa(int num)
{
    int i = 0;
    	
    while (num != 0)
    {
        int rem = num % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/10;
    }
 
    str[i] = '\0';
 
    reverse(str, i);
 
    return str;
}


int main()
{

	int pid,fd ;
        pid = fork();
        if (pid < 0)
	{
		exit();
	}
        if (pid > 0)
	{
		exit();
        }
	int buf=52;
	fd = open("badproc.out", O_CREATE|O_RDWR );
	while (1)
	{
		buf=uptime();
		write(fd, itoa(buf), sizeof buf);
		close(fd);
		fd = open("badproc.out", O_RDWR );
		sleep(2);
        }
       exit();
}
