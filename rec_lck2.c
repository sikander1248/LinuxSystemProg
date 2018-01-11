#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc,char *argv[])
{
	int fd = open(argv[1] , O_RDWR | O_APPEND | O_CREAT , 0666);
	int ch;
	printf("1. Lock First Record 2. Lock Second Record ");
	scanf(" %d",&ch);
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	if(ch == 1)
		lock.l_start = 0;
	else
		lock.l_start = 11;
	lock.l_len = 10;
	lock.l_pid = getpid();

	if(fcntl(fd , F_SETLKW , &lock) == -1)
	{
		printf("Unable to set lock \n");
		return 1;
	}
	
	printf("p2 Acquired Lock  \n");	
	close(fd);
	printf("P2 COMPLETED \n");
	return 0;
}

