#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//Program - p1.c
int main(int argc,char *argv[])
{
	int fd = open(argv[1] , O_WRONLY | O_APPEND | O_CREAT , 0666);

	struct flock  lock ;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	lock.l_pid = getpid();
	
	if( fcntl(fd , F_SETLKW , &lock) == -1)
	{
		printf("Unable to set lock on p1 \n");
		exit(1);
	}
	printf("Acquired lock - p1 \n");
	for(int i = 0 ; i < 10 ; i++)
	{
		write(fd , "A" , 1);
		sleep(1);
	}
}



