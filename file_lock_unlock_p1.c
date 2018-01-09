#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE	20
int main(int argc,char *argv[])
{
	int fd1 = open(argv[1], O_WRONLY | O_APPEND);
	
	struct flock lock = {
				.l_type = F_WRLCK,
				.l_whence = SEEK_SET,
				.l_start = 0,
				.l_len = 0,
				.l_pid = getpid()
			    };
	
	int lockRet = fcntl(fd1 , F_SETLK , &lock);
	
	printf("Lock Return value = %d \n" , lockRet);
	if(lockRet == -1)
		printf("Unable to acquire Lock \n");
	else
	{
		printf("Lock Acquired \n");
		for(int i = 0 ; i < 26 ; i++)
		{
			char c = 'a' + i;
			write(fd1 , &c , 1);
			sleep(1);
		}
		//To Unlock
		lock.l_type = F_UNLCK;
		fcntl(fd1 , F_SETLK , &lock);

		printf("Data written... Lock Released\n");		
		sleep(10);
		printf("Program Completed \n");	
	}
	return 0;
}
