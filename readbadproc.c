#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// might or might not be used

int main()
{

	int fd 	;
        int bug;
	fd = open("badproc.out", O_RDONLY);
        read(fd,&bug,4);
	printf(1,"%d\n",bug);
	close(fd);
	close(fd);
	exit();
}
