#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
        printf("     PID          PPID \n");
        if(fork() == 0)
        {
                printf("CP- %d        %d \n" , getpid() , getppid());
                sleep(5);
                printf("CP %d        %d \n" , getpid() , getppid());
                exit(0);
        }
        else
        {
                printf("PP- %d        %d \n" , getpid() , getppid());
                sleep(1);
                printf("Parent Completed \n");
                exit(0);
        }
}
