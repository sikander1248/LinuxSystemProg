#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//Program - p2.c
int main(int argc,char *argv[])
{
	int fd = open(argv[1] , O_WRONLY | O_APPEND | O_CREAT , 0666);

	struct flock lock = {.l_type = F_WRLCK , 
			     .l_whence = SEEK_SET, 
			     .l_start = 0, 
			     .l_len = 0 , 
                             .l_pid = getpid()
			    };

	if( fcntl(fd , F_SETLKW , &lock) == -1)
	{
		printf("Unable to set lock on p2 \n");
		exit(0);
	}
	printf("Acquired lock in p2 \n");
	for(int i = 0 ; i < 10 ; i++)
	{
		write(fd , "B" , 1);
		sleep(1);
	}
}













