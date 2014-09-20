#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
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
		write(fd, &buf, sizeof buf);
		close(fd);
		fd = open("badproc.out", O_RDWR );
		sleep(2);
        }
       exit();
}
