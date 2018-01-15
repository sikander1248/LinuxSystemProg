#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Program to Understand fork return value \n");

	if( fork() == 0 )
	{
		printf("CP - PID  = %u \n" , getpid() );
		printf("CP - PPID = %u \n" , getppid() );
	}
	else
	{
		printf("PP - PID  = %u \n" , getpid() );
		printf("PP - PPID = %u \n" , getppid() );
		getchar();
	}
	return 0;
}

