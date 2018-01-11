#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
	int fd = open(argv[1] , O_RDWR | O_CREAT , 0666);

	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 10;
	lock.l_pid = getpid();

	if(fcntl(fd , F_SETLKW , &lock) == -1)
	{
		printf("Unable to set lock \n");
		return 1;
	}
	printf("p1 - Acquired Lock \n");	
	printf("Press Enter to release the lock \n");
	getchar();

	close(fd);
	printf("P1 COMPLETED \n");
	return 0;
}

