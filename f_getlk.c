//F_GETLK

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define SIZE	20
int main(int argc,char *argv[])
{
	int fd = open(argv[1], O_WRONLY | O_APPEND);
	
	printf("Process Id = %d \n" , getpid());
	struct flock lock;

	lock.l_type = F_RDLCK;		//Compulsory
	lock.l_whence = SEEK_SET;	//Compulsory
	lock.l_start = 0;	//Optional
	lock.l_len = 0;		//Optional
	lock.l_pid = getpid();	//Optional

	int lockRet = fcntl(fd , F_GETLK , &lock);
	if(lockRet == -1)
		perror("Lock Error ");
	else
	{
		if(lock.l_pid == getpid())
			printf("No Read Lock has been set to file \n");
		else
			printf("Read Lock set by process id  %d \n" , lock.l_pid);
	}

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lockRet = fcntl(fd , F_GETLK , &lock);
	if(lockRet == -1)
		perror("Lock Error ");
	else
	{
		if(lock.l_pid == getpid())
			printf("No Write Lock has been set to file \n");
		else
			printf("Write Lock set by process id  %d \n" , lock.l_pid);
	}
	return 0;
}









