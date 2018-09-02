#include <stdio.h>

#include <sys/types.h>	//open
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>	//read, write

int main()
{
	int fd1 = open("f1.txt",O_RDONLY);	
	printf("fd1 = %d \n",fd1);
	
	int fd2 = open("f2.txt",O_RDONLY);
	printf("fd2 = %d \n",fd2);
}
